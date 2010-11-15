
/**
 * Stack implementation using Linked List
 * Vishesh Yadav
 *
 */


#include<stdio.h>
#include<stdlib.h>


typedef struct _list_node {
    struct _list_node* next;
    int data;
} ListNode;

typedef struct {
    ListNode *head;
} Stack;

ListNode* stack_get_head(Stack *l)
{
    return l->head;
}

ListNode* list_create_node(int data, ListNode* next)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    if (node) {
        node->data = data;
        node->next = next;
    }
    return node;
}

Stack* stack_new()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack)
        stack->head = NULL;
    return stack;
}

void stack_free(Stack *l)
{
    ListNode *node = stack_get_head(l), *temp;
    while (node)	{
        temp = node;
        node = node->next;
        free(temp);
    }
}

int stack_is_empty(Stack* l)
{
    return l->head==NULL;
}

int stack_push(Stack* s, int data)
{
    ListNode *node = list_create_node(data, s->head);
    if (!node)
        return 0;
    s->head = node;
    return 1;
}

int stack_pop(Stack* s)
{
    ListNode *new_front;
    int ret;
    if (stack_is_empty(s))
        return -1;
    new_front = s->head->next;
    ret = s->head->data;
    free(s->head);
    s->head = new_front;
    return ret;
}

void print_stack(Stack *l)
{
    ListNode *node = stack_get_head(l);
    printf("\n----\n");
    while (node)	{
        printf("%d    ", node->data);
        node = node->next;
    }
    printf("\n----\n\n");
}

int main()
{
    Stack *s = stack_new(10);
    char choice = '\0';
    int data;

    while (choice!='x') {
        printf("\nStack using List\n--------------------------------");
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
