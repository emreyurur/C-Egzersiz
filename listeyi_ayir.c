#include <stdio.h>
#include <stdlib.h>

struct dugum {
    int veri;
    struct dugum* sonraki;
};

void listeyi_ayir(struct dugum **liste_basi,struct dugum **ciftListe, struct dugum **tekListe){
    if(*liste_basi==NULL){
        printf("Ayırmak için liste yok.\n");
        *ciftListe=NULL;
        *tekListe=NULL;
        return;
    }
    struct dugum *kopya = *liste_basi;
    *liste_basi = NULL;
    *ciftListe = NULL;
    *tekListe = NULL;

    struct dugum *ciftKopya = NULL;
    struct dugum *tekKopya = NULL;
    struct dugum *a = NULL;

    while (kopya != NULL) {
        a = kopya;
        kopya = kopya->sonraki;
        a->sonraki = NULL;

        if (a->veri % 2 == 0) {
            ciftKopya = *ciftListe;
            a->sonraki = ciftKopya;
            *ciftListe = a;
        } else {
            tekKopya = *tekListe;
            a->sonraki = tekKopya;
            *tekListe = a;
        }
    }
}


void listeyi_yazdir(struct dugum *liste) {
    struct dugum *gecici = liste;
    while (gecici != NULL) {
        printf("%d ", gecici->veri);
        gecici = gecici->sonraki;
    }
    printf("\n");
}

int main() {
    // Test kodu: Bağlı liste oluşturma
    struct dugum* liste_basi = (struct dugum*)malloc(sizeof(struct dugum));
    liste_basi->veri = 1;
    liste_basi->sonraki = (struct dugum*)malloc(sizeof(struct dugum));
    liste_basi->sonraki->veri = 2;
    liste_basi->sonraki->sonraki = (struct dugum*)malloc(sizeof(struct dugum));
    liste_basi->sonraki->sonraki->veri = 3;
    liste_basi->sonraki->sonraki->sonraki = (struct dugum*)malloc(sizeof(struct dugum));
    liste_basi->sonraki->sonraki->sonraki->veri = 4;
    liste_basi->sonraki->sonraki->sonraki->sonraki = NULL;

    struct dugum *ciftListe = NULL;
    struct dugum *tekListe = NULL;

    listeyi_ayir(&liste_basi, &ciftListe, &tekListe);

    printf("Çift Sayılar: ");
    listeyi_yazdir(ciftListe);
    printf("Tek Sayılar: ");
    listeyi_yazdir(tekListe);

    // Belleği serbest bırakma
    while (ciftListe != NULL) {
        struct dugum* gecici = ciftListe;
        ciftListe = ciftListe->sonraki;
        free(gecici);
    }

    while (tekListe != NULL) {
        struct dugum* gecici = tekListe;
        tekListe = tekListe->sonraki;
        free(gecici);
    }

    return 0;
}
