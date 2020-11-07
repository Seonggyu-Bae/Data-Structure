# STACK Architecture

![architecture](https://postfiles.pstatic.net/MjAyMDExMDdfMjcz/MDAxNjA0Njc3OTg1NzU3.nqOUPdt5eCURmT3T7PxvqRKB4q_eix2HeKmJXvJs_DUg.45WHswSDBlnQfCDL32Of1WAqNOVnCkTK-w9ZL3Cnq2kg.PNG.qotjdrb6/image.png?type=w773)

# STACK_NODE 정의
```sh

typedef struct node {
	void* data_ptr;
	struct node* link;
} STACK_NODE;

```
# STACK 정의 
```sh
typedef struct stack {
	int count;
	STACK_NODE* top;
} STACK;

```

# STACK 만들기
```sh
STACK* create_stack(){
	printf("creating a stack \n");
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	if( !stack )
		return 0;
	stack->count = 0;
	stack->top = 0;	
	return stack;     //return
	
}
```

# STACK NODE를 STACK으로 넣기
```sh
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
```

# STACK NODE를 STACK에서 빼기
```sh
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
```
