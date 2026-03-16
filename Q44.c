// Problem Statement:
// Perform inorder, preorder, and postorder traversals of a given binary tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)

// Output Format:
// - Print inorder, preorder, and postorder traversals

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4 2 5 1 6 3 7
// 1 2 4 5 3 6 7
// 4 5 2 6 7 3 1

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void inorder(struct Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n,i;
    scanf("%d",&n);

    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    struct Node* root = newNode(a[0]);
    root->left = newNode(a[1]);
    root->right = newNode(a[2]);
    root->left->left = newNode(a[3]);
    root->left->right = newNode(a[4]);
    root->right->left = newNode(a[5]);
    root->right->right = newNode(a[6]);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}