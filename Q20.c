// Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the count of subarrays having sum zero

#include <stdio.h>

int main()
{
    int n, i, j, sum, count = 0;

    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n; i++)
    {
        sum = 0;

        for(j = i; j < n; j++)
        {
            sum += arr[j];

            if(sum == 0)
                count++;
        }
    }

    printf("%d", count);

    return 0;
}