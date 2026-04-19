// Problem Statement
// Using BFS or DFS, check if the entire graph is connected.

// Input Format
// n m
// edges

// Output Format
// CONNECTED
// NOT CONNECTED

// Sample Input
// 4 2
// 1 2
// 3 4

// Sample Output
// NOT CONNECTED

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int visited[MAX];

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* adj[MAX];

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int node) {
    visited[node] = 1;

    for (Node* temp = adj[node]; temp != NULL; temp = temp->next) {
        if (!visited[temp->val]) {
            dfs(temp->val);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(u, v);
        addEdge(v, u);
    }

    // start DFS from node 1
    dfs(1);

    // check if all nodes are visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}