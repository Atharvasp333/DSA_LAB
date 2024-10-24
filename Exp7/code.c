#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node {
    int data;
    struct node* next;
};

// Function to insert a node at the beginning
struct node* insertAtBeginning(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    newNode->data = data;
    newNode->next = head;
    if (head == NULL) {
        newNode->next = newNode;  // If list is empty, point to itself
        return newNode;
    }
    while (temp->next != head) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;
    return newNode;
}

// Function to insert a node at the end
struct node* insertAtEnd(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    newNode->data = data;
    newNode->next = head;
    if (head == NULL) {
        newNode->next = newNode;  // If list is empty, point to itself
        return newNode;
    }
    while (temp->next != head) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to insert a node at a given position
struct node* insertAtPosition(struct node* head, int data, int pos) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    newNode->data = data;
    if (pos == 1) {
        newNode->next = head;
        if (head == NULL) {
            newNode->next = newNode;  // If list is empty
            return newNode;
        }
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        return newNode;
    }
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    if (temp->next == head && pos > 1) {
        printf("Position out of range\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to delete the first node
struct node* deleteFirstNode(struct node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    struct node* temp = head;
    struct node* last = head;
    while (last->next != head) {  // Traverse to the last node
        last = last->next;
    }
    if (head == last) {  // If only one node is present
        free(head);
        return NULL;
    }
    head = head->next;
    last->next = head;
    free(temp);
    return head;
}

// Function to delete the last node
struct node* deleteLastNode(struct node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    struct node* temp = head;
    struct node* prev = NULL;
    if (head->next == head) {  // Only one node
        free(head);
        return NULL;
    }
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
    return head;
}

// Function to delete a node at a given position
struct node* deleteAtPosition(struct node* head, int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    struct node* temp = head;
    if (pos == 1) {
        return deleteFirstNode(head);
    }
    struct node* prev = NULL;
    for (int i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == head && pos > 1) {
        printf("Position out of range\n");
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

// Function to display the circular linked list
void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main function with switch-case structure
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
