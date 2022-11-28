#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int len = 0,i = 0;
	printf("Enter a string: ");
	gets(str);
	while(str[i] != '\0')
	{
		len++;
		i++;
	}
	printf("Length of string: %d",len);
	return 0;
}