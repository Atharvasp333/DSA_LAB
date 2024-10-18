#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void insertAtBeginning(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        newNode->next = newNode->prev = newNode;
        head = newNode;
    }
    else
    {
        struct Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        newNode->next = newNode->prev = newNode;
        head = newNode;
    }
    else
    {
        struct Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = head->prev = newNode;
    }
}

void insertAtPosition(int data, int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (position == 1)
    {
        insertAtBeginning(data);
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1; i++)
        temp = temp->next;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteFromBeginning()
{
    if (head == NULL)
        return;
    struct Node *temp = head;
    if (head->next == head)
    {
        head = NULL;
        free(temp);
        return;
    }
    struct Node *last = head->prev;
    head = head->next;
    last->next = head;
    head->prev = last;
    free(temp);
}

void deleteFromEnd()
{
    if (head == NULL)
        return;
    struct Node *last = head->prev;
    if (head->next == head)
    {
        head = NULL;
        free(last);
        return;
    }
    struct Node *secondLast = last->prev;
    secondLast->next = head;
    head->prev = secondLast;
    free(last);
}

void deleteFromPosition(int position)
{
    if (head == NULL)
        return;
    struct Node *temp = head;
    if (position == 1)
    {
        deleteFromBeginning();
        return;
    }
    for (int i = 1; i < position; i++)
        temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display()
{
    if (head == NULL)
        return;
    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    insertAtPosition(15, 3);
    display();
    deleteFromPosition(2);
    display();
    deleteFromBeginning();
    display();
    deleteFromEnd();
    display();
    return 0;
}
