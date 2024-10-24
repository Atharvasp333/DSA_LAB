#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* insertAtBeginning(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    struct node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    return newNode;
}

struct node* insertAtEnd(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    struct node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    return head;
}

struct node* insertAtPosition(struct node* head, int data, int pos) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if (pos == 1) {
        return insertAtBeginning(head, data);
    }
    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    if (temp->next == head && pos > 1) {
        printf("Position out of range\n");
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

struct node* deleteFirstNode(struct node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    struct node* last = head->prev;
    struct node* temp = head;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    head = head->next;
    head->prev = last;
    last->next = head;
    free(temp);
    return head;
}

struct node* deleteLastNode(struct node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    struct node* last = head->prev;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    last->prev->next = head;
    head->prev = last->prev;
    free(last);
    return head;
}

struct node* deleteAtPosition(struct node* head, int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    if (pos == 1) {
        return deleteFirstNode(head);
    }
    struct node* temp = head;
    for (int i = 1; i < pos && temp->next != head; i++) {
        temp = temp->next;
    }
    if (temp->next == head && pos > 1) {
        printf("Position out of range\n");
        return head;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return head;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    struct node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteFirstNode(head);
                break;
            case 5:
                head = deleteLastNode(head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
