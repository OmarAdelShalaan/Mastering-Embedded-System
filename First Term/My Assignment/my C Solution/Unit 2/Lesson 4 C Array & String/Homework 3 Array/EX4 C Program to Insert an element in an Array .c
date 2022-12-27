#include<stdio.h>

int main()
{
	int n, i, j, arr[100], arr_temp[100];
	int inserted_num,location;
	printf("Enter no of elements : ");
	scanf("%d",&n);
	for(i = 0; i < n ; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be inserted : ");
	scanf("%d",&inserted_num);
	printf("Enter the location: ");
	scanf("%d",&location);
	for(i = 0, j = 0; i < n + 1 ; i++, j++)
	{
		if( i == location)
		{
			arr_temp [i] = inserted_num;
			j--;
			continue;
		}
		arr_temp[i] = arr[j];
	}
	for(i = 0; i < n + 1 ; i++)
	{
		printf("%d ", arr_temp [i]);
	}
		
	return 0;

}
	