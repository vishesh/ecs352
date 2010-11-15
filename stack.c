
/**
 * Stack using Array
 * Vishesh Yadav
 *
 */


#include<stdio.h>
#include<stdlib.h>


typedef struct _stack {
    int *data;
    unsigned int size;
    unsigned int tail;
} Stack;

Stack* stack_new(unsigned int size)
{
    Stack *stck = (Stack*)malloc(sizeof(Stack));
    if (stck) {
        stck->data = (int*)malloc(sizeof(int)*size);
        if (!stck->data) {
            free(stck);
            return NULL;
        }
        stck->size = size;
        stck->tail = 0;
    }
    return stck;
}

int stack_is_empty(Stack *stack)
{
    return stack->tail==0;
}

int stack_is_full(Stack *stack)
{
    return stack->tail==stack->size;
}

int stack_push(Stack *stack, int data)
{
    if (stack_is_full(stack))
        return 0;
    stack->data[stack->tail++] = data;
    return 1;
}

int stack_pop(Stack *stack)
{
    if (stack_is_empty(stack))
        return 0;
    return stack->data[--stack->tail];
}

int stack_peek(Stack *stack)
{
    if (stack_is_empty(stack))
        return -1;
    return stack->data[stack->tail-1];
}

void stack_free(Stack *stack)
{
    free(stack->data);
    free(stack);
}

void print_stack(Stack *stack)
{
    unsigned int i;
    printf("\n------\n");
    for (i=0; i<stack->tail; i++)
        printf("%d  ", stack->data[i]);
    printf("\n------\n");
}


int main()
{
    Stack *s = stack_new(10);
    char choice = '\0';
    int data;

    while (choice!='x') {
        printf("\nStack\n--------------------------------");
        printf("\n\n\nWhat would you like to do?\n");
        printf("\n  1. Push");
        printf("\n  2. Pop");
        printf("\n  3. Print the Stack contents");
        printf("\n  x. Exit");
        printf("\n\nEnter Choice: ");
        fflush(stdin);
        scanf("%c", &choice);
        printf("-----\n");
        switch (choice) {
        case 'x':
            break;
        case '1':
            printf("\nEnter data: ");
            scanf("%d", &data);
            stack_push(s, data);
            print_stack(s);
            break;
        case '2':
            printf("\nPopped: %d", stack_pop(s));
            print_stack(s);
            break;
        case '3':
            print_stack(s);
            break;
        }

    }
    stack_free(s);
}
