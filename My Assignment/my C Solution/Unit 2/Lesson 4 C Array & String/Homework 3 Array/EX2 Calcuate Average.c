#include<stdio.h>

int main()
{
	float arr[100], sum = 0;
	int n, i;
	printf("Enter the number of data: ");
	scanf("%d",&n);
	for(i = 0; i < n ; i++)
	{
		printf("%d. Enter Number: ", i + 1);
		scanf("%f",&arr[i]);
		sum += arr[i];
	}
	printf("Average = %0.2f",sum / n);
	return 0;
}
