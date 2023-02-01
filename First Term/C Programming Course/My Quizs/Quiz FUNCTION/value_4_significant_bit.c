#include<stdio.h>

int value_of_4_significant_bit( int num)
{
	return ( ( num & ( 1 << 3) ) >> 3 );
}

int main()
{
	int num;
	printf("Enter num: ");
	scanf("%d",&num);
	printf("bit 4 = %d",value_of_4_significant_bit(num));
	return 0;
}