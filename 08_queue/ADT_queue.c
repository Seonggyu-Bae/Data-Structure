#include "ADT_queue.h"

QUEUE* create_queue() {
	QUEUE* queue;
	queue = (QUEUE*)malloc(sizeof(QUEUE));

	if(queue) {
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;
		return queue;
	} else {
		return NULL;
	}
}

bool
enqueue (
	QUEUE* queue, //target queue 
	void* in      //data	
) {
	QUEUE_NODE* new_node;
	new_node =(QUEUE_NODE*) malloc(sizeof(QUEUE_NODE));
	if(!new_node)
		return false;

	new_node->data_ptr = in;
	new_node->next= NULL;
	
	if(queue->count == 0){
		queue->front = new_node;
	} else{
		queue->rear->next = new_node;
	}
	
	queue->rear = new_node;
	queue->count++;
	return true;
}

