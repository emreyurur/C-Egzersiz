#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bağlı liste düğüm yapısı
struct cell {
    char *anahtar;
    struct cell *next;
};

// Hash tablosu hücre yapısı
struct table_node {
    int count;
    struct cell *header;
};

// Hash tablosu yapısı
struct hash_tablosu {
    struct table_node *tablo_basi;
    int tablo_uzunlugu;
    int multiplier;
};

// Fonksiyon prototipleri
unsigned int hash(char *s, int multiplier, int table_size);
void delete_from_hash_table(struct hash_tablosu *htable, char *anahtar);
struct hash_tablosu *create_hash_table(int table_size, int multiplier);
void insert_hash_table_single(struct hash_tablosu *htable, struct cell *dugum);
void print_hash_table(struct hash_tablosu *htable);
void free_hash_table(struct hash_tablosu *htable);

// Hash fonksiyonu
unsigned int hash(char *s, int multiplier, int table_size) {
    unsigned int value = 0;
    while (*s) {
        value = (value * multiplier + *s) % table_size;
        s++;
    }
    return value;
}

// Eleman ekleme fonksiyonu
void insert_hash_table_single(struct hash_tablosu *htable, struct cell *dugum) {
    int hash_index = hash(dugum->anahtar, htable->multiplier, htable->tablo_uzunlugu);
    struct cell **header = &(htable->tablo_basi[hash_index].header);

    struct cell *current = *header;
    while (current != NULL) {
        if (strcmp(current->anahtar, dugum->anahtar) == 0) {
            printf("Anahtar zaten var: %s\n", dugum->anahtar);
            return;
        }
        current = current->next;
    }
    dugum->next = *header;
    *header = dugum;

    htable->tablo_basi[hash_index].count++;
    printf("Anahtar eklendi: %s\n", dugum->anahtar);
}

// Hash tablosunu yazdırma fonksiyonu
void print_hash_table(struct hash_tablosu *htable) {
    printf("----- HASH TABLOSU -----\n");
    for (int i = 0; i < htable->tablo_uzunlugu; i++) {
        printf("[%d]: ", i);
        struct cell *current = htable->tablo_basi[i].header;
        while (current != NULL) {
            printf("%s -> ", current->anahtar);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Hash tablosu oluşturma fonksiyonu
struct hash_tablosu *create_hash_table(int table_size, int multiplier) {
    struct hash_tablosu *htable = (struct hash_tablosu *)malloc(sizeof(struct hash_tablosu));
    htable->tablo_uzunlugu = table_size;
    htable->multiplier = multiplier;
    htable->tablo_basi = (struct table_node *)malloc(table_size * sizeof(struct table_node));

    for (int i = 0; i < table_size; i++) {
        htable->tablo_basi[i].count = 0;
        htable->tablo_basi[i].header = NULL;
    }
    return htable;
}

//BURAYA BAK!!
void delete_from_hash_table(struct hash_tablosu *htable, char *anahtar) {
    int hash_index=hash(anahtar,htable->multiplier,htable->tablo_uzunlugu);
    struct cell **header=&((htable->tablo_basi+hash_index)->header);

    struct cell *current=*header;
    struct cell *prev=NULL;
    
    while(current!=NULL){
        if(strcmp(current->anahtar,anahtar)==0){
            if(prev=NULL){
                *header=current->next;
            }
            else{;
                prev->next=current->next
            }
            free(current->anahtar);
            free(current);

            (htable->tablo_basi+hash_index)->count--;
            printf ("Anahtar silindi: %s\n",anahtar);
            return;
        }
        prev=current;
        current=current->next;
    }
    

    printf("Anahtar bulunamadı: %s\n", anahtar);
}

// Hash tablosunu serbest bırakma fonksiyonu
void free_hash_table(struct hash_tablosu *htable) {
    for (int i = 0; i < htable->tablo_uzunlugu; i++) {
        struct cell *current = htable->tablo_basi[i].header;
        while (current != NULL) {
            struct cell *temp = current;
            current = current->next;
            free(temp->anahtar);
            free(temp);
        }
    }
    free(htable->tablo_basi);
    free(htable);
}

// Ana program
int main() {
    struct hash_tablosu *hash_table = create_hash_table(10, 31);

    struct cell *apple = (struct cell *)malloc(sizeof(struct cell));
    apple->anahtar = strdup("emreee");
    apple->next = NULL;
    insert_hash_table_single(hash_table, apple);

    struct cell *banana = (struct cell *)malloc(sizeof(struct cell));
    banana->anahtar = strdup("banana");
    banana->next = NULL;
    insert_hash_table_single(hash_table, banana);

    struct cell *cherry = (struct cell *)malloc(sizeof(struct cell));
    cherry->anahtar = strdup("cherry");
    cherry->next = NULL;
    insert_hash_table_single(hash_table, cherry);

    print_hash_table(hash_table);

    delete_from_hash_table(hash_table, "banana");
    delete_from_hash_table(hash_table, "grape");

    print_hash_table(hash_table);

    free_hash_table(hash_table);

    return 0;
}
