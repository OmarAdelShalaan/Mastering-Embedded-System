#include<stdio.h>

int sum_1_to_num(int num)
{
	return (num * (num + 1 ) / 2) ;
}
int main()
{
	int num;
	printf("Enter your number: ");
	scanf("%d",&num);
	printf("sum 1 to num : %d",sum_1_to_num(num));
	
	return 0;
}