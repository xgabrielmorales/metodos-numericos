#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
	/* === Define the fuction to use ===*/
	return cos(x) - x;
}

void Bisection(double a, double b, int n, double tol){
	double p;
	double f_de_a = f(a);
	double f_de_p;

	int i = 1;

	while (i <= n){
		p = a + (b - a) / 2;
		f_de_p = f(p);

		if (f_de_p == 0 || ((b-a)/2) < tol){
			printf("%f\n", p);
			exit(0);
		}

		if( (f_de_a * f_de_p) > 0 ){
			a = p;
			f_de_a = f_de_p;
		} else {
			b = p;
		}

		i++;
	}

	printf("Algo salio mal..\n");
	printf("Revisa tus datos de entrada\n");
}

int main(){
	/* === INSERT DATA HERE === */
	int n = 50;
	double a = 0, b = 5;
	double tol = pow(10, -6);

	/* === Calculate the bisection === */
	Bisection(a, b, n, tol);

	return 0;
}
