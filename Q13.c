// Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

// Input:
// - First line: two integers r and c representing the number of rows and columns
// - Next r lines: c integers each representing the matrix elements

// Output:
// - Print all visited elements in the order of traversal, separated by spaces

#include <stdio.h>

int main()
{
    int r,c;
    scanf("%d%d",&r,&c);

    int a[r][c];

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);

    int t=0,b=r-1,l=0,ri=c-1;

    while(t<=b && l<=ri)
    {
        for(int i=l;i<=ri;i++) printf("%d ",a[t][i]);
        t++;

        for(int i=t;i<=b;i++) printf("%d ",a[i][ri]);
        ri--;

        for(int i=ri;i>=l && t<=b;i--) printf("%d ",a[b][i]);
        b--;

        for(int i=b;i>=t && l<=ri;i--) printf("%d ",a[i][l]);
        l++;
    }
}
