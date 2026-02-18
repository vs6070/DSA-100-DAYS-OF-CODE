// Problem: Write a program to find the maximum and minimum values present in a given array of integers.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the maximum and minimum element

#include <stdio.h>

int main()
{
    int n, i;
    
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int max = arr[0];
    int min = arr[0];
    
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    
    printf("Maximum = %d\n", max);
    printf("Minimum = %d", min);

    return 0;
}
