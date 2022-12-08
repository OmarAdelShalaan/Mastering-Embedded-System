#include<stdio.h>

void revers_arr(int arr[], int size)
{
	int arr_temp[size];
	int i , j = 0;
	for(i = size - 1,j = 0; i >= 0; i--, j++)
	{
			arr_temp[j] = arr[i]; 
	}
	for(i = 0; i < size; i++ )
	{
		arr[i] = arr_temp[i];
	}
}
int main()
{
	int i ,size = 5;
	int arr[5]={1,2,3,4,5};
	revers_arr(arr,5);
	for( i = 0; i< size; i++)
		printf("%d ",arr[i]);
	
	return 0;
}