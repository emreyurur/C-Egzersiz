#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash tablosu veri yapısı
struct cell {
    char *anahtar;
    struct cell *next;
};

struct table_node {
    int count;         // Hücredeki eleman sayısı
    struct cell *header; // Bağlı listenin başlangıcı
};

struct hash_tablosu {
    struct table_node *tablo_basi; // Hash tablosundaki hücreler
    int tablo_uzunlugu;           // Hash tablosunun boyutu
    int multiplier;               // Hash fonksiyonu için çarpan
};

// Hash fonksiyonu
unsigned int hash(char *s, int multiplier, int table_size) {
    unsigned int value = 0;
    while (*s) {
        value = (value * multiplier + *s) % table_size;
        s++;
    }
    return value;
}

//BURAYA BAK!!
void insert_hash_table_single(struct hash_tablosu *htable struct cell *dugum){
    int hash_index=hash(dugum->anahtar,htable->multiplier,htable->tablo_uzunlugu);
    struct sell **header=&((htable->tablo_basi+hash_index)->header);
    
    struct cell *current=*header;
     while(current!=NULL){
        if(strcmp(dugum->anahtar,current->anahtar)==0){
            printf("Anahtar zaten var: %s\n",dugum->anahtar);
            return;
        }
        current=current->next;
     }
     dugum->next=*header;
     *header=dugum;
     (htable->tablo_basi+hash_index)->count++;
}

struct hash_tablosu *create_hash_table(int table_size, int multiplier) {
    struct hash_tablosu *hash_table = (struct hash_tablosu *)malloc(sizeof(struct hash_tablosu));
    hash_table->tablo_uzunlugu = table_size;
    hash_table->multiplier = multiplier;
    hash_table->tablo_basi = (struct table_node *)malloc(table_size * sizeof(struct table_node));

    for (int i = 0; i < table_size; i++) {
        hash_table->tablo_basi[i].count = 0;
        hash_table->tablo_basi[i].header = NULL;
    }
    return hash_table;
}

// Hash tablosunu yazdırma
void print_hash_table(struct hash_tablosu *hash_table) {
    printf("----- HASH TABLOSU -----\n");
    for (int i = 0; i < hash_table->tablo_uzunlugu; i++) {
        printf("[%d]: ", i);
        struct cell *current = hash_table->tablo_basi[i].header;
        while (current != NULL) {
            printf("%s -> ", current->anahtar);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Ana program
int main() {
    // Hash tablosu oluştur
    struct hash_tablosu *hash_table = create_hash_table(10, 31);

    // Eleman ekle
    struct cell *apple = (struct cell *)malloc(sizeof(struct cell));
    apple->anahtar = "comuceng";
    apple->next = NULL;
    insert_hash_table_single(hash_table, apple);

    struct cell *banana = (struct cell *)malloc(sizeof(struct cell));
    banana->anahtar = "canakkale";
    banana->next = NULL;
    insert_hash_table_single(hash_table, banana);

    struct cell *cherry = (struct cell *)malloc(sizeof(struct cell));
    cherry->anahtar = "cherry";
    cherry->next = NULL;
    insert_hash_table_single(hash_table, cherry);

    struct cell *apple2 = (struct cell *)malloc(sizeof(struct cell));
    apple2->anahtar = "apple";
    apple2->next = NULL;
    insert_hash_table_single(hash_table, apple2); // Aynı anahtar tekrar eklenmeyecek

    // Hash tablosunu yazdır
    print_hash_table(hash_table);

    return 0;
}
