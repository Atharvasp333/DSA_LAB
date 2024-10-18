#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    int value = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return value;
}

int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

int isEmpty() {
    return top == NULL;
}

void display() {
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Top element is %d\n", peek());
    printf("Popped element is %d\n", pop());
    display();
    printf("Stack is empty: %s\n", isEmpty() ? "Yes" : "No");
    return 0;
}
