// Problem: Given an array of integers, rotate the array to the right by k positions.

// Input:
// - First line: integer n
// - Second line: n integers
// - Third line: integer k

// Output:
// - Print the rotated array

#include <stdio.h>

int main()
{
    int n, i, k;
    
    scanf("%d", &n);
    
    int arr[n];
    
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &k);
    
    k = k % n;
    
    int temp[n];
    
    for(i = 0; i < k; i++)
    {
        temp[i] = arr[n - k + i];
    }
    
    for(i = k; i < n; i++)
    {
        temp[i] = arr[i - k];
    }
    
    for(i = 0; i < n; i++)
    {
        printf("%d ", temp[i]);
    }

    return 0;
}
