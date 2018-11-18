#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	void* data_ptr;
	struct node* link;
} STACK_NODE;

typedef struct stack {
	int count;
	STACK_NODE* top;
} STACK;

STACK* create_stack();
int push(STACK* stack, void* in);
void* pop(STACK* stack);
void print(STACK* stack);
STACK* Merge(STACK* stack1,STACK* stack2);
int main(){
	STACK* s1 = create_stack();
	STACK* s2 = create_stack();
	int a0 = 0;
	int a1 = 1;
	int a2 = 2;
	int a3 = 3;
	int a4 = 4;
	int b0 = 5;
	int b1 = 6;
	int b2 = 7;
 	int b3 = 8;
	int b4 = 9;

	push(s1,&a0);
	push(s1,&a1);
	push(s1,&a2);
	push(s1,&a3);
	push(s1,&a4);
	push(s2,&b0);
	push(s2,&b1);
	push(s2,&b2);
	push(s2,&b3);
	push(s2,&b4);

	print(Merge(s1,s2));
}

STACK* create_stack(){
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	if(!stack)
		return 0;
	stack-> count =0;
	stack -> top =0;
	return stack;
}

int push(STACK* stack, void* in){
	STACK_NODE* node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if(!node)
		return 0;
	node->data_ptr = in;
	node->link = stack->top;
	stack->top = node;
	stack->count++;
	return 1;
}

void* pop(STACK* stack){
	if(stack->count==0)
		return 0;
	else{
		STACK_NODE*temp = stack -> top;
		void* data_out = stack->top->data_ptr;
		stack->top = stack->top->link;
		free(temp);
		(stack->count)--;
		return data_out;
	}	
}

void print(STACK* stack){
	STACK_NODE* p1 = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	p1 = stack->top;
	
	while(p1!=NULL){
		printf("%d\n",*(int*)(p1->data_ptr));
		p1=p1->link;
	}
}	
	


STACK* Merge(STACK* stack1,STACK* stack2){
	STACK* n_stack1 = (STACK*)malloc(sizeof(STACK));
	STACK* n_stack2 = (STACK*)malloc(sizeof(STACK));
	STACK* n_stack3 = (STACK*)malloc(sizeof(STACK));
	
	while(stack1->count!=0){
		push(n_stack1,pop(stack1));
	}
	while(stack2->count!=0){
		push(n_stack2,pop(stack2));
	}
	while(n_stack1->count!=0){
		push(n_stack3,pop(n_stack1));
	}
	while(n_stack2->count!=0){
		push(n_stack3,pop(n_stack2));
	}
	return n_stack3;
}

	
