// Problem: Given an array of integers, count the frequency of each distinct element and print the result.

// Input:
// - First line: integer n (size of array)
// - Second line: n integers

// Output:
// - Print each element followed by its frequency in the format element:count

#include <stdio.h>

int main()
{
    int n,i,j,count;
    scanf("%d",&n);

    int a[n];

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        count=0;

        for(j=0;j<n;j++)
        {
            if(a[i]==a[j])
                count++;
        }

        printf("%d:%d\n",a[i],count);
    }

    return 0;
}
