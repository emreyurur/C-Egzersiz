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

// MinHeap'te en büyük anahtarı bulma
int max_heap_minheap(struct heap *heap) {
    if (heap->eleman_sayisi == 0) {
        printf("Heap boş, maksimum değer bulunamadı.\n");
        return -1; // Heap boşsa hata değeri döndür
    }

    // Yaprak düğümleri kontrol ederek en büyük değeri bul
    int max = heap->dizi[(heap->eleman_sayisi / 2)].anahtar; // İlk yaprak düğüm
    for (int i = (heap->eleman_sayisi / 2) + 1; i < heap->eleman_sayisi; i++) {
        if (heap->dizi[i].anahtar > max) {
            max = heap->dizi[i].anahtar;
        }
    }
    return max;
}

int max_heap_minheap(struct heap *heap){
    if(heap->eleman_sayisi==0){
        printf("Heap boş. \n");
        return -1;
    }
    int max=heap->dizi[(heap->eleman_sayisi/2)].anahtar;
    for(int i=(heap->eleman_sayisi/2)+1;i<heap->eleman_sayisi;i++){
        if(heap->dizi[i].anahtar>max){
            max=heap->dizi[i].anahtar;
        }
    }
    return max;
}

int max_heap_minheap(struct heap *heap){
    if(heap->eleman_sayisi==0){
        printf("Heap boş. \n");
        return -1;
    }
    int max=heap->dizi[(heap->eleman_sayisi/2)].anahtar;
    for(int i=(heap->eleman_sayisi/2)+1;i<heap->eleman_sayisi;i++){
        if(heap->dizi[i].anatar>max){
        max=heap->dizi[i].anahtar;
        }
    }
    return max;
}



// Heap'e manuel eleman ekleme fonksiyonu (MinHeap mantığına göre düzenlenmiş olarak varsayıyoruz)
void heap_insert_manual(struct heap *heap, int key) {
    if (heap->eleman_sayisi < heap->kapasite) {
        heap->dizi[heap->eleman_sayisi].anahtar = key;
        heap->eleman_sayisi++;
    }
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

    // MinHeap'e elle eleman ekleme
    heap_insert_manual(myHeap, 5);
    heap_insert_manual(myHeap, 10);
    heap_insert_manual(myHeap, 15);
    heap_insert_manual(myHeap, 82);
    heap_insert_manual(myHeap, 25);

    // Heap'i yazdır
    print_heap(myHeap);

    // En büyük anahtarı bul
    int max_anahtar = max_heap_minheap(myHeap);
    printf("En büyük anahtar: %d\n", max_anahtar);

    // Bellek temizleme
    free(myHeap->dizi);
    free(myHeap);

    return 0;
}
