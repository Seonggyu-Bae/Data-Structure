#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	void* data_ptr;
	struct node* next;
} QUEUE_NODE;

typedef struct {
	int count;
	QUEUE_NODE* front;
	QUEUE_NODE* rear;
} QUEUE;

QUEUE* create_queue();
bool enqueue (QUEUE* queue, void* in);
void* dequeue (QUEUE* queue); //data_ptr return...


