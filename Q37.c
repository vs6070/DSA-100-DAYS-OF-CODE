// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty


#include <stdio.h>

int pq[100];
int size = 0;

void insert(int x)
{
    pq[size] = x;
    size++;
}

void deleteElement()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int min = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[min])
            min = i;
    }

    printf("%d\n", pq[min]);

    for(int i = min; i < size-1; i++)
        pq[i] = pq[i+1];

    size--;
}

void peek()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int min = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[min])
            min = i;
    }

    printf("%d\n", pq[min]);
}

int main()
{
    int n, x;
    char op[10];

    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s",op);

        if(op[0]=='i')
        {
            scanf("%d",&x);
            insert(x);
        }
        else if(op[0]=='d')
        {
            deleteElement();
        }
        else if(op[0]=='p')
        {
            peek();
        }
    }

    return 0;
}