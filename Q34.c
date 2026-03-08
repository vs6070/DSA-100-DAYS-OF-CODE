// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    int data;
    struct node *next;
};

struct node *top=NULL;

void push(int x){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->next=top;
    top=temp;
}

int pop(){
    int x=top->data;
    struct node *temp=top;
    top=top->next;
    free(temp);
    return x;
}

int main(){
    char exp[50];
    int i,a,b;

    scanf("%s",exp);

    for(i=0;exp[i]!='\0';i++){
        if(isdigit(exp[i]))
            push(exp[i]-'0');
        else{
            b=pop();
            a=pop();

            if(exp[i]=='+') push(a+b);
            if(exp[i]=='-') push(a-b);
            if(exp[i]=='*') push(a*b);
            if(exp[i]=='/') push(a/b);
        }
    }

    printf("%d",pop());
}
