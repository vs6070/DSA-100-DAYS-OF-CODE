// Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the circular linked list elements starting from head, space-separated


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, i;
    struct node *head = NULL, *newnode, *temp, *last = NULL;

    scanf("%d", &n);

    // Creating Circular Linked List
    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);

        if(head == NULL) {
            head = newnode;
            last = newnode;
        } else {
            last->next = newnode;
            last = newnode;
        }
    }
    last->next = head;   // circular link

    // Traversal
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    return 0;
}
