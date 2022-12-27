#include<stdio.h>

int swap_with_shift(int num)
{
	num = ((num & 0x0F) << 4) | ((num & 0xF0) >> 4);
	return num;
}

int main()
{
	int num;
	printf("Enter num: ");
	scanf("%x",&num);
	printf("%x",swap_with_shift(num));
	return 0;
}