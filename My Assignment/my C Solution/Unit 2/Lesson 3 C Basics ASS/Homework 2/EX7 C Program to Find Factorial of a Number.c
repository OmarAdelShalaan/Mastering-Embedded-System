#include <stdio.h>

int main()
{
	int num;
	unsigned long Factorial = 1;
	int i;
	printf("Enter Num : ");
	scanf("%d",&num);
	if( num < 0)
	{
		printf(" Error!!! Factorial of negative number doesn't exist\n\n");
		return 1;
	}
	for ( i = 1; i <= num; i++)
	{
		Factorial *= i; 
	}
	printf("%d Factorial = %ld\n\n",num,Factorial );
	return 0;
}