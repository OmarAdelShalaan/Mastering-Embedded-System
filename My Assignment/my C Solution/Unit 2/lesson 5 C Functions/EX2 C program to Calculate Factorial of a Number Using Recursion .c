#include<stdio.h>

int Factorial_Number(int num);
int main()
{
	int n;
	printf("Enter an positive integer: ");
	scanf("%d",&n);
	printf("Factorial of %d = %d",n,Factorial_Number(n));
	return 0;
}

int Factorial_Number(int num)
{
	if(num <= 1)
		return 1;
	return num * Factorial_Number(num-1);
}