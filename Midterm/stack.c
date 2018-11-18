#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	void* data_ptr;
	struct node* link;
} STACK_NODE;

typedef struct stack{
	int count;
	STACK_NODE* top;
} STACK;

STACK* create_stack(){
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	stack->count = 0;
	stack->top = NULL;
	return stack;
}

int push(STACK* stack,void* input){
	STACK_NODE* node =(STACK_NODE*)malloc(sizeof(STACK_NODE));
	if(!node)
		return 0;

	node->data_ptr=input;
	node->link=stack->top;
	stack->top=node;
	stack->count++;
	
	return 1;
}

int main(){
	STACK* s1 = create_stack();
	int a = 10;
	push(s1,&a);

	printf("%d\n",s1->count);
}









