// Problem Statement:
// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print traversal in zigzag order

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 1 3 2 4 5 6 7

// Explanation:
// Level 1 is printed left-to-right, level 2 right-to-left, and so on.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

void zigzag(struct Node* root) {
    struct Node* q[100];
    int front = 0, rear = 0;
    int leftToRight = 1;

    q[rear++] = root;

    while (front < rear) {
        int size = rear - front;
        int arr[100];

        for (int i = 0; i < size; i++) {
            struct Node* temp = q[front++];

            int idx = leftToRight ? i : size - i - 1;
            arr[idx] = temp->data;

            if (temp->left) q[rear++] = temp->left;
            if (temp->right) q[rear++] = temp->right;
        }

        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);

        leftToRight = !leftToRight;
    }
}

int main() {
    // Example tree: 1 2 3 4 5 6 7
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    zigzag(root);
    return 0;
}