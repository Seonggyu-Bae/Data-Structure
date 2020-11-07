# Linked List 

**STACK과 QUEUE는 원하는곳에 데이터를 쓰고, 지우고를 하기에는 너무 귀찮기 때문에 Linked List를 써보자**

# Linked List Architecture
![architecture](https://postfiles.pstatic.net/MjAyMDExMDdfODcg/MDAxNjA0NzIwMzY1MjEw.QgbQ4f95Sbtvr8111Y3VJ5oOnKa7pYMrKS1MIDNKB0Eg.NQ-HT_Ng3NazY7uyGqlDqmxLPAUoOFZfv_D2Emn9mhog.PNG.qotjdrb6/image.png?type=w773)

# Insertion
![architecture](https://postfiles.pstatic.net/MjAyMDExMDdfNzIg/MDAxNjA0NzIwMTQxMzk0.2225DQAhj6jvLb6VetryaUUoxYAzYvANvhaVY-syilMg.-oKlUzj5e7cZbgMm7DTys2ymntEeqFCkE0ftRwvt6Rkg.PNG.qotjdrb6/image.png?type=w773)

**원하는 곳에 데이터 삽입가능**

# Deletion
![architecture](https://postfiles.pstatic.net/MjAyMDExMDdfMjE1/MDAxNjA0NzIwMjY5NjU0.0GYKo8r8o_R4K7YzpKK7YGY69jh9PUe8iGBLXkdknEwg.hvQHOfBebsbS7CKbtDweJ1s5r5DdPNE_7wzCpZC1_iYg.PNG.qotjdrb6/image.png?type=w773)

**원하는 곳의 데이터 삭제가능**

# Retrieval
![architecture](https://postfiles.pstatic.net/MjAyMDExMDdfMTg3/MDAxNjA0NzIwMjk4ODI4.kcw3ewtkprMeAEiaAXwKMqqG97TkawcIcfzmCd2QzCIg.eej8J18hP0F5Doa3GRDZbxooSnHHanfF6LvPwPd-S4og.PNG.qotjdrb6/image.png?type=w773)

**원하는 곳의 데이터 검색가능**

# 코드

**리스트 생성**

```sh
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
```

**원하는 곳에 데이터 삽입**
```sh

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
```

**원하는 곳의 데이터 삭제**

```sh
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
```
