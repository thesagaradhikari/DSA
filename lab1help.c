#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX 5
struct STACK
{
    int TOS;
    char data[MAX][20];
};
int IsFull(struct STACK *s)
{
    return (s->TOS == MAX - 1) ? TRUE : FALSE;
}
int IsEmpty(struct STACK *s)
{
    return s->TOS == -1 ? TRUE : FALSE;
}
void push(struct STACK *s, char *enteredname)//since name is a string.
{
    strcpy(s->data[++s->TOS], enteredname);
}
char *Pop(struct STACK *s)
{
    return s->data[s->TOS--];
}
int main()
{
    int choice;
    char name[20];
    struct STACK S = {-1};// TOS= -1
    do
    {
        printf("\n1. Push\n2. Pop\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (IsFull(&S)) printf("\nStack OverFlow\n");
            else
            {
                printf("\nStack is not full so,\n");
                printf("Enter Name to insert in stack:- ");
                scanf("%s", name);
                push(&S, name);
                printf("\nThe name that was pushed onto the stack is:- %s\n", name);
            }
            break;
        case 2:
            if (IsEmpty(&S)) printf("\nStack UnderFlow\n");
            else
            {       
                printf("\nThe name that was popped from the stack is:- %s \n",Pop(&S));
            }
            break;
        case 3:
            printf("You have decided to exit.\n");
            break;
        default:
            printf("Enter 1,2,3 only\n");
            break;
        }
    } while (choice != 3);
}
