#include <stdio.h>
#include <stdlib.h>

// Düğüm yapısı
struct dugum {
    int anahtar;
};

// Heap yapısı
struct heap {
    struct dugum *dizi;    // Heap düğümlerini tutan dizi
    int kapasite;          // Heap'in toplam kapasitesi
    int eleman_sayisi;     // Şu anda bulunan eleman sayısı
};

// Heap oluşturma fonksiyonu
struct heap *heap_olustur(int kapasite) {
    struct heap *yeni_heap = (struct heap *)malloc(sizeof(struct heap));
    yeni_heap->kapasite = kapasite;
    yeni_heap->eleman_sayisi = 0;
    yeni_heap->dizi = (struct dugum *)malloc(kapasite * sizeof(struct dugum));
    return yeni_heap;
}

// Heap'e eleman ekleme fonksiyonu
void heap_insert(struct heap *heap, int key) {
    if (heap->eleman_sayisi >= heap->kapasite) {
        printf("Heap kapasitesi dolu, eleman eklenemiyor.\n");
        return;
    }

    int index = heap->eleman_sayisi;
    heap->eleman_sayisi++;
    heap->dizi[index].anahtar = key;

    // Bubble-up işlemi
    int parent_index = (index - 1) / 2;
    struct dugum temp_dugum;

    while (index > 0 && heap->dizi[parent_index].anahtar < heap->dizi[index].anahtar) {
        temp_dugum = heap->dizi[parent_index];
        heap->dizi[parent_index] = heap->dizi[index];
        heap->dizi[index] = temp_dugum;

        index = parent_index;
        parent_index = (index - 1) / 2;
    }
}


int minimum_anahtari_bul(struct heap *heap) {
    if (heap->eleman_sayisi == 0) {
        printf("Heap boş, minimum değer bulunamadı.\n");
        return -1;
    }

    int min = heap->dizi[heap->eleman_sayisi / 2].anahtar; // İlk yaprak düğümü al
    for (int i = (heap->eleman_sayisi / 2) + 1; i < heap->eleman_sayisi; i++) {
        if (heap->dizi[i].anahtar < min) {
            min = heap->dizi[i].anahtar;
        }
    }

    return min;
}

// Heap'i yazdırma fonksiyonu
void print_heap(struct heap *heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->eleman_sayisi; i++) {
        printf("%d ", heap->dizi[i].anahtar);
    }
    printf("\n");
}

// Ana program
int main() {
    struct heap *myHeap = heap_olustur(10);

    // Eleman ekleme
    heap_insert(myHeap, 50);
    heap_insert(myHeap, 30);
    heap_insert(myHeap, 20);
    heap_insert(myHeap, 15);
    heap_insert(myHeap, 10);
    heap_insert(myHeap, 15);
    heap_insert(myHeap, 2);

    // Heap'i yazdır
    print_heap(myHeap);

    // Minimum anahtarı bul
    int min_anahtar = minimum_anahtari_bul(myHeap);
    printf("En küçük anahtar: %d\n", min_anahtar);

    // Bellek temizliği
    free(myHeap->dizi);
    free(myHeap);

    return 0;
}

