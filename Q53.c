// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* newNode(int val) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    t->left = t->right = NULL;
    return t;
}

// Build tree (level order)
struct Node* build(int arr[], int n) {
    if (arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* q[MAX];
    int f = 0, r = 0;

    q[r++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = q[f++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[r++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[r++] = curr->right;
        }
        i++;
    }
    return root;
}

// Vertical Order
void vertical(struct Node* root) {
    int map[200][20], count[200] = {0};
    struct Node* q[MAX];
    int hd[MAX];

    int f = 0, r = 0;
    q[r] = root; hd[r++] = 100;

    int min = 100, max = 100;

    while (f < r) {
        struct Node* curr = q[f];
        int h = hd[f++];
        
        if (h < min) min = h;
        if (h > max) max = h;

        map[h][count[h]++] = curr->data;

        if (curr->left) {
            q[r] = curr->left;
            hd[r++] = h - 1;
        }
        if (curr->right) {
            q[r] = curr->right;
            hd[r++] = h + 1;
        }
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i]; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = build(arr, n);
    vertical(root);

    return 0;
}