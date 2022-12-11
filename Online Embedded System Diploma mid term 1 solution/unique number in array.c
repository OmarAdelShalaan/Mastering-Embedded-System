#include<stdio.h>

int unique_num_in_arr(int arr[], int size)
{
	int arr_temp[100]={0};
	int i;
	for(i = 0; i < size; i++)
	{
		arr_temp[arr[i]]++;
	}
	for(i = 0; i < 100; i++)
	{
		if(arr_temp[i] == 1)
			return i ;
	}
}
int main()
{
	
	int arr[7]={4,2,5,2,5,7,4};
	//int arr[]={4,2,4};
	printf("%d ",unique_num_in_arr(arr,7));
	
	return 0;
}