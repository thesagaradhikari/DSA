#include <stdio.h>
#include <stdlib.h>

struct DLL
{
    int data;
    struct DLL *prev;
    struct DLL *next;
};

struct DLL *first = NULL, *last = NULL;

void insertionAtBeginning(int element)
{
    struct DLL *newNode = (struct DLL *)malloc(sizeof(struct DLL));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (first == NULL)
    {
        first = last = newNode;
    }
    else
    {
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    }
}

void traverse()
{
    struct DLL *temp = first;
    if (first == NULL)
        printf("List is empty\n");
    else
    {
        while (temp->next != NULL)
        {
            printf("%d <<->> ", temp->data);
            temp = temp->next;
        }
        printf("%d <<->> NULL\n", temp->data);
    }
}

void reverse()
{
    struct DLL *temp = last;
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp->prev != NULL)
        {
            printf("%d <<->> ", temp->data);
            temp = temp->prev;
        }
        printf("%d <<->> NULL\n", temp->data);
    }
}

struct DLL *copy(struct DLL *first)
{
    struct DLL *copyFirst = NULL;
    struct DLL *copyLast = NULL;
    struct DLL *temp = first;

    while (temp != NULL)
    {
        struct DLL *copyNode = (struct DLL *)malloc(sizeof(struct DLL));

        if (copyNode == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        copyNode->data = temp->data;
        copyNode->prev = NULL;
        copyNode->next = NULL;

        if (copyFirst == NULL)
        {
            copyFirst = copyLast = copyNode;
        }
        else
        {
            copyLast->next = copyNode;
            copyNode->prev = copyLast;
            copyLast = copyNode;
        }

        temp = temp->next;
    }

    return copyFirst;
}


int main()
{
    insertionAtBeginning(40);
    insertionAtBeginning(30);
    insertionAtBeginning(20);
    insertionAtBeginning(10);

    printf("Original List: ");
    traverse();

    printf("Reversed List: ");
    reverse();

    struct DLL *copyList = copy(first);

    printf("Copied List: ");
    traverse();

    return 0;
}