#include<stdio.h>

int revers_digit_fun(int num)
{
	int revers = 0;
	while(num != 0)
	{
		revers = revers * 10 + (num % 10);
		num /= 10;
	}
	return revers;
}
int main()
{
	int num;
	printf("Enter your number: ");
	scanf("%d",&num);
	printf("%d",revers_digit_fun(num));
	return 0;
}