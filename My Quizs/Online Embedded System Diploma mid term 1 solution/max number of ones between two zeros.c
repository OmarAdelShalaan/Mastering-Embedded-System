#include<stdio.h>

int max_num_of_one_fun(int num)
{
	int count = 0;
	int max = 0;
	while(num != 0)
	{
		if((num & 1) == 1)
		{
			count++;
			num = num >> 1;
			while(num != 0)
			{
				if((num & 1) == 1)
				{
					count++;
				}
				else 
					break;
				num = num >> 1;
			}
			if(max < count)
				max = count;
		}
		count = 0;
		num = num >> 1;
	}
	return max;
}
int main()
{
	int num;
	printf("Enter your number: ");
	scanf("%d",&num);
	printf("max num of ones: %d",max_num_of_one_fun(num));
	
	return 0;
}