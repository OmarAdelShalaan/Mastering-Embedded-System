#include <stdio.h>
/********************************
Swap Two Numbers
********************************/
void swap_with_temp(int *add_a,int *add_b);
void swap_without_temp(int *add_a,int *add_b);
int main()
{
	int a,b;
	printf("Enter value of a: ");
	scanf("%d",&a);
	printf("Enter value of b: ");
	scanf("%d",&b);
	printf("\n");
	swap_with_temp(&a,&b);
	printf("After swapping, value of a: %d\n",a);
	printf("After swapping, value of b: %d\n",b);
	printf("\n");
	printf("Now : a = %d \n",a);
	printf("Now : b = %d \n",b);
	printf("\n");
	swap_without_temp(&a,&b);
	printf("After swapping, value of a: %d\n",a);
	printf("After swapping, value of b: %d\n",b);
	printf("\n\n");
	return 0;
}

void swap_with_temp(int *add_a,int *add_b)
{
	int temp;
	printf("Swap with Temp Variable \n");
	temp = *add_b;
	*add_b = *add_a;
	*add_a = temp;
}
void swap_without_temp(int *add_a,int *add_b)
{
	printf("Swap without Temp Variable \n");
	*add_a += *add_b;
	*add_b = *add_a - *add_b;
	*add_a = *add_a - *add_b;
}


