#include <stdio.h>
#include "increment.h"
int main(){
	int a;
	int b;
	int data[10] = {10,20,30,40,50,60,70,80,90,100};
	float data_f[10] = {10.1,20.1,30.1,40.1,50.1,60.1,70.1,80.1,90.1,100.1};
	a = 10;
	
	printf("a is %d\n",a);
	
	a = increment(a);
	printf("a is %d\n",a);
	
	printf("Enter b: ");
	scanf("%d",&b);
	b = increment(b);
	printf("b is %d\n",b);
	
	int i;
	for(i=0; i<10; i++) {
	printf("data[%d} is %d\n", i , data[i]);
	}
	for(i=0; i<10; i++) {
	printf("data_f[%d} is %.2f\n", i , data_f[i]);
	}

	
	return 0;
}

