#include<stdio.h>
#include<string.h>
typedef struct Student{
	char name[20];
	int roll;
	int marks;
}Student;
int main()
{
	Student student_arr[10];
	int i = 0;
	printf("Enter information of students: \n");
	for( i = 0; i < 10; i++)
	{
		printf("For roll number %d \n", i + 1);
		student_arr[i].roll = i + 1;
		printf("Enter Name: ");
		scanf("%s", student_arr[i].name);
		printf("Enter marks: ");
		scanf("%d", &student_arr[i].marks);
	}
	for( i = 0; i < 10; i++)
	{
		printf("Roll: %d\nname: %s\nMarks: %d\n\n",\
		student_arr[i].roll, student_arr[i].name,  student_arr[i].marks);
	}
	
	return 0;
}