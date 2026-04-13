// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

// Sample Input
// 7
// 4
// INSERT 49
// INSERT 56
// SEARCH 49
// SEARCH 15

// Sample Output
// FOUND
// NOT FOUND

// Explanation
// Collisions resolved using i² jumps.

#include <stdio.h>

#define MAX 100

int hashTable[MAX];
int size;

// Initialize table
void init() {
    for (int i = 0; i < size; i++)
        hashTable[i] = -1; // -1 means empty
}

// Insert using quadratic probing
void insert(int key) {
    int h = key % size;

    for (int i = 0; i < size; i++) {
        int index = (h + i * i) % size;

        if (hashTable[index] == -1) {
            hashTable[index] = key;
            return;
        }
    }

    printf("Hash Table Full\n");
}

// Search using quadratic probing
void search(int key) {
    int h = key % size;

    for (int i = 0; i < size; i++) {
        int index = (h + i * i) % size;

        if (hashTable[index] == key) {
            printf("FOUND\n");
            return;
        }

        if (hashTable[index] == -1) {
            break; // stop if empty slot found
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &size);   // table size
    scanf("%d", &q);      // number of operations

    init();

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {
            insert(key);
        } else if (op[0] == 'S') {
            search(key);
        }
    }

    return 0;
}