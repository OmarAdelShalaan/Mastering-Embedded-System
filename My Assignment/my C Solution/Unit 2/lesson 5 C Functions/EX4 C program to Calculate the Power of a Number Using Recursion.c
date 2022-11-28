#include<stdio.h>

int power_Number(int num,int power);
int main()
{
	int num, power;
	printf("Enter base number: ");
	scanf("%d",&num);
	printf("Enter power number (positive integer): ");
	scanf("%d",&power);
	printf("%d^%d = %d",num,power,power_Number(num,power));
	return 0;
}

int power_Number(int num,int power)
{	
	if( power == 1)
		return num;
	return num * power_Number(num,power - 1);
}