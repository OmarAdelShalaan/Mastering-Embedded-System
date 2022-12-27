#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	char _char;
	int i, len, fre = 0;
	printf("Enter a string: ");
	gets(str);
	len = strlen(str);
	printf("Enter a character to find frequency: ");
	scanf("%c",&_char);
	for (i = 0; i < len; i++)
	{
		if(str[i] == _char )
			fre++;
	}
	printf("Frequency of %c = %d",_char,fre);
	return 0;
}