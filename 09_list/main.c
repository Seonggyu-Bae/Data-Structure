#include <stdio.h>
#include <stdlib.h>
#include "ADT_list.h"

int main() {
	
	LLIST* q1;
	q1 = create_list();
	
	if(q1 == NULL)	{
		printf("fail to create list\n");
		return -1;
	}

	return 0;
}
