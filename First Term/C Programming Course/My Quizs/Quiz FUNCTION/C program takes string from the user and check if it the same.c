#include<stdio.h>

char name_str[] = "omar adel shalaan";
int compare_str(char *str)
{
	int i = 0;
	while( i[name_str] != '\0' )
	{
		if( i[str] != name_str[i])
			return 1;
		++i;
	}
	return 0;
}

int main()
{
	char name[50];
	printf("Input name: ");
	gets(name);
	if(!(compare_str(name)))
		printf("True");
	else 
		printf("False");
	return 0;
}