#include<stdio.h>
#include<string.h>
typedef struct Student{
	char name[20];
	int roll;
	float marks;
}Student;
int main()
{
	Student s1;
	strcpy(s1.name , "omar");
	s1.roll = 21;
	s1.marks = 334.5;
	printf("name: %s\nRoll: %d\nMarks: %.2f",s1.name,s1.roll,s1.marks);
	return 0;
}