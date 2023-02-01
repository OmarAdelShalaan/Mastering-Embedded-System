#include<stdio.h>

int check_power_3( int num)
{
	while( num != 1)
	{
		if(num % 3 != 0)
		{
			return 1;
		}
		num /= 3;
	}
	return 0;
}

int main()
{
	int num;
	printf("Input number: ");
	scanf("%d",&num);
	printf("output: %d",check_power_3(num));
	
	return 0;
}