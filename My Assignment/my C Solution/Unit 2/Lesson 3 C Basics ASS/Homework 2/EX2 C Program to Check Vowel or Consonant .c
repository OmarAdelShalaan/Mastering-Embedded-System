#include <stdio.h>

int main()
{
	char _char;
	printf("Enter an alphabet: ");
	scanf("%c",&_char);
	if( _char == 'a' || _char == 'e' || _char == 'i' || _char == 'o' || _char == 'u' )
	{
		printf("%c is a vowel.  \n\n",_char);
	}
	else
	{
		printf("%c is consonant \n\n",_char);
	}
	return 0;
}