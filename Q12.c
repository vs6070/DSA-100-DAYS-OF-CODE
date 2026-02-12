// Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

// Input:
// - First line: two integers m and n representing the number of rows and columns
// - Next m lines: n integers each representing the elements of the matrix

// Output:
// - Print "Symmetric Matrix" if the given matrix is symmetric
// - Otherwise, print "Not a Symmetric Matrix"


#include <stdio.h>

int main() {
    int m, n, i, j;
    int a[10][10];

    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix");
    return 0;
}
