#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

struct Stack {
    int top;
    int arr[MAX];
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (!isFull(stack))
        stack->arr[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->arr[stack->top--];
    return -1;
}

int peek(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->arr[stack->top];
    return -1;
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initialize(&stack);
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        if (isdigit(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack);
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && precedence(infix[i]) <= precedence(peek(&stack))) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }
    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }
    postfix[k] = '\0';
}

int evaluatePostfix(char* postfix) {
    struct Stack stack;
    initialize(&stack);
    int i = 0, operand1, operand2, result;

    while (postfix[i]) {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '^': result = pow(operand1, operand2); break;
            }
            push(&stack, result);
        }
        i++;
    }
    return pop(&stack);
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    
    return 0;
}
