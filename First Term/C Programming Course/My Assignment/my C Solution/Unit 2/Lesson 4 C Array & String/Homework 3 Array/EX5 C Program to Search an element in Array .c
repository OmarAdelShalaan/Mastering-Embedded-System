#include<stdio.h>

int main()
{
	int n, i, arr[100];
	int searched_num,location;
	printf("Enter no of elements : ");
	scanf("%d",&n);
	for(i = 0; i < n ; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the elements to be searched : ");
	scanf("%d",&searched_num);
	printf("Number found at the location = ");
	for(i = 0; i < n  ; i++)
	{
		if( searched_num == arr[i])
			printf("%d", i + 1);
	}
		
	return 0;

}
	