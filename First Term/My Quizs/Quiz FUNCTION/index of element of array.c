#include<stdio.h>

int index_element_in_arr(int *arr, int size, int num)
{
	int i;
	for( i = 0; i < size; i++)
		if( i[arr] == num)
			return i;
	return -1;	
}
int main()
{
	int size = 5;
	int arr[5];
	int i, num;
	for( i = 0; i < size; i++)
	{
		printf("index_%d: ", i + 1);
		scanf("%d",&arr[i]);
	}
	printf("input number: ");
	scanf("%d",&num);
	printf("index of element: %d",index_element_in_arr( arr, size, num));
	
	return 0;
}