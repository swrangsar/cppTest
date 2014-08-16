#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
} node;

typedef struct circBuffer {
    node *begin;
    node *head;
    node *tail;
    int size;
} circBuffer;

circBuffer *makeCircBuffer(int size)
{
    circBuffer *cb;
    cb = malloc(sizeof(circBuffer));
    int sz = size+1;
    if (!cb) {
        printf("ERROR: could not allocate for a circ buffer!\n");
        exit(EXIT_FAILURE);
    }
    cb->begin = calloc(sz, sizeof(node));
    if (!cb->begin) {
        printf("ERROR: could not allocate array for the circ buffer!\n");
        exit(EXIT_FAILURE);
    }
    cb->head    = cb->begin;
    cb->tail    = cb->begin;
    cb->size    = sz;
    return cb;
}

int isEmpty(circBuffer *cb)
{
    return (cb->head == cb->tail);
}

int isFull(circBuffer *cb)
{
    node *ph = cb->head;
    node *pt = cb->tail;
    node *pb = cb->begin;
    return (pt-pb) == ((ph - pb + 1)%(cb->size))?1:0;
}

void push(circBuffer *cb, int data)
{
    if (isFull(cb)) {
        printf("circ buffer is already full: cannot push\n");
        return;
    } else {
        cb->head->data  = data;
        cb->head        = &(cb->begin)[(cb->head - cb->begin + 1)% cb->size];
        return;
    }
}

int pop(circBuffer *cb)
{
    if (isEmpty(cb)) {
        printf("circ buffer is empty: cannot pop!\n");
        exit(EXIT_FAILURE);
    } else {
        int data        = cb->tail->data;
        cb->tail->data  = 0;
        cb->tail        = &(cb->begin)[(cb->tail - cb->begin +1) % cb->size];
        return data;
    }
}

void destroyCircBuffer(circBuffer *cb)
{
    if (cb) {
        free(cb->begin);
        free(cb);
        cb = NULL;
    }
}

void showCircBuffer(circBuffer *cb)
{
    if (!cb) return;
    node *it = cb->begin;
    if (!it) return;
    int i = 0, sz = cb->size;
    printf("Circ buf data:\n");
    while (i < sz) {
        printf("%2d: %d,\n", i, ((cb->begin)[i]).data );
        i++;
    }
    printf("head: %d ",((cb->begin)[(cb->head - cb->begin - 1 + sz) % sz]).data);
    printf("tail: %d \n", cb->tail->data);
    printf("end of circ buf data.\n");
    return;
}

int main(int argc, const char *argv[])
{
    int i = 0, size = 10;
    circBuffer *cb = makeCircBuffer(size);
    
    if (cb) {
        printf("Circ buffer of size %d has been allocated.\n", size);
    }
    if (isEmpty(cb)) {
        printf("Circular buffer is empty.\n");
    }
    showCircBuffer(cb);
    
    for (i=0; i < 11; i++) {
        int sq = (i+1)*(i+1);
        printf("%d is being pushed to circ buffer\n", sq);
        push(cb, sq);
    }
    
    
    if (isFull(cb)) {
        printf("Circular buffer is FULL!\n");
    }
    showCircBuffer(cb);
      
    for (i=0; i < size-3; i++) {
        int n = pop(cb);
        printf("%d was popped from circ buffer\n", n);
    }
    showCircBuffer(cb);
    
    
    for (i=11; i <20 ; i++) {
        int db = (i+1)*2;
        printf("%d is being pushed to circ buffer\n", db);
        push(cb, db);
    }
    
    if (isFull(cb)) {
        printf("Circular buffer is FULL!\n");
    }
    
    showCircBuffer(cb);
    
    for (i=0; i < size-5; i++) {
        int n = pop(cb);
        printf("%d was popped from circ buffer\n", n);
    }
    
    showCircBuffer(cb);
    
    destroyCircBuffer(cb);
    return 0;
}