#include <stdio.h>
#include <stdlib.h>

// Düğüm yapısı
struct dugum {
    int key;
};

// Heap yapısı
struct heap {
    struct dugum *dizi;
    int kapasite;
    int eleman_sayisi;
};

// Fonksiyonlar
struct heap *heap_olustur(int kapasite) {
    struct heap *yeni_heap = (struct heap *)malloc(sizeof(struct heap));
    yeni_heap->kapasite = kapasite;
    yeni_heap->eleman_sayisi = 0;
    yeni_heap->dizi = (struct dugum *)malloc(kapasite * sizeof(struct dugum));
    return yeni_heap;
}

void heap_insert(struct heap *heap, int key) {
   if(heap->eleman_sayisi >= heap->kapasite){
    printf("Heap kapasitesi dolu. \n");
    return;
   }
   int index = heap->eleman_sayisi;
   heap->eleman_sayisi++;
   heap->dizi[index].key = key;

   int parent_index = (index - 1) / 2;
   struct dugum temp_dugum;

   while(index > 0 && heap->dizi[parent_index].key < heap->dizi[index].key){
        temp_dugum = heap->dizi[parent_index];
        heap->dizi[parent_index] = heap->dizi[index];
        heap->dizi[index] = temp_dugum;

        index = parent_index;
        parent_index = (index - 1) / 2;
   }
}

void print_heap(struct heap *heap) {
    for(int i = 0; i < heap->eleman_sayisi; i++) {
        printf("%d ", heap->dizi[i].key);
    }
    printf("\n");
}

int main() {
    struct heap *myHeap = heap_olustur(10);

    heap_insert(myHeap, 20);
    heap_insert(myHeap, 1500);
    heap_insert(myHeap, 30);
    heap_insert(myHeap, 10);
    heap_insert(myHeap, 400);

    print_heap(myHeap);

    free(myHeap->dizi);
    free(myHeap);

    return 0;
}
