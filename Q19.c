// Problem: Given an array of integers, find two elements whose sum is closest to zero.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int min = 9999;
    int x, y;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum = a[i] + a[j];

            if(abs(sum) < min)
            {
                min = abs(sum);
                x = a[i];
                y = a[j];
            }
        }
    }

    printf("%d %d",x,y);

    return 0;
}
