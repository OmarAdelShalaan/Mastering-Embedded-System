#include<stdio.h>

int main()
{
	float a[2][2],b[2][2];
	int i = 0, j = 0;
	printf("Enter the elements of 1st matrix\n");
	for(i = 0; i < 2 ; i++)
	{
		for( j = 0; j < 2; j++)
		{
			printf("Enter a%d%d: ",i + 1,j + 1);
			scanf("%f",&a[i][j]);
		}
	}
	printf("Enter the elements of 2st matrix\n");
	for(i = 0; i < 2 ; i++)
	{
		for( j = 0; j < 2; j++)
		{
			printf("Enter b%d%d: ",i + 1,j + 1);
			scanf("%f",&b[i][j]);
		}
	}
	printf("Sum of Matrix\n");
	for(i = 0; i < 2 ; i++)
	{
		for( j = 0; j < 2; j++)
		{
			printf("%0.1f    ",a[i][j] + b[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}