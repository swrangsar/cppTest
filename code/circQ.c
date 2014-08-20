#include <stdio.h>
#include <stdlib.h>



typedef struct node {
	int data;
} node;

typedef struct cirq {
	node *array;
	node *head;
	node *tail;
	int len;
}

cirq* makeCirq(int size)
{
	cirq* cp;
	cp = malloc(sizeOf(cirq));
	if (!cp) {
		printf("ERR: could not allocate memory for a cirq!\n");
		exit(EXIT_FAILURE);
	}

	cp->array = calloc(size, sizeOf(node));
	if (!cp->array) {
		printf("ERROR: could not allocate array for cirq!\n");
		exit(EXIT_FAILURE);
	}
	cp->head = cp->array;
	cp->tail = cp->array;
	cp->len = size;
	
	return cp;
}


void push(cirq *cq, node *nd)
{
	memmove(cq->head, nd, sizeOf(node));
	cq->head++;
	if ((cp->head - cp->array) > (cp->len * sizeOf(node))) {
		cp->head = cp->array;
	}
	return;
}

node* pop(cirq *cp)
{
	node* nd = cp->tail;
	cp->tail++;
	if ((cp->tail - cp->array) > (cp->len * sizeOf(node))) {
		cp->tail = cp->array;
	}
	return nd;
}