#include <stdio.h>

int main()
{
	int num;
	long sum = 0;
	int i;
	printf("Enter Num : ");
	scanf("%d",&num);
	for ( i = 0; i <= num; i++)
	{
		sum += i; 
	}
	printf("%d sum = %ld\n\n",num,sum);
	return 0;
}