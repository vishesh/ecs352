
/**
 * Queue using Linked List
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
} Queue;

ListNode* list_get_head(Queue *l)
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

Queue* queue_new()
{
    Queue* list = (Queue*)malloc(sizeof(Queue));
    if (list)
        list->head = NULL;
    return list;
}

void queue_free(Queue *l)
{
    ListNode *node = list_get_head(l), *temp;
    while (node)	{
        temp = node;
        node = node->next;
        free(temp);
    }
}

int queue_is_empty(Queue* l)
{
    return l->head==NULL;
}

ListNode* list_get_tail(Queue *l)
{
    ListNode *node = list_get_head(l);
    if (!node)
        return NULL;
    while (node->next)
        node = node->next;
    return node;
}

int queue_insert(Queue *l, int data)
{
    ListNode *node;
    ListNode *last = list_get_tail(l);

    node = list_create_node(data, NULL);
    if (!node)
        return 0;

    if (!last)
        l->head = node;
    else
        last->next = node;

    return 1;
}

int queue_remove(Queue* l)
{
    ListNode *new_front;
    int ret;
    if (queue_is_empty(l))
        return -1;
    new_front = list_get_head(l)->next;
    ret = l->head->data;
    free(list_get_head(l));
    l->head = new_front;
    return ret;
}


void print_queue(Queue *l)
{
    ListNode *node = list_get_head(l);
    printf("\n----\n");
    while (node)	{
        printf("%d    ", node->data);
        node = node->next;
    }
    printf("\n----\n\n");
}


int main()
{
    Queue *q = queue_new(10);
    char opt = ' ';

    printf("\n\nQUEUE IMPLEMENTATION USING LINKED LIST\n");

    while ( opt != 'x' ) {
        printf("  1. Insert\n");
        printf("  2. Remove\n");
        printf("  x. Exit\n\n");

        printf("\nWhat to do?\n");
        fflush(stdin);
        scanf("%c", &opt);

        if ( opt == '1' ) {
            int x;
            printf("\nEnter Data: ");
            scanf("%d", &x);
            queue_insert(q, x);
        } else if ( opt == '2' ) {
            printf("\nDequeued  ->  %d", queue_remove(q) );
        } else if ( opt == 'x' ) {
            break;
        }
        printf("\nQueue is now\n");
        print_queue(q);
    }
    queue_free(q);
    return 0;
}

