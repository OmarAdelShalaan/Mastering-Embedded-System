#include <stdio.h>

int main()
{
	char _char;
	printf("Enter char : ");
	scanf("%c",&_char);
	if ( ( _char >= 'a' && _char < 'z' ) || ( _char >= 'A' && _char < 'Z' ) )
	{
		printf("%c  is an alphabet\n\n",_char);
	}
	else	
		printf("%c  is not an alphabet\n\n",_char);
	return 0;
}