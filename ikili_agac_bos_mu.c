#include <stdio.h>
#include <stdlib.h>

struct agac_dugum {
    int anahtar;
    struct agac_dugum* sol;
    struct agac_dugum* sag;
};

struct agac_dugum* dugum_olustur(int anahtar){
    struct agac_dugum *d = (struct agac_dugum*)malloc(sizeof(struct agac_dugum));
    if(d == NULL){
        printf("Heapte gerekli yer ayrilamadi... \n");
        exit(1);
    }
    d->anahtar = anahtar;
    d->sol = d->sag = NULL;
    return d;
}

int ikili_agac_bos_mu(struct agac_dugum *kok){
    if(kok == NULL){
        return 1;
    } else {
        return 0;
    }
}

int main() {
    struct agac_dugum* kok = NULL;

    if (ikili_agac_bos_mu(kok)) {
        printf("Agac bos.\n");
    } else {
        printf("Agac bos degil.\n");
    }

    kok = dugum_olustur(10);

    if (ikili_agac_bos_mu(kok)) {
        printf("Agac bos.\n");
    } else {
        printf("Agac bos degil.\n");
    }

    return 0;
}