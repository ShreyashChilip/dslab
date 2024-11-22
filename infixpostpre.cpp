#include <stdio.h>

#define MAX 100

// Stack for operators and operands
char stack[MAX];
int top = -1;

// Function prototypes
void push(char);
char pop();
int precedence(char);
void infixToPostfix(char[], char[]);
void infixToPrefix(char[], char[]);

// Stack functions
void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to determine the precedence of operators
int precedence(char symbol) {
    switch (symbol) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char item;
    for (i = 0; infix[i] != '\0'; i++) {
        item = infix[i];
        if (isalnum(item)) {
            postfix[j++] = item;
        } else if (item == '(') {
            push(item);
        } else if (item == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        } else { // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

// Function to reverse a string
void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Function to replace '(' with ')' and vice versa
void replaceBrackets(char *exp) {
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }
}

// Function to convert infix expression to prefix
void infixToPrefix(char infix[], char prefix[]) {
    reverse(infix);
    replaceBrackets(infix);
    infixToPostfix(infix, prefix);
    reverse(prefix);
}

// Main function with menu options
int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    int choice;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    printf("Choose conversion type:\n");
    printf("1. Infix to Postfix\n");
    printf("2. Infix to Prefix\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            infixToPostfix(infix, postfix);
            printf("Postfix Expression: %s\n", postfix);
            break;
        case 2:
            infixToPrefix(infix, prefix);
            printf("Prefix Expression: %s\n", prefix);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
