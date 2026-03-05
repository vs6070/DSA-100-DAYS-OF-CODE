// Problem: Convert an infix expression to postfix notation using stack.

// Input:
// - Single line: infix expression (operands are single characters)

// Output:
// - Print the postfix expression

#include<stdio.h>
#include<ctype.h>

char stack[100];
int top=-1;

void push(char x){
    stack[++top]=x;
}

char pop(){
    return stack[top--];
}

int pr(char x){
    if(x=='+'||x=='-') return 1;
    if(x=='*'||x=='/') return 2;
    return 0;
}

int main(){
    char exp[100];
    int i=0;

    printf("Enter infix: ");
    scanf("%s",exp);

    while(exp[i]){
        if(isalnum(exp[i]))
            printf("%c",exp[i]);

        else if(exp[i]=='(')
            push(exp[i]);

        else if(exp[i]==')'){
            while(stack[top]!='(')
                printf("%c",pop());
            pop();
        }

        else{
            while(top!=-1 && pr(stack[top])>=pr(exp[i]))
                printf("%c",pop());
            push(exp[i]);
        }
        i++;
    }

    while(top!=-1)
        printf("%c",pop());

    return 0;
}