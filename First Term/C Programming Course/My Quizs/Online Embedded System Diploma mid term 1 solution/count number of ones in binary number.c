#include<stdio.h>

int num_of_one_fun(int num)
{
	int count = 0;
	while(num != 0)
	{
		if((num & 1) == 1)
			count++;
		num = num >> 1;
	}
	return count;
}
int main()
{
	int num;
	printf("Enter your number: ");
	scanf("%d",&num);
	printf("num of ones: %d",num_of_one_fun(num));
	
	return 0;
}