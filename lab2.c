#include <string.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX 5
#define strlength 20
typedef struct QUEUE
{
    int FRONT;
    int REAR;
    char DATA[MAX][strlength];
} Queuest;              // Renaming so have not to write (struct QUEUE) everytime
int IsFull(Queuest *s); // Function prototyping
int IsEmpty(Queuest *s);
void Enqueue(Queuest *s, char *enteredstring);
char *Dequeue(Queuest *s);
int main()
{
    int choice;
    char value[strlength];
    Queuest Queue = {0, -1};
    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (IsFull(&Queue))
                printf("Queue is full\n");
            else
            {
                printf("enter string element:");
                scanf("%s", &value);
                Enqueue(&Queue, value);
                printf("%s was Enqueued\n", value);
            }

            break;
        case 2:
            if (IsEmpty(&Queue))
                printf("Queue is empty\n");
            else
                printf("%s was  Dequeued\n", Dequeue(&Queue));
            break;
        case 3:
            printf("Exited from the program\n");
            break;

        default:
            printf("enter 1,2, or 3 only\n");
            break;
        }
    } while (choice != 3);
    printf("\n");
    return 0;
}
int IsFull(Queuest *s)
{
    return (s->REAR == MAX - 1) ? TRUE : FALSE;
}
int IsEmpty(Queuest *s)
{
    return s->REAR < s->FRONT ? TRUE : FALSE;
}
void Enqueue(Queuest *s, char *enteredstring)
{
    strcpy(s->DATA[++s->REAR], enteredstring);
}
char *Dequeue(Queuest *s) // returning an array requires pointer.
{
    return s->DATA[s->FRONT++];
}