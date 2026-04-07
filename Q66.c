// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include <stdio.h>

#define MAX 100

int visited[MAX];
int recStack[MAX];

// DFS function
int dfs(int node, int n, int adj[MAX][MAX]) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {

            // If not visited → recurse
            if (!visited[i]) {
                if (dfs(i, n, adj))
                    return 1;
            }
            // If in recursion stack → cycle found
            else if (recStack[i]) {
                return 1;
            }
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return 0;
}

int hasCycle(int n, int adj[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n, adj))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    if (hasCycle(n, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}