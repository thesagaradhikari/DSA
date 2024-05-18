#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct DLL
{
    int data;
    struct DLL *prev;
    struct DLL *next;
};
struct DLL *first, *last;
void insertionATBeginning(int element)
{
    struct DLL *NewNode;
    NewNode = (struct DLL *)malloc(sizeof(struct DLL));
    if (NewNode == NULL)
    {
        printf("void");
    }
    else
    {
        NewNode->data = element;
        NewNode->prev = NULL;
        NewNode->next = NULL;
        if (first == NULL)
        {
            first = last = NewNode;
        }
        else
        {
            NewNode->next = first;
            first->prev = NewNode;
            first = NewNode;
        }
        printf("%d in front\n", first->data);
    }
}
void traverse()
{
    struct DLL *temp = first;
    if (first == NULL)
        printf("void or list is empty");

    else
    {
        while (temp->next != NULL)
        {
            printf("%d<<->>", temp->data);
            temp = temp->next;
        }
        printf("%d <<->>null\n", temp->data);
    }
}
void deletionAtBeginning()
{
    struct DLL *temp=first;
    if(first==NULL)
    {
        printf("void deletion");

    }
    else if(first->next=NULL){
        printf("%d is going to be deleted",first->data);
        first=last=NULL;
    }
    else{
        struct DLL *temp=first;
        printf("%d is going to be dedleted ",first->data);
        first=first->next;
        first->prev=NULL;
    }

}
void deletionAtEnd()
{
    struct DLL *temp=first;
    if(first==NULL)
    {
        printf("void deletion");

    }
    else if(first->next=NULL){
        printf("%d is going to be deleted",first->data);
        first=last=NULL;
    }
    else{
        struct DLL *temp=last;
        printf("%d is going to be dedleted ",last);
        last=last->prev;
        last->next=NULL;
        free(temp);
    }

}
void search(int key)
{
    int flag=0;
    if(first==NULL)
    {
        printf("emptylist");
    }
    else
    {
        struct DLL *temp=first;
        do{
            if(temp->data==key)
            {
                flag=1;
                printf("element is found");

            }
            temp=temp->next;

        }while(temp!=NULL);
        if (flag==0)
        printf("element not found");
    }

}
int main()
{
    //first = NULL;
    //last = NULL;
    insertionATBeginning(10);
    traverse();
    insertionATBeginning(20);
    traverse();
    insertionATBeginning(20);
    traverse();
    insertionATBeginning(20);
    traverse();
    insertionATBeginning(20);
    traverse();
    insertionATBeginning(20);
    traverse();
    deletionAtBeginning();
    traverse();
    deletionAtBeginning();
    traverse();
    deletionAtBeginning();
    traverse();
    deletionAtEnd();
    traverse();
    search(20);
}
