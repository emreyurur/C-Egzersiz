#include <stdio.h>
#include <stdlib.h>

struct dugum {
    int veri;
    struct dugum* sonraki;
};

void ilk_ve_son_dugumleri_sil(struct dugum **liste_basi){
    if((*liste_basi) == NULL){
        printf("Listede eleman yok.\n");
        exit(1);
    }
    if((*liste_basi)->sonraki == NULL){
        printf("Listede tek eleman var siliniyor.\n");
        free(*liste_basi);
        *liste_basi = NULL;
        exit(1);
    }
    struct dugum* ikinci = NULL;
    ikinci = (*liste_basi)->sonraki;
    free(*liste_basi);
    *liste_basi = ikinci;

    struct dugum* onceki = NULL;
    while(ikinci->sonraki != NULL){
        onceki = ikinci;
        ikinci = ikinci->sonraki;
    }
    free(ikinci);
    if (onceki != NULL) {
        onceki->sonraki = NULL;
    }
}

int main() {
    // Test kodu: Bağlı liste oluşturma ve ilk ve son düğümleri silme
    struct dugum* liste_basi = (struct dugum*)malloc(sizeof(struct dugum));
    liste_basi->veri = 1;
    liste_basi->sonraki = (struct dugum*)malloc(sizeof(struct dugum));
    liste_basi->sonraki->veri = 2;
    liste_basi->sonraki->sonraki = (struct dugum*)malloc(sizeof(struct dugum));
    liste_basi->sonraki->sonraki->veri = 3;
    liste_basi->sonraki->sonraki->sonraki = NULL;

    ilk_ve_son_dugumleri_sil(&liste_basi);

    // Kalan listeyi yazdırma
    struct dugum* gecici = liste_basi;
    while (gecici != NULL) {
        printf("%d ", gecici->veri);
        gecici = gecici->sonraki;
    }
    printf("\n");

    // Belleği serbest bırakma
    while (liste_basi != NULL) {
        struct dugum* gecici = liste_basi;
        liste_basi = liste_basi->sonraki;
        free(gecici);
    }

    return 0;
}