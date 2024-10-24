#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* insertAtBeginning(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

struct node* insertAtEnd(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct node* insertAtPosition(struct node* head, int data, int pos) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    newNode->data = data;
    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct node* deleteFirstNode(struct node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* deleteLastNode(struct node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct node* deleteAtPosition(struct node* head, int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    if (pos == 1) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct node* temp = head, *prev = NULL;
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
