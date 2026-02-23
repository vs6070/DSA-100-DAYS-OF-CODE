// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create(int n)
{
    struct node *head=NULL,*temp,*newnode;
    int x;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=NULL;

        if(head==NULL)
            head=temp=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

struct node* merge(struct node* a,struct node* b)
{
    struct node *c,*temp;

    if(a->data < b->data)
    {
        c=temp=a;
        a=a->next;
    }
    else
    {
        c=temp=b;
        b=b->next;
    }

    while(a!=NULL && b!=NULL)
    {
        if(a->data < b->data)
        {
            temp->next=a;
            temp=a;
            a=a->next;
        }
        else
        {
            temp->next=b;
            temp=b;
            b=b->next;
        }
    }

    if(a!=NULL)
        temp->next=a;
    else
        temp->next=b;

    return c;
}

void display(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}

int main()
{
    int n,m;
    scanf("%d",&n);
    struct node* l1=create(n);

    scanf("%d",&m);
    struct node* l2=create(m);

    struct node* l3=merge(l1,l2);
    display(l3);
}
