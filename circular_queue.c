
/**
 * Circular Queue
 * Vishesh Yadav
 *
 */

#include<stdio.h>
#include<stdlib.h>


struct Queue {
    int *data;
    int  front;
    int  rear;
    int  length;
};

struct Queue* CreateQueue(int length) {
    struct Queue *nw = malloc( sizeof(struct Queue) );
    nw->data = malloc( sizeof(int) * length );
    nw->rear = 0;
    nw->front = 0;
    nw->length = length+1;
    return nw;
}

void FreeQueue(struct Queue *q)
{
    free(q->data);
    free(q);
}

int QueueEmpty(struct Queue *q)
{
    if ( q->front == q->rear )
        return 1;
    else
        return 0;
}

int QueueFull(struct Queue *q)
{
    if ( (q->rear+1)%q->length == q->front )
        return 1;
    else
        return 0;
}

int Enqueue(struct Queue *q, int data)
{
    if ( !QueueFull(q) ) {
        q->data[q->rear] = data;
        q->rear = (q->rear+1)%q->length;
        return 1;
    }
    return 0;
}

int Dequeue(struct Queue *q)
{
    if ( !QueueEmpty(q) ) {
        int ret = q->data[q->front];
        q->front = (q->front+1)%q->length;
        return ret;
    }
    return -1;
}

void PrintQueue(struct Queue *q)
{
    int i;
    for (i=q->front; i%q->length!=q->rear; i++)
        printf("%5d", q->data[i%q->length]);
    printf("\n");
}

int main()
{
    struct Queue *q = CreateQueue(4);
    char opt = ' ';

    printf("\n\nQUEUE IMPLEMENTATION USING ARRATY\n");

    while ( opt != 'x' ) {
        printf("  1. Enqueue\n");
        printf("  2. Dequeue\n");
        printf("  x. Exit\n\n");

        printf("\nWhat to do?\n");
        fflush(stdin);
        scanf("%c", &opt);

        if ( opt == '1' ) {
            int x;
            printf("\nEnter Data: ");
            scanf("%d", &x);
            Enqueue(q, x);
        } else if ( opt == '2' ) {
            printf("\nDequeued  ->  %d", Dequeue(q) );
        } else if ( opt == 'x' ) {
            break;
        }
        printf("\nQueue is now\n");
        PrintQueue(q);
    }
    FreeQueue(q);
    return 0;
}

