#include<stdio.h>

#define circle_area(r) (r*(22.0/7)*(22.0/7))

int main()
{
	float radius;
	printf("Enter the radius: ");
	scanf("%f", &radius);
	printf("Area = %0.2f", circle_area(radius));
	return 0;
}