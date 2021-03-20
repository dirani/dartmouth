#include <stdio.h>
#include <math.h>

int main(){
	int aninteger;
	double asqrt;
 	double euler;
/*	double a_command; */

	scanf("%d", &aninteger);
	asqrt = sqrt(aninteger);
	printf("%0.8lf\n", asqrt);

	euler = exp(1);
	printf("%0.10lf\n", euler);

	printf("gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.c -lm -o program\n");
}
