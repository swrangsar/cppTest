/* overwritable buffer version */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
} node;

typedef struct circBuffer {
    node *elems;
    int head;
    int tail;
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
    cb->elems = calloc(sz, sizeof(node));
    if (!cb->elems) {
        printf("ERROR: could not allocate array for the circ buffer!\n");
        exit(EXIT_FAILURE);
    }
    cb->head    = 0;
    cb->tail    = 0;
    cb->size    = sz;
    return cb;
}

int isEmpty(circBuffer *cb)
{
    return (cb->head == cb->tail);
}

int isFull(circBuffer *cb)
{
    node *pb = cb->elems;
    int h = cb->head;
    int t = cb->tail;
    return ((&pb[t] == &pb[(h+1)% cb->size])?1:0);
}

void push(circBuffer *cb, int data)
{    
    ((cb->elems)[cb->head]).data   = data;
    cb->head                    = (cb->head + 1) % cb->size;
    if (cb->head == cb->tail) {
        cb->tail = (cb->tail + 1) % cb->size;
    } 
    return;
}

int pop(circBuffer *cb)
{
    if (isEmpty(cb)) {
        printf("circ buffer is empty: cannot pop!\n");
        exit(EXIT_FAILURE);
    } else {
        int data        = ((cb->elems)[cb->tail]).data;
        ((cb->elems)[cb->tail]).data  = 0;
        cb->tail        = (cb->tail + 1) % cb->size;
        return data;
    }
}

void destroyCircBuffer(circBuffer *cb)
{
    if (cb) {
        free(cb->elems);
        free(cb);
        cb = NULL;
    }
}

void showCircBuffer(circBuffer *cb)
{
    if (!cb) return;
    node *it = cb->elems;
    if (!it) return;
    int i = 0, sz = cb->size;
    printf("Circ buf data:\n");
    while (i < sz) {
        printf("%2d: %d,\n", i, ((cb->elems)[i]).data );
        i++;
    }
    printf("head: %d ",((cb->elems)[(cb->head - 1 + sz) % sz]).data );
    printf("tail: %d \n", ((cb->elems)[cb->tail]).data );
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