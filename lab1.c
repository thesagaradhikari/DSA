//static implementation of stack
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX 5
struct STACK
{
    int TOS;
    int DATA[MAX];
};
int IsFull(struct STACK *s)
{
    return (s->TOS == MAX - 1) ? TRUE : FALSE;
}
int IsEmpty(struct STACK *s)
{
    return s->TOS == -1 ? TRUE : FALSE;
}
void Enqueue(struct STACK *s, int element)
{
    s->DATA[++s->TOS] = element;
}
int Dequeue(struct STACK *s)
{
    return s->DATA[s->TOS--];
}
int main()
{
    int choice, value;
    struct STACK S = {-1};
    do
    {
        printf("\n1. push\n2. pop\n 4. exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (IsFull(&S))
                printf("Stack OverFlow\n");
            else
            {
                printf("enter element:");
                scanf("%d", &value);
                Enqueue(&S, value);
                printf("%d was pushed\n", value);
            }

            break;
        case 2:
            if (IsEmpty(&S))

                printf("Stack UnderFlow");

            else

                printf("%d was a poped\n", Dequeue(&S));

            break;
        case 3:
            printf("tata\n");
            break;

        default:
            printf(
                "enter 123 only\n");
            break;
        }
    } while (choice != 3);
    printf("\n");
    return 0;
}