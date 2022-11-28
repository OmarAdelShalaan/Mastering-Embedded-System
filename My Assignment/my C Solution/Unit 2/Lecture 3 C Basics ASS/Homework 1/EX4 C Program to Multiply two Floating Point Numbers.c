#include <stdio.h>

int main()
{
	float user_int_1 = 0;
	float user_int_2 = 0;
	printf("Enter Two Float Num ");
	printf("Num 1 : ");
	scanf("%f",&user_int_1);
	printf("Num 2 : ");
	scanf("%f",&user_int_2);
	printf("Mul : %6f\n",user_int_1 * user_int_2);
	return 0;
}