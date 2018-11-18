#include "ADT_list.h"

LLIST* create_list() {
	LLIST* list;
	list = (LLIST*)malloc(sizeof(LLIST));

	if(list) {
		list->front = NULL;
		list->rear  = NULL;
		list->pos   = NULL;
		list->count = 0;
		return list;
	} else {
		return NULL;
	}
}

bool
add_node_at (
	LLIST*		 list,
	unsigned int index,
	void*		 data
) {
	if( (list->count) < index )
		return false;

	NODE* new_p = (NODE*)malloc(sizeof(NODE));
	if(!new_p ){
		printf("fail to malloc \n");
		return false;
	}
	new_p->data_ptr	= data;
	new_p->next	= NULL;

	if(list->count==0) {
		list->front = new_p;
		list->rear  = new_p;
		(list->count)++;
		return true;
	}	
	
	int iter_i=0;
	if(index == 0) {
		new_p->next = list->front;
		list->front = new_p;
		(list->count)++;
		return true;
	}
	iter_i++;
	list->pos = list->front; //start from front
	while(iter_i != index) {
		list->pos = list->pos->next;
		iter_i++;
	}
	if(iter_i == list->count) {
		list->pos->next = new_p;
		list->rear = new_p;
		(list->count)++;
		return true;
	}

	else{
		new_p->next = list->pos->next;
		list->pos->next = new_p;
		(list->count)++;
		return true;
	}
}
bool
del_node_at (
	LLIST* list,
	unsigned int index
) {
	if(list->count==0)
		return false;
	else if(index>= list->count)
		return false;

	if(list->count==1){
		free(list->front);
		list->front = NULL;
		list->rear  = NULL;
		list->count = 0;
		return true;
	}

	int iter_i=0;
	list->pos = list->front;
	NODE*pre  = NULL;
	while(iter_i != index){
		pre = list->pos;
		list->pos = list->pos->next;
		iter_i++;
	}
	
	if(index==0){
		list->front = list->pos->next;
		free(list->pos);
		list->pos=NULL;
		(list->count)--;
		return true;
	}	

	if(index == (list->count-1)){
		list->rear = pre;
		pre->next  = NULL;
		free(list->pos);
		list->pos  = NULL;
		(list->count)--;
		return true;
	}

	else{
		pre->next = list->pos->next;
		free(list->pos);
		list->pos = NULL;
		(list->count)--;
		return true;
	}

	return false;
}	
