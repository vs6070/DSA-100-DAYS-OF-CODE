// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

// Explanation
// One possible MST edges: (2-3), (3-4), (1-2)

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];
int visited[MAX];

// Min Heap
typedef struct {
    int node, weight;
} HeapNode;

HeapNode heap[MAX];
int size = 0;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(int node, int weight) {
    heap[++size] = (HeapNode){node, weight};
    int i = size;

    while (i > 1 && heap[i].weight < heap[i/2].weight) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[size--];

    int i = 1;
    while (1) {
        int smallest = i;
        int left = 2*i, right = 2*i + 1;

        if (left <= size && heap[left].weight < heap[smallest].weight)
            smallest = left;
        if (right <= size && heap[right].weight < heap[smallest].weight)
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
    return top;
}

void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    int totalWeight = 0;

    // start from node 1
    push(1, 0);

    while (size > 0) {
        HeapNode cur = pop();
        int node = cur.node;
        int wt = cur.weight;

        if (visited[node]) continue;

        visited[node] = 1;
        totalWeight += wt;

        for (Node* temp = adj[node]; temp != NULL; temp = temp->next) {
            if (!visited[temp->v]) {
                push(temp->v, temp->w);
            }
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}