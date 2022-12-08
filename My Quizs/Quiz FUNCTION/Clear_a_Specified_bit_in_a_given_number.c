#include<stdio.h>

int clear_specified_bit(int num, int position)
{
	num = num & (~( 1 << position ));
	return num;
}

int main()
{
	int num, position;
	printf("Input Number: ");
	scanf("%d",&num);
	printf("Bit position: ");
	scanf("%d",&position);
	printf("%d",clear_specified_bit(num, position));
	return 0;
}