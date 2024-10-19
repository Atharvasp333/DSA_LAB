#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Queue;

void initialize(Queue *q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

int isFull(Queue *q) {
    return q->size == MAX;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
    } else {
        q->arr[q->rear] = value;
        q->rear = (q->rear + 1) % MAX;
        q->size++;
        printf("%d enqueued to queue\n", value);
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int value = q->arr[q->front];
        q->front = (q->front + 1) % MAX;
        q->size--;
        return value;
    }
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return q->arr[q->front];
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        int i = q->front;
        for (int count = 0; count < q->size; count++) {
            printf("%d\n", q->arr[i]);
            i = (i + 1) % MAX;
        }
    }
}

int main() {
    Queue q;
    int choice, value;
    
    initialize(&q);
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Front value: %d\n", value);
                }
                break;
            case 4:
                display(&q);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
