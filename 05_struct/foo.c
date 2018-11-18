#include <stdio.h>

struct student {
	char name[20];
	int age;
	int score;
	struct student* friend;
};

typedef struct student std;


int main(){
	
	struct student s1 = {"Bae",23,80};
	std	       s2 = {"Heo",24,90};	
	
	s1.friend = &s2;
	s2.friend = &s1;


	std* f = s1.friend; //it needed

	printf("Student name: %s\n",s1.name);
	printf("Student age : %d\n",s1.age);
	printf("Student score : %d\n",s1.score);
	printf("friend name : %s\n",s1.friend->name);
	printf("friend name : %s\n",(*(std*)f).name); //dirty code

	printf("Student name: %s\n",s2.name);
	printf("Student age : %d\n",s2.age);
	printf("Student score : %d\n",s2.score);



	return 0;

}
