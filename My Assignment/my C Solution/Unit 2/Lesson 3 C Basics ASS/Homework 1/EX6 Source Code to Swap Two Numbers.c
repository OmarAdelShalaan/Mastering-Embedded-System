#include <stdio.h>
/********************************
Swap Two Numbers
********************************/
int main()
{
	float a,b,temp;
	printf("Enter value of a: ");
	scanf("%f",&a);
	printf("Enter value of b: ");
	scanf("%f",&b);
	temp = b;
	b = a;
	a = temp;
	printf("\n\n");
	printf("After swapping, value of a: %.2f\n",a);
	printf("After swapping, value of b: %.2f\n",b);
	return 0;
}