#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
    int is_occupied; // 0 if empty, 1 if occupied
} HashEntry;

// Hash function
int hashFunction(int key, int table_size) {
    return key % table_size;
}

// Insert a key-value pair into the hash table
void insert(HashEntry *table, int table_size, int key, int value) {
    int index = hashFunction(key, table_size);
    int original_index = index;

    // Linear probing for collision handling
    while (table[index].is_occupied) {
        if (table[index].key == key) {
            // Update existing key's value
            table[index].value = value;
            return;
        }
        index = (index + 1) % table_size;
        if (index == original_index) {
            printf("Hash table is full, cannot insert key %d\n", key);
            return;
        }
    }

    // Insert new entry
    table[index].key = key;
    table[index].value = value;
    table[index].is_occupied = 1;
}

// Search for a key in the hash table
int search(HashEntry *table, int table_size, int key) {
    int index = hashFunction(key, table_size);
    int original_index = index;

    // Linear probing to search for the key
    while (table[index].is_occupied) {
        if (table[index].key == key) {
            return table[index].value;
        }
        index = (index + 1) % table_size;
        if (index == original_index) {
            break;
        }
    }
    return -1; // Key not found
}

// Display the hash table
void display(HashEntry *table, int table_size) {
    printf("Hash Table:\n");
    for (int i = 0; i < table_size; i++) {
        if (table[i].is_occupied) {
            printf("Index %d: Key = %d, Value = %d\n", i, table[i].key, table[i].value);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    int table_size, choice, key, value;

    printf("Enter the size of the hash table: ");
    scanf("%d", &table_size);

    // Allocate memory for the hash table
    HashEntry *hash_table = (HashEntry *)malloc(table_size * sizeof(HashEntry));
    if (!hash_table) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize the hash table
    for (int i = 0; i < table_size; i++) {
        hash_table[i].is_occupied = 0;
    }

    while (1) {
        printf("\n1. Insert 2. Search 3. Display 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value to insert: ");
                scanf("%d %d", &key, &value);
                insert(hash_table, table_size, key, value);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                value = search(hash_table, table_size, key);
                if (value != -1) {
                    printf("Value found: %d\n", value);
                } else {
                    printf("Key not found\n");
                }
                break;

            case 3:
                display(hash_table, table_size);
                break;

            case 4:
                free(hash_table); // Free allocated memory
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
