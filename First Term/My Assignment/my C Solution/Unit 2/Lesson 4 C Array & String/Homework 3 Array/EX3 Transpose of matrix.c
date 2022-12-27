#include<stdio.h>

int main()
{
	int arr[10][10];
	int row, colum, i, j;
	printf("Enter rows and column  of matrix: ");
	scanf("%d%d",&row,&colum);
	printf("Enter elements of matrix: \n");
	for(i = 0; i < row ; i++)
	{
		for(j = 0; j < colum ; j++)
		{
			printf("Enter elements a%d%d: ", i + 1, j + 1);
			scanf("%d",&arr[i][j]);
		}
	}
	printf("Entered matrix: \n");
	for(i = 0; i < row ; i++)
	{
		for(j = 0; j < colum ; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("Transpose of matrix: \n");
	for(j = 0; j < colum ; j++)
	{
		for(i = 0; i < row ; i++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}