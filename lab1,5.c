#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct
{
    char data[MAX_SIZE][20];
    int top;
} StringStack;

int isEmptyStack(StringStack *stack)
{
    return stack->top == -1;
}

int isFullStack(StringStack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(StringStack *stack, char *element)
{
    if (isFullStack(stack))
    {
        printf("Error: Stack is full!\n");
        return;
    }
    strcpy(stack->data[++stack->top], element);
}

char *pop(StringStack *stack)
{
       return stack->data[stack->top--];
}

int main()
{
    StringStack stack = {-1};
    push(&stack, "apple");
    push(&stack, "banana");
    char *popped_element = pop(&stack);
    printf("Popped element: %s\n", popped_element);

    return 0;
}