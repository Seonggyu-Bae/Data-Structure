# Queue

**Queue Architecture**

![architecture](https://postfiles.pstatic.net/MjAyMDExMDdfNzYg/MDAxNjA0NzE4NjU3NTU4.y2ffGxn8TAeWK0FICZa_Hyu2Kt6oSuVYOdcD76HDd-Qg.vWAgEYt-GsL3h4eoqXmP1TcBoEeQQINWvhWlThpzCwAg.PNG.qotjdrb6/image.png?type=w773)


# enqueue, dequeue mechanism

![architecture](https://postfiles.pstatic.net/MjAyMDExMDdfMjIz/MDAxNjA0NzE4NjkzMzcy.A6AWMM6RRcEGO7CSrrPR-qNJaiQchTJjDIr-VRVV8bAg.nouSyM0o5lqeE703u-wMMg0pD6lUdslpCDg5piOC2Vsg.PNG.qotjdrb6/image.png?type=w773)



# data 는 pointer로 빼올수 있다

![architecture](https://postfiles.pstatic.net/MjAyMDExMDdfMjky/MDAxNjA0NzE4NzgxMTA1.vodXTRARZMkmoazuzlFbKlob_3Tw-pAWRIm3HDCgsX4g.-gKsd7ct8L6BGKS04F0j1UlAFEKqyJh7TfkHxHiMCIgg.PNG.qotjdrb6/image.png?type=w773)


# Queue 생성

```sh
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
```

# enqueue

```sh
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
```
