#include<stdio.h>
#include<string.h>
void revers_word_in_string_fun(char str[])
{
	char str_temp[100];
	int i = 0, j = 0;
	while( str[i] != ' ' )
	{
		i++;
	}
	i++;
	while( str[i] != '\0' )
	{
		str_temp[j] = str[i];
		i++;
		j++;
	}
	str_temp[j] = ' ';
	i = 0;
	j++;
	while( str[i] != ' ' )
	{
		str_temp[j] = str[i];
		i++;
		j++;
	}
	str_temp[j] = '\0';
	i = 0;
	while( str_temp[i] != '\0' )
	{
		str[i] = str_temp[i];
		i++;
	}
}
int main()
{
	char str[] = "omar adel";
	revers_word_in_string_fun(str);
	puts(str);
	return 0;
}