#include <stdio.h>
#include <stdlib.h>

// Define the structure for a heap node
struct heap_node {
    int anahtar;
};

// Define the structure for the heap
struct heap {
    struct heap_node *dizi;
    int eleman_sayisi;
};

// Function to find the minimum key in a MaxHeap
int minimum_anahtari_bul(struct heap *heap) {
    // Heap boş ise hata döndür
    if (heap->eleman_sayisi == 0) {
        return -1;  // veya hata kodu
    }
    
    // MaxHeap'te en küçük eleman yapraklarda olacaktır
    int min_anahtar = heap->dizi[(heap->eleman_sayisi)/2].anahtar;  // ilk yaprağın anahtarı
    
    // Tüm yaprak düğümleri kontrol et
    for (int i = (heap->eleman_sayisi/2); i < heap->eleman_sayisi; i++) {
        if (heap->dizi[i].anahtar < min_anahtar) {
            min_anahtar = heap->dizi[i].anahtar;
        }
    }
    
    return min_anahtar;
}

int main() {
    // Create a sample heap
    struct heap myHeap;
    myHeap.eleman_sayisi = 7;
    myHeap.dizi = (struct heap_node *)malloc(myHeap.eleman_sayisi * sizeof(struct heap_node));
    
    // Initialize the heap with some values
    myHeap.dizi[0].anahtar = 50;
    myHeap.dizi[1].anahtar = 30;
    myHeap.dizi[2].anahtar = 20;
    myHeap.dizi[3].anahtar = 10;
    myHeap.dizi[4].anahtar = 5;
    myHeap.dizi[5].anahtar = 15;
    myHeap.dizi[6].anahtar = 25;
    
    // Find the minimum key in the heap
    int min_anahtar = minimum_anahtari_bul(&myHeap);
    
    // Print the result
    if (min_anahtar != -1) {
        printf("En küçük anahtar: %d\n", min_anahtar);
    } else {
        printf("Heap boş.\n");
    }
    
    // Free the allocated memory
    free(myHeap.dizi);
    
    return 0;
}