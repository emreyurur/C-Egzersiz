#include <stdio.h>
#include <stdlib.h>

// Dugum yapisi
struct dugum {
    int anahtar;
    struct dugum *sol_link, *sag_link;
};

// Yuksekligi hesaplayan yardimci fonksiyon
int yukseklik(struct dugum *kok){
    if(kok==NULL)
    return 0;
    int solYukseklik=yukseklik(kok->sol_link);
    int sagYukseklik=yukseklik(kok->sag_link);
    return (solYukseklik>sagYukseklik ? solYukseklik:sagYukseklik)+1;
}

// Dengeli olup olmadigini kontrol eden fonksiyon
int dengeli_mi(struct dugum *kok){
    if(kok==NULL)
    return 1;
    int solYukseklik=yukseklik(kok->sol_link);
    int sagYukseklik=yukseklik(kok->sag_link);
    if(abs(solYukseklik-sagYukseklik)>1){
        return 0;
    }
    return dengeli_mi(kok->sol_link) && dengeli_mi(kok->sag_link);
}

int main() {
    // Test agaci olusturma
    struct dugum* kok = (struct dugum*)malloc(sizeof(struct dugum));
    kok->anahtar = 1;
    kok->sol_link = (struct dugum*)malloc(sizeof(struct dugum));
    kok->sag_link = (struct dugum*)malloc(sizeof(struct dugum));

    kok->sol_link->anahtar = 2;
    kok->sol_link->sol_link = NULL;
    kok->sol_link->sag_link = NULL;

    kok->sag_link->anahtar = 3;
    kok->sag_link->sol_link = (struct dugum*)malloc(sizeof(struct dugum));
    kok->sag_link->sag_link = NULL;

    kok->sag_link->sol_link->anahtar = 4;
    kok->sag_link->sol_link->sol_link = (struct dugum*)malloc(sizeof(struct dugum));
    kok->sag_link->sol_link->sag_link = NULL;

    kok->sag_link->sol_link->sol_link->anahtar = 5;
    kok->sag_link->sol_link->sol_link->sol_link = NULL;
    kok->sag_link->sol_link->sol_link->sag_link = NULL;

    // Agacin dengeli olup olmadigini kontrol etme
    if (dengeli_mi(kok))
        printf("Agac dengeli.\n");
    else
        printf("Agac dengesiz.\n");

    // Bellegi temizleme
    free(kok->sag_link->sol_link->sol_link);
    free(kok->sag_link->sol_link);
    free(kok->sol_link);
    free(kok->sag_link);
    free(kok);

    return 0;
}
