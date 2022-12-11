#include<stdio.h>
#include<string.h>
typedef struct Complex{
	float real;
	float imagin;
}Complex;
void add_print(Complex num_1, Complex num_2)
{
	printf("sum = %.1f + %.1fi", num_1.real + num_2.real, num_1.imagin + num_2.imagin);
}
int main()
{
	Complex num_1, num_2;
	printf("Enter real and imaginary respectively: ");
	scanf("%f%f", &num_1.real, &num_1.imagin);
	printf("Enter real and imaginary respectively: ");
	scanf("%f%f", &num_2.real, &num_2.imagin);
	add_print( num_1, num_2);
	return 0;
}