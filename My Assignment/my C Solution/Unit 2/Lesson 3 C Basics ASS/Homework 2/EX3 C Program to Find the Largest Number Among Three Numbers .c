#include <stdio.h>

int main()
{
	float a,b,c;
	printf("Enter 3 Num\n");
	printf("Enter Num 1 : ");
	scanf("%f",&a);
	printf("Enter Num 2 : ");
	scanf("%f",&b);
	printf("Enter Num 3 : ");
	scanf("%f",&c);
	printf("\n\n");
	a > b ? (a > c) ? printf("MAX Num : %0.2f",a): printf("MAX Num : %0.2f",c): b > c ? printf("MAX Num : %0.2f",b): printf("MAX Num : %0.2f",c);
	printf("\n\n");
	return 0;
}
