#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX 20
struct QUEUE
{
    int FRONT;
    int REAR;
    int DATA[MAX];
};
int IsFull(struct QUEUE *s)
{
    return (s->REAR == MAX - 1) ? TRUE : FALSE;
}
int IsEmpty(struct QUEUE *s)
{
    return s->REAR < s->FRONT ? TRUE : FALSE;
}
void Enqueue(struct QUEUE *s, int element)
{
    s->DATA[++s->REAR] = element;
}
int Dequeue(struct QUEUE *s)
{
    return s->DATA[s->FRONT++];
}
int main()
{
    int choice, value;
    struct QUEUE Queue = {0, -1};
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
                printf("enter element:");
                scanf("%d", &value);
                Enqueue(&Queue, value);
                printf("%d was pushed\n", value);
            }

            break;
        case 2:
            if (IsEmpty(&Queue))
                printf("Queue is empty");
            else
                printf("%d was a poped\n", Dequeue(&Queue));
            break;
        case 3:
            printf("tata\n");
            break;

        default:
            printf("enter 123 only\n");
            break;
        }
    } while (choice != 3);
    printf("\n");
    return 0;
}