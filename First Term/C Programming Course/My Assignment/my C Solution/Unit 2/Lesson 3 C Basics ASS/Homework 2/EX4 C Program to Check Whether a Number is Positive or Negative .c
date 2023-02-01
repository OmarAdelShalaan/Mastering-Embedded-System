#include <stdio.h>

int main()
{
	float a;
	printf("Enter Num : ");
	scanf("%f",&a);
	printf("\n\n");
	if ( a > 0)
		printf("%0.2f num is postive",a);
	else if ( a < 0)
		printf("%0.2f num is negtive",a);
	else 
		printf("You entered zero");
	printf("\n\n");
	return 0;
}
