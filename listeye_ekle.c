#include <stdio.h>
#include <stdlib.h>

// İkili arama ağacı düğüm yapısı
struct bt_dugum {
    int key;
    int derinlik;
    struct bt_dugum *sol, *sag;
};

// Bağlı liste düğüm yapısı
struct ls_dugum {
    struct bt_dugum *dugum;
    struct ls_dugum *sonraki;
};

// Bir bağlı listeye yeni düğüm ekleyen fonksiyon
void listeye_ekle(struct ls_dugum **liste_basi, struct bt_dugum *eklenecek_dugum) {
    struct ls_dugum *yeni_dugum = (struct ls_dugum*)malloc(sizeof(struct ls_dugum));
    yeni_dugum->dugum = eklenecek_dugum;
    yeni_dugum->sonraki = *liste_basi;
    *liste_basi = yeni_dugum;
}

// En uzun yolun derinliğini bulma fonksiyonu
int max_derinlik(struct bt_dugum *kok) {
    if (kok == NULL) return 0;
    int sol_derinlik = max_derinlik(kok->sol);
    int sag_derinlik = max_derinlik(kok->sag);
    return 1 + (sol_derinlik > sag_derinlik ? sol_derinlik : sag_derinlik);
}

// En uzun yoldaki düğümleri bağlı listeye ekleyen fonksiyon
void en_uzun_yolu_listeye_ekle(struct bt_dugum *kok, struct ls_dugum **liste_basi, int hedef_derinlik) {
    if (kok == NULL) return;
    if (hedef_derinlik == 1) {
        listeye_ekle(liste_basi, kok);
    } else {
        en_uzun_yolu_listeye_ekle(kok->sol, liste_basi, hedef_derinlik - 1);
        en_uzun_yolu_listeye_ekle(kok->sag, liste_basi, hedef_derinlik - 1);
    }
}

// Liste oluşturma fonksiyonu
void liste_olustur(struct bt_dugum *kok, struct ls_dugum **liste_basi) {
    int derinlik = max_derinlik(kok);
    en_uzun_yolu_listeye_ekle(kok, liste_basi, derinlik);
}

// Test kodu
int main() {
    // Örnek ikili arama ağacı oluşturulması
    struct bt_dugum *kok = (struct bt_dugum*)malloc(sizeof(struct bt_dugum));
    kok->key = 1;
    kok->sol = (struct bt_dugum*)malloc(sizeof(struct bt_dugum));
    kok->sol->key = 2;
    kok->sol->sol = kok->sol->sag = NULL;
    kok->sag = (struct bt_dugum*)malloc(sizeof(struct bt_dugum));
    kok->sag->key = 3;
    kok->sag->sol = (struct bt_dugum*)malloc(sizeof(struct bt_dugum));
    kok->sag->sol->key = 4;
    kok->sag->sol->sol = kok->sag->sol->sag = NULL;
    kok->sag->sag = NULL;

    struct ls_dugum *liste_basi = NULL;
    liste_olustur(kok, &liste_basi);

    // Bağlı listedeki düğümleri yazdırma
    printf("En uzun yoldaki düğümler: ");
    struct ls_dugum *gecici = liste_basi;
    while (gecici != NULL) {
        printf("%d ", gecici->dugum->key);
        gecici = gecici->sonraki;
    }
    printf("\n");

    // Bellek temizleme (bellek yönetimini ihmal etmeyin)
    while (liste_basi != NULL) {
        struct ls_dugum *gecici = liste_basi;
        liste_basi = liste_basi->sonraki;
        free(gecici);
    }

    // Ağacın bellek temizlemesi eklenmeli
    free(kok->sol);
    free(kok->sag->sol);
    free(kok->sag);
    free(kok);

    return 0;
}
