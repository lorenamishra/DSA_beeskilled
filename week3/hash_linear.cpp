
#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert using Linear Probing
void insert(int key) {
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;

        if (index == start) {
            printf("Hash Table is full!\n");
            return;
        }
    }

    hashTable[index] = key;
}

// Display Hash Table
void display() {
    printf("\nHash Table:\n");
    printf("Index\tValue\n");

    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1) {
            printf("%d\tEmpty\n", i);
        } else {
            printf("%d\t%d\n", i, hashTable[i]);
        }
    }
}

int main() {
    int n, key;

    // Initialize Hash Table
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
