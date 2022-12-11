#include<stdio.h>

int prime_num_fun(int num)
{
	if(num == 2 || num == 3 || num == 5 )
		return 1;
	if( num % 2 == 0)
		return -1;
	else if( num % 3 == 0)
		return -1;
	else if( num % 5 == 0)
		return -1;
	return 1;
}
int main()
{
	int num_1, num_2, i;
	printf("Enter your number 1: ");
	scanf("%d",&num_1);
	printf("Enter your number 2: ");
	scanf("%d",&num_2);
	for( i = num_1; i <= num_2; i++ )
	{
		if( prime_num_fun(i) == 1)
			printf("%d ", i);
	}
	return 0;
}