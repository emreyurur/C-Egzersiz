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
struct hash_tablosu *create_hash_table(int table_size, int multiplier);
void insert_hash_table(struct hash_tablosu *htable, char *anahtar);
void print_hash_table(struct hash_tablosu *htable);
void delete_hash_table(struct hash_tablosu *htable);

// Hash fonksiyonu
unsigned int hash(char *s, int multiplier, int table_size) {
    unsigned int value = 0;
    while (*s) {
        value = (value * multiplier + *s) % table_size;
        s++;
    }
    return value;
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

// Eleman ekleme fonksiyonu
void insert_hash_table(struct hash_tablosu *htable, char *anahtar) {
    int hash_index = hash(anahtar, htable->multiplier, htable->tablo_uzunlugu);
    struct cell **header = &((htable->tablo_basi + hash_index)->header);

    struct cell *current = *header;
    while (current != NULL) {
        if (strcmp(current->anahtar, anahtar) == 0) {
            printf("Anahtar zaten var: %s\n", anahtar);
            return;
        }
        current = current->next;
    }

    struct cell *new_cell = (struct cell *)malloc(sizeof(struct cell));
    new_cell->anahtar = strdup(anahtar);
    new_cell->next = *header;
    *header = new_cell;

    (htable->tablo_basi + hash_index)->count++;
    printf("Anahtar eklendi: %s\n", anahtar);
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

// Hash tablosunu silme fonksiyonu
void delete_hash_table(struct hash_tablosu *htable) {
    if (htable == NULL) {
        return; // Eğer hash tablosu zaten boşsa hiçbir şey yapma
    }

    // Tüm hücreleri dolaş
    for (int i = 0; i < htable->tablo_uzunlugu; i++) {
        struct cell *current = htable->tablo_basi[i].header;

        // Her hücrenin bağlı listesini temizle
        while (current != NULL) {
            struct cell *temp = current;
            current = current->next;
            free(temp->anahtar); // Anahtar için ayrılan belleği serbest bırak
            free(temp);          // Düğümün kendisi için ayrılan belleği serbest bırak
        }
    }

    // Hash tablosunun hücre dizisi için ayrılan belleği serbest bırak
    free(htable->tablo_basi);

    // Hash tablosunun kendisi için ayrılan belleği serbest bırak
    free(htable);

    printf("Hash tablosu tamamen silindi.\n");
}

// Ana program
int main() {
    // Hash tablosu oluştur
    struct hash_tablosu *hash_table = create_hash_table(10, 31);

    // Eleman ekle
    insert_hash_table(hash_table, "apple");
    insert_hash_table(hash_table, "banana");
    insert_hash_table(hash_table, "cherry");

    // Hash tablosunu yazdır
    print_hash_table(hash_table);

    // Hash tablosunu sil
    delete_hash_table(hash_table);

    return 0;
}
