// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)

// Output:
// - Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coef, exp;
    struct Node* next;
};

int main(){

    int n,c,e;
    scanf("%d",&n);

    struct Node *head=NULL,*temp=NULL,*newnode;

    for(int i=0;i<n;i++){
        scanf("%d%d",&c,&e);

        newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->coef=c;
        newnode->exp=e;
        newnode->next=NULL;

        if(head==NULL)
            head=temp=newnode;
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }

    temp=head;

    while(temp!=NULL){
        if(temp->exp==0)
            printf("%d",temp->coef);
        else if(temp->exp==1)
            printf("%dx",temp->coef);
        else
            printf("%dx^%d",temp->coef,temp->exp);

        if(temp->next!=NULL)
            printf(" + ");

        temp=temp->next;
    }

    return 0;
}