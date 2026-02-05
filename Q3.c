// Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

// Input:
// - First line: integer n (array size)
// - Second line: n space-separated integers
// - Third line: integer k (key to search)

// Output:
// - Line 1: "Found at index i" OR "Not Found"
// Line 2: "Comparisons = c"

#include <stdio.h>

int main() {
    int n, k, i;
    int a[100];
    int count = 0, found = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        count++;
        if(a[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Not Found\n");

    printf("Comparisons = %d", count);

    return 0;
}
