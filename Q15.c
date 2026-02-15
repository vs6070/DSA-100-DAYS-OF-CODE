// Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

// Input:
// - First line: two integers m and n
// - Next m lines: n integers each

// Output:
// - Print the sum of the primary diagonal elements#include <stdio.h>

#include <stdio.h>

int main()
{
    int m,n,i,j,sum=0;
    scanf("%d %d",&m,&n);

    int a[m][n];

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<m && i<n;i++)
        sum = sum + a[i][i];

    printf("%d",sum);
}

