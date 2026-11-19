
#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert an element
void insert(int key) {
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            printf("Key already exists!\n");
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start) {
            printf("HashMap is full!\n");
            return;
        }
    }

    hashTable[index] = key;
    printf("%d inserted successfully.\n", key);
}

// Search for an element
void search(int key) {
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            printf("%d found at index %d.\n", key, index);
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start) {
            break;
        }
    }

    printf("%d not found.\n", key);
}

// Display the HashMap
void display() {
    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1) {
            printf("Index %d : Empty\n", i);
        } else {
            printf("Index %d : %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    int choice, key;

    // Initialize all positions as empty
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    while (1) {
        printf("\n1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
