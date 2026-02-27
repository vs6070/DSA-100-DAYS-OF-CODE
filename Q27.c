// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create(int n) {
    struct node *head=NULL,*temp,*newnode;
    int x;
    for(int i=0;i<n;i++) {
        scanf("%d",&x);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=NULL;
        if(head==NULL)
            head=temp=newnode;
        else {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

int main() {
    int n,m;
    scanf("%d",&n);
    struct node *h1=create(n);
    scanf("%d",&m);
    struct node *h2=create(m);

    if(h1 && h2) {
        struct node *t=h1;
        while(t->next)
            t=t->next;
        t->next=h2;
    }

    struct node *p=h1,*q=h2;

    while(p!=q) {
        p=p?p->next:h2;
        q=q?q->next:h1;
    }

    if(p)
        printf("%d",p->data);
    else
        printf("No Intersection");
}