#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }
    else
    {
        struct Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }
    else
    {
        struct Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
}

void insertAtPosition(int value, int position)
{
    if (position < 1)
    {
        printf("Position should be >= 1\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1)
    {
        insertAtBeginning(value);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        if (temp->next == head)
        {
            printf("Position is out of range\n");
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *last = head->prev;
        struct Node *temp = head;
        head = head->next;
        head->prev = last;
        last->next = head;
        free(temp);
    }
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *last = head->prev;
        last->prev->next = head;
        head->prev = last->prev;
        free(last);
    }
}

void deleteFromPosition(int position)
{
    if (position < 1)
    {
        printf("Position should be >= 1\n");
        return;
    }

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (position == 1)
    {
        deleteFromBeginning();
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position; i++)
    {
        temp = temp->next;
        if (temp == head)
        {
            printf("Position is out of range\n");
            return;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

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
    insertAtEnd(30);
    insertAtBeginning(5);
    insertAtPosition(15, 3);
    display();

    deleteFromBeginning();
    display();

    deleteFromEnd();
    display();

    deleteFromPosition(2);
    display();

    return 0;
}
