// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int main(){
    int n,k,x;

    scanf("%d",&n);

    struct Node *head=NULL,*temp=NULL,*newnode;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=x;
        newnode->next=NULL;

        if(head==NULL)
            head=temp=newnode;
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }

    scanf("%d",&k);

    int len=1;
    temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
        len++;
    }

    temp->next=head;      // make circle

    k=k%len;
    int move=len-k;

    struct Node *newTail=head;

    for(int i=1;i<move;i++)
        newTail=newTail->next;

    head=newTail->next;
    newTail->next=NULL;

    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}