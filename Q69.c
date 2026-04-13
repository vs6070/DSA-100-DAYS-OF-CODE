// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph
struct Node* adj[MAX];

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Priority Queue (Min Heap)
struct Pair {
    int vertex;
    int dist;
};

struct Pair heap[MAX];
int size = 0;

// Swap
void swap(struct Pair* a, struct Pair* b) {
    struct Pair temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[i].dist < heap[(i - 1) / 2].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert into heap
void push(int v, int d) {
    heap[size].vertex = v;
    heap[size].dist = d;
    heapifyUp(size);
    size++;
}

// Extract min
struct Pair pop() {
    struct Pair root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}

// Dijkstra Algorithm
void dijkstra(int n, int source) {
    int dist[MAX];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;
    push(source, 0);

    while (size > 0) {
        struct Pair p = pop();
        int u = p.vertex;

        struct Node* temp = adj[u];

        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

// Main function
int main() {
    int n = 5;

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(4, 1, 3);
    addEdge(4, 2, 9);
    addEdge(4, 3, 2);
    addEdge(3, 2, 4);

    dijkstra(n, 0);

    return 0;
}