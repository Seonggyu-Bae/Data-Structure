#include <stdio.h>

int main(){
	int a , b;
	a  =100;
	b = 200;	
	
	printf("Variable a : %d at address %p\n",a,&a);
	printf("Variable b : %d at address %p\n",b,&b);
	
	
	int*  a_address;
	// int *a_address;
	a_address = &a;
	
	*a_address = 300;

	printf("Variable a(%d) can be referenced via pointer \n",*a_address);
	


	
	
	
	
	return 0;

}
