#include <stdio.h>
/********************************
Swap Two Numbers
********************************/
void swap_temp(int *add_a,int *add_b);
int main()
{
	int a,b;
	printf("Enter value of a: ");
	scanf("%d",&a);
	printf("Enter value of b: ");
	scanf("%d",&b);
	printf("\n\n");
	swap_temp(&a,&b);
	printf("After swapping, value of a: %d\n",a);
	printf("After swapping, value of b: %d\n",b);
	printf("\n\n");
	return 0;
}

void swap_temp(int *add_a,int *add_b)
{
	int temp;
	printf("Swap with Temp\n");
	temp = *add_b;
	*add_b = *add_a;
	*add_a = temp;
}

