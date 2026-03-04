// Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottomProblem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom

#include <stdio.h>

int main() {
    int stack[100], top = -1;
    int n, m, i;

    // number of elements to push
    scanf("%d", &n);

    // push elements
    for(i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
    }

    // number of pops
    scanf("%d", &m);

    // pop elements
    for(i = 0; i < m; i++) {
        if(top >= 0)
            top--;
    }

    // display stack from top to bottom
    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}