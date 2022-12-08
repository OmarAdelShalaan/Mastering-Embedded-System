#include <stdio.h>

int main()
{
	char _char;
	float num1,num2;
	printf("Enter operator either + or - or * or divide : ");
	scanf("%c",&_char);
	printf("Enter Num 1 : ");
	scanf("%f",&num1);
	printf("Enter Num 2 : ");
	scanf("%f",&num2);
	switch(_char)
	{
		case '+':
			printf("%0.2f %c %0.2f = %0.2f", num1, _char, num2, num1 + num2 );
			break;
		case '-':
			printf("%0.2f %c %0.2f = %0.2f", num1, _char, num2, num1 - num2 );
			break;
		case '*':
			printf("%0.2f %c %0.2f = %0.2f", num1, _char, num2, num1 * num2 );
			break;
		case '/':
			printf("%0.2f %c %0.2f = %0.2f", num1, _char, num2, num1 / num2 );
			break;
	}
	printf("\n\n");
	return 0;
}