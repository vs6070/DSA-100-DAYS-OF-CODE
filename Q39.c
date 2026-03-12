// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.

// Supported Operations:
// - insert x
// - extractMin
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain heap operations

// Output Format:
// - Print results of extractMin and peek
// - Print -1 if operation cannot be performed

#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void insert(int x) {
    heap[size] = x;
    int i = size;
    size++;

    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

int extractMin() {

    if(size == 0)
        return -1;

    int min = heap[0];

    heap[0] = heap[size-1];
    size--;

    int i = 0;

    while(2*i+1 < size) {

        int left = 2*i+1;
        int right = 2*i+2;
        int smallest = left;

        if(right < size && heap[right] < heap[left])
            smallest = right;

        if(heap[i] <= heap[smallest])
            break;

        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        i = smallest;
    }

    return min;
}

int peek() {
    if(size == 0)
        return -1;
    return heap[0];
}

int main() {

    int n;
    scanf("%d",&n);

    char op[20];
    int x;

    for(int i=0;i<n;i++) {

        scanf("%s",op);

        if(strcmp(op,"insert")==0) {
            scanf("%d",&x);
            insert(x);
        }

        else if(strcmp(op,"extractMin")==0) {
            printf("%d\n",extractMin());
        }

        else if(strcmp(op,"peek")==0) {
            printf("%d\n",peek());
        }
    }

    return 0;
}