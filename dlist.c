
/**
 * Doubly Linked List using Dynamic Memory Allocation
 * Vishesh Yadav
 *
 */


#include<stdio.h>
#include<stdlib.h>


typedef struct _list_node {
    struct _list_node *next, *previous;
    int data;
} ListNode;

typedef struct {
    ListNode *head;
} List;

ListNode* list_get_head(List *l)
{
    return l->head;
}

ListNode* list_create_node(int data, ListNode* next, ListNode* previous)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    if (node) {
        node->data = data;
        node->next = next;
        node->previous = previous;
        if (next)
            next->previous = node;
        if (previous)
            previous->next = node;
    }
    return node;
}

List* list_new()
{
    List* list = (List*)malloc(sizeof(List));
    if (list)
        list->head = NULL;
    return list;
}

void list_free(List *l)
{
    ListNode *node = list_get_head(l), *temp;
    while (node)	{
        temp = node;
        node = node->next;
        free(temp);
    }
}

int list_is_empty(List* l)
{
    return l->head==NULL;
}

int list_push_front(List* l, int data)
{
    ListNode *node = list_create_node(data, l->head, NULL);
    if (!node)
        return 0;
    l->head = node;
    return 1;
}

int list_insert_at(List *l, int pos, int data)
{
    int i;
    ListNode *at = list_get_head(l), *node;

    if (pos==0)
        return list_push_front(l, data);

    for (i=0; i<pos; i++) {
        at = at->next;
        if (!at && i!=pos-1)
            return 0;
    }

    node = list_create_node(data, at, at->previous);
    return node!=NULL;
}

ListNode* list_get_tail(List *l)
{
    ListNode *node = list_get_head(l);
    if (!node)
        return NULL;
    while (node->next)
        node = node->next;
    return node;
}

int list_push_back(List *l, int data)
{
    ListNode *node;
    ListNode *last = list_get_tail(l);

    if (!last)
        return list_push_front(l, data);

    node = list_create_node(data, NULL, last);
    if (!node)
        return 0;
    return 1;
}

void list_free_node(ListNode* node)
{
    if (node->previous)
        node->previous->next = node->next;
    if (node->next)
        node->next->previous = node->previous;
}

int list_pop_back(List* l)
{
    ListNode *last;;
    if (list_is_empty(l))
        return 0;
    last = list_get_tail(l);
    list_free_node(last);
    return 1;
}

int list_pop_front(List* l)
{
    ListNode *new_front;
    if (list_is_empty(l))
        return 0;
    new_front = list_get_head(l)->next;
    list_free_node(list_get_head(l));
    l->head = new_front;
    return 1;
}

int list_delete_at(List *l, int pos)
{
    int i;
    ListNode *at = list_get_head(l);
    if (list_is_empty(l))
        return 0;

    if (pos==0)
        return list_pop_front(l);

    for (i=0; i<pos; i++) {
        at = at->next;
        if (!at && i!=pos-1)
            return 0;
    }

    list_free_node(at);
    return 1;
}

void print_list(List *l)
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
    List *l = list_new();
    char choice = '\0';
    int pos, data;

    while (choice!='x') {
        printf("\nLinked List\n--------------------------------");
        printf("\n\n\nWhat would you like to do?\n");
        printf("\n  1. Insert at First Position");
        printf("\n  2. Insert at Last Position");
        printf("\n  3. Insert at nth Position");
        printf("\n  4. Delete First Element");
        printf("\n  5. Delete Last Element");
        printf("\n  6. Delete from nth Position");
        printf("\n  7. Print the List");
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
            list_push_front(l, data);
            print_list(l);
            break;
        case '2':
            printf("\nEnter data: ");
            scanf("%d", &data);
            list_push_back(l, data);
            print_list(l);
            break;
        case '3':
            printf("\nEnter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            list_insert_at(l, pos, data);
            print_list(l);
            break;
        case '4':
            list_pop_front(l);
            print_list(l);
            break;
        case '5':
            list_pop_back(l);
            print_list(l);
            break;
        case '6':
            printf("Enter position: ");
            scanf("%d", &pos);
            list_delete_at(l, pos);
            print_list(l);
            break;
        case '7':
            print_list(l);
            break;
        }

    }
    list_free(l);
}
