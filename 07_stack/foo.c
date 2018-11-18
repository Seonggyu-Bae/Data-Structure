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
void* pop(STACK* stack); //make! homework

int main(){
	STACK* s1 = create_stack();	
	printf("stack s1's size: %d\n",s1->count);	
	int a = 10;
	int b = 12;
	push(s1,&a);
	push(s1,&b);
	printf("stack s1's size: %d\n",s1->count);


	STACK*stack_ptr;
	stack_ptr = create_stack();
	int i,k;
	i=100;
	if(!push(stack_ptr,&i)){
		printf("oops");
		return -1;
	}	
	k=200;	
	if(!push(stack_ptr,&k)){
		printf("oops");
		return -1;
	}
	int* temp;
	temp = (int*) pop(stack_ptr);
	printf("pop: %d\n", *temp);
	
}
STACK* create_stack(){
	printf("creating a stack \n");
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	if( !stack )
		return 0;
	stack->count = 0;
	stack->top = 0;	
	return stack;     //return
	
}
int push(STACK* stack, void* in){
	printf("Pushing a data into stack...\n");
	STACK_NODE* node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if( !node )
		return 0;
	
	node->data_ptr = in;
	node->link = stack->top; //my next become old boss;
	stack->top = node; //I am a new boss
	stack->count++;
	
	return 1;
}	

void* pop(STACK* stack) {
	if(stack->count==0)
		return 0;
	else{
		STACK_NODE*temp = stack->top;
		void* data_out = stack->top->data_ptr;
		stack->top = stack->top->link;
		free(temp);
		(stack->count)--;
		return data_out;
}


}

