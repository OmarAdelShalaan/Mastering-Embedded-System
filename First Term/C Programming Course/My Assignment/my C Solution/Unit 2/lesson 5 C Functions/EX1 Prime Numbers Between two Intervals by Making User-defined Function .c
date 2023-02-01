#include<stdio.h>

int prime_num(int num);
int main()
{
	int num_1,num_2;
	printf("Enter two numbers (intervals): ");
	scanf("%d%d",&num_1,&num_2);
	printf("Prime numbers between %d and %d are: ",num_1,num_2);
	for( ; num_1 < num_2; num_1++ )
	{
		if(prime_num(num_1) == 1)
			printf("%d ",num_1);
	}
	return 0;
}

int prime_num(int num)
{
	if(num % 2 == 0)
		return -1;
	else if(num % 3 == 0)
		return -1;
	else if(num % 5 == 0)
		return -1;
	return 1;
}