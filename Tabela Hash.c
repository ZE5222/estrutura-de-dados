#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct {
    char *key;
    int value;
} HashItem;

typedef struct {
    HashItem *table[TABLE_SIZE];
} HashTable;

unsigned int hash(char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + *key++;
    }
    return hash % TABLE_SIZE;
}

HashTable* createTable() {
    HashTable *t = (HashTable *)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        t->table[i] = NULL;
    }
    return t;
}

void insert(HashTable *t, char *key, int value) {
    unsigned int index = hash(key);
    HashItem *item = (HashItem *)malloc(sizeof(HashItem));
    item->key = strdup(key);
    item->value = value;
    t->table[index] = item;
}

int search(HashTable *t, char *key) {
    unsigned int index = hash(key);
    if (t->table[index] != NULL && strcmp(t->table[index]->key, key) == 0) {
        return t->table[index]->value;
    }
    return -1; // Key not found
}

void delete(HashTable *t, char *key) {
    unsigned int index = hash(key);
    if (t->table[index] != NULL && strcmp(t->table[index]->key, key) == 0) {
        free(t->table[index]->key);
        free(t->table[index]);
        t->table[index] = NULL;
    }
}

int main() {
    HashTable *ht = createTable();

    insert(ht, "key1", 10);
    insert(ht, "key2", 20);
    printf("Value for 'key1': %d\n", search(ht, "key1"));
    printf("Value for 'key2': %d\n", search(ht, "key2"));

    delete(ht, "key1");
    printf("Value for 'key1' after deletion: %d\n", search(ht, "key1"));

    return 0;
}
