#include <stdio.h>

#define MAX 100  // Maximum size of the stack

int stack[MAX];
int top = -1;  // Stack is initially empty

// Function to push an element onto the stack
void push(int element) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d onto the stack.\n", element);
    } else {
        top++;
        stack[top] = element;
        printf("%d pushed onto the stack.\n", element);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! The stack is empty.\n");
    } else {
        printf("%d popped from the stack.\n", stack[top]);
        top--;
    }
}

// Function to display the current stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function
int main() {
    int choice, element, maxSize;

    printf("Enter the maximum size of the stack: ");
    scanf("%d", &maxSize);

    if (maxSize > MAX) {
        printf("Maximum allowed stack size is %d.\n", MAX);
        maxSize = MAX;
    }

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (top < maxSize - 1) {
                    printf("Enter the element to push: ");
                    scanf("%d", &element);
                    push(element);
                } else {
                    printf("Stack Overflow! Cannot push more elements.\n");
                }
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}
