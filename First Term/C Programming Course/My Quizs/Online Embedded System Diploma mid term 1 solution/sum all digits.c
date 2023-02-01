#include<stdio.h>

int sum_digit_fun(int num)
{
	int sum = 0;
	while(num != 0)
	{
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}
int main()
{
	int num;
	printf("Enter your number: ");
	scanf("%d",&num);
	printf("%d",sum_digit_fun(num));
	return 0;
}