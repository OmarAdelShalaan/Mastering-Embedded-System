#include<stdio.h>
#include<string.h>
int lenstr(char *str);
int main()
{
	char str[100];
	char str_temp[100];
	int i = 0, len = 0;
	printf("Enter a string: ");
	gets(str);
	len = lenstr(str);
	while(str[i] != '\0')
	{
		str_temp[len - 1 -i] = str[i];
		i++;
	}
	str_temp[i] = '\0';
	puts(str_temp);
	return 0;
}

int lenstr(char *str)
{
	int len = 0,i = 0;
	while(str[i] != '\0')
	{
		len++;
		i++;
	}
	return len;
}