#include <stdio.h>
#include <stdlib.h>

void ayir(int* liste_basi, int boyut, int** ciftListe, int* ciftSayisi, int** tekListe, int* tekSayisi) {
    *ciftSayisi = 0;
    *tekSayisi = 0;

    for (int i = 0; i < boyut; i++) {
        if (liste_basi[i] % 2 == 0) (*ciftSayisi)++;
        else (*tekSayisi)++;
    }

    // Çift ve tek sayı listelerini ayırma
    *ciftListe = (int*)malloc((*ciftSayisi) * sizeof(int));
    *tekListe = (int*)malloc((*tekSayisi) * sizeof(int));

    int c = 0, t = 0;
    for (int i = 0; i < boyut; i++) {
        if (liste_basi[i] % 2 == 0) (*ciftListe)[c++] = liste_basi[i];
        else (*tekListe)[t++] = liste_basi[i];
    }
}

int main() {
    int liste_basi[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int boyut = sizeof(liste_basi) / sizeof(liste_basi[0]);
    int *ciftListe, *tekListe;
    int ciftSayisi, tekSayisi;

    ayir(liste_basi, boyut, &ciftListe, &ciftSayisi, &tekListe, &tekSayisi);

    printf("Çift Sayılar: ");
    for (int i = 0; i < ciftSayisi; i++) printf("%d ", ciftListe[i]);
    printf("\nTek Sayılar: ");
    for (int i = 0; i < tekSayisi; i++) printf("%d ", tekListe[i]);

    // Belleği serbest bırakma
    free(ciftListe);
    free(tekListe);
    return 0;
}
