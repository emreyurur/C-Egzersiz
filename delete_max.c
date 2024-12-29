#include <stdio.h>
#include <stdlib.h>

struct dugum {
    int key;
};

struct heap {
    struct dugum *dizi;
    int eleman_sayisi;
    int kapasite;
};

struct heap* heap_olustur(int kapasite) {
    struct heap *yeni_heap = (struct heap*)malloc(sizeof(struct heap));
    yeni_heap->kapasite = kapasite;
    yeni_heap->eleman_sayisi = 0;
    yeni_heap->dizi = (struct dugum*)malloc(kapasite * sizeof(struct dugum));
    return yeni_heap;
}

void delete_max(struct heap *heap) {
    if (heap->eleman_sayisi <= 0) {
        printf("Heap bos, silinecek eleman yok.\n");
        return;
    }

    if (heap->eleman_sayisi == 1) {
        heap->eleman_sayisi--; // Sadece kökü sil
        return;
    }

    // Kök düğümü (en büyük eleman) ile son düğümü yer değiştir
    struct dugum temp = heap->dizi[0];
    heap->dizi[0] = heap->dizi[heap->eleman_sayisi - 1];
    heap->dizi[heap->eleman_sayisi - 1] = temp;

    // Eleman sayısını bir azalt
    heap->eleman_sayisi--;

    // Heap'i yeniden düzenlemek için aşağı doğru kaydırma işlemi (bubble_down)
    int index = 0;
    int sol = 2 * index + 1;
    int sag = 2 * index + 2;

    while (sol < heap->eleman_sayisi) {
        int larger_child_index = sol;

        // Sağ çocuk varsa ve sağ çocuk daha büyükse, larger_child_index'i güncelle
        if (sag < heap->eleman_sayisi && heap->dizi[sag].key > heap->dizi[sol].key) {
            larger_child_index = sag;
        }

        // Eğer ebeveyn (index) çocuğundan büyükse, döngüden çık
        if (heap->dizi[index].key >= heap->dizi[larger_child_index].key) {
            break;
        }

        // Ebeveyn ile daha büyük çocuk düğümü yer değiştir
        struct dugum temp_dugum = heap->dizi[index];
        heap->dizi[index] = heap->dizi[larger_child_index];
        heap->dizi[larger_child_index] = temp_dugum;

        // Yeni indeksi daha büyük çocuk yap
        index = larger_child_index;

        // Sol ve sağ çocukları tekrar hesapla
        sol = 2 * index + 1;
        sag = 2 * index + 2;
    }
}


int main() {
    struct heap *myHeap = heap_olustur(10);

    // Eleman ekleme
    myHeap->dizi[0].key = 50;
    myHeap->dizi[1].key = 30;
    myHeap->dizi[2].key = 20;
    myHeap->dizi[3].key = 10;
    myHeap->eleman_sayisi = 4;

    printf("Delete max islemi oncesi:\n");
    for (int i = 0; i < myHeap->eleman_sayisi; i++) {
        printf("%d ", myHeap->dizi[i].key);
    }
    printf("\n");

    // Max eleman sil
    delete_max(myHeap);

    printf("Delete max islemi sonrasi:\n");
    for (int i = 0; i < myHeap->eleman_sayisi; i++) {
        printf("%d ", myHeap->dizi[i].key);
    }
    printf("\n");

    free(myHeap->dizi);
    free(myHeap);
    return 0;
}
