
/**
 * Linked List using Arrays
 * Vishesh Yadav
 *
 */


#include<stdio.h>
#include<stdlib.h>


typedef struct _list_node {
    int next;
    int data;
    int occupied;
} ListNode;

typedef struct {
    ListNode *nodes;
    int head;
    int size;
    int total;
} List;

ListNode* list_get_node(List *list, int pos)
{
    if (pos<0 || pos>=list->size)
        return NULL;
    return (list->nodes+pos);
}

ListNode* list_get_head(List *l)
{
    return list_get_node(l, l->head);
}

ListNode* list_get_next(List *l, ListNode *node)
{
    return list_get_node(l, node->next);
}

int list_find_free_pos(List *l)
{
    int i;
    for (i=0; i<(l->size); i++)
        if ( list_get_node(l, i)->occupied==0 )
            return i;
    return -1;
}

ListNode* list_create_node(List *l, int data, int next, int *position)
{
    int free_pos = list_find_free_pos(l);
    ListNode *node =  list_get_node(l, free_pos);
    if (position)
        *position = free_pos;
    if (node) {
        node->data = data;
        node->next = next;
        node->occupied = 1;
    }
    return node;
}

List* list_new(int size)
{
    List* list = (List*)malloc(sizeof(List));
    if (list) {
        int i;
        list->nodes = (ListNode*)malloc(sizeof(ListNode)*size);
        if (!list->nodes) {
            free(list);
            return NULL;
        }
        for (i=0; i<size; i++)
            list->nodes[i].occupied = 0;
        list->head = -1;
        list->size = size;
        list->total = 0;
    }
    return list;
}

void list_free(List *l)
{
    free(l->nodes);
    free(l);
}

int list_is_empty(List* l)
{
    return l->head==-1;
}

int list_is_full(List* l)
{
    return l->total==l->size;
}


int list_push_front(List* l, int data)
{
    int pos;
    ListNode *node = list_create_node(l, data, l->head, &pos);
    if (!node)
        return 0;
    l->head = pos;
    ++l->total;
    return 1;
}

int list_insert_at(List *l, int pos, int data)
{
    ListNode *node;
    int i, position;
    int at = l->head, pat;

    if (pos==0)
        return list_push_front(l, data);

    for (i=0; i<pos; i++) {
        pat = at;
        at = list_get_node(l, at)->next;
        if (at<0 && i!=pos-1)
            return 0;
    }

    node = list_create_node(l, data, at, &position);
    if (node)
        list_get_node(l, pat)->next = position;
    ++l->total;
    return node!=NULL;
}

ListNode* list_get_tail(List *l)
{
    ListNode *node = list_get_head(l);
    if (!node)
        return NULL;
    while (node->next >= 0)
        node = list_get_next(l, node);
    ++l->total;
    return node;
}

int list_push_back(List *l, int data)
{
    ListNode *node;
    ListNode *last = list_get_tail(l);
    int pos;

    if (!last)
        return list_push_front(l, data);

    node = list_create_node(l, data, -1, &pos);
    if (!node)
        return 0;
    last->next = pos;
    ++l->total;
    return 1;
}

int list_pop_back(List* l)
{
    int last = l->head, last2 = -1;
    if (list_is_empty(l))
        return 0;
    while (list_get_node(l, last)->next>=0) {
        last2 = last;
        last = list_get_node(l, last)->next;
    }
    list_get_node(l, last)->occupied = 0;
    if (last2>=0)
        list_get_node(l, last2)->next = -1;
    else {
        list_get_head(l)->occupied = 0;
        l->head = -1;
    }
    --l->total;
    return 1;
}

int list_pop_front(List* l)
{
    int new_front;
    if (list_is_empty(l))
        return 0;
    new_front = list_get_head(l)->next;
    list_get_head(l)->occupied = 0;
    l->head = new_front;
    return 1;
}

int list_delete_at(List *l, int pos)
{
    int i;
    int at = l->head, pat;
    if (list_is_empty(l))
        return 0;

    if (pos==0)
        return list_pop_front(l);

    for (i=0; i<pos; i++) {
        pat = at;
        at = list_get_node(l, at)->next;
        if (!at && i!=pos-1)
            return 0;
    }
    list_get_node(l, pat)->next = list_get_node(l, at)->next;
    list_get_node(l, at)->occupied = 0;
    return 1;
}

void print_list(List *l)
{
    ListNode *node = list_get_head(l);
    printf("\n----\n");
    while (node)	{
        printf("%d    ", node->data);
        node = list_get_next(l, node);
    }
    printf("\n----\n\n");
}

int main()
{
    List *l = list_new(10);
    char choice = '\0';
    int pos, data;

    while (choice!='x') {
        printf("\nLinked List using Array\n--------------------------------");
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
