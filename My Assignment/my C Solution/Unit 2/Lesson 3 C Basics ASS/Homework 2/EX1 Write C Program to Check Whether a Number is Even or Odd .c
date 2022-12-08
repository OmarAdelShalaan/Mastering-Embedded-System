#include <stdio.h>

int main()
{
	int num;
	printf(" Enter an integer you want to check: ");
	scanf("%d",&num);
	if( num % 2 == 0)
	{
		printf("%d is even \n\n",num);
	}
	else
	{
		printf("%d is odd \n\n",num);
	}
	return 0;
}