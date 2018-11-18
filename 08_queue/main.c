#include <stdio.h>
#include <stdlib.h>
#include "ADT_queue.h"

int main() {
	
	QUEUE* q1;
	q1 = create_queue();
	
	if(q1 == NULL)	{
		printf("fail to create queue\n");
		return -1;
	}
	int a=10;
	int b=20;

	if(!enqueue(q1, &a)) {
		printf("fail to enqueue %d\n",a);
	} else {
		printf("success to enqueue %d\n",a);
}

	return 0;
}
