// Problem Statement
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10

#include <stdio.h>

int main() {
    int n, i, stack[100], top = -1, x;

    scanf("%d", &n);

    // push into stack
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        stack[++top] = x;
    }

    // pop from stack (reverse order)
    while(top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}