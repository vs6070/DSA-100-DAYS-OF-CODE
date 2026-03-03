// Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

// Input:
// - First line: integer n (number of operations)
// - Next n lines: operation type and value (if applicable)
//   - 1 value: push value
//   - 2: pop
//   - 3: display

// Output:
// - For display: print stack elements from top to bottom
// - For pop: print popped element or 'Stack Underflow'


#include <stdio.h>

int stack[100];
int top = -1;

int main() {
    int n, choice, value;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &choice);

        if(choice == 1) {        // Push
            scanf("%d", &value);
            top++;
            stack[top] = value;
        }
        else if(choice == 2) {   // Pop
            if(top == -1)
                printf("Stack Underflow\n");
            else {
                printf("%d\n", stack[top]);
                top--;
            }
        }
        else if(choice == 3) {   // Display
            if(top == -1)
                printf("Stack is Empty\n");
            else {
                for(int j = top; j >= 0; j--)
                    printf("%d ", stack[j]);
                printf("\n");
            }
        }
    }
    return 0;
}