#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double Bisection(double a, double b, int n, double tol){
	double p;
	double f_de_a = f(a);
	double f_de_p;

	int i = 1;
	while (i <= n){
		p = a + (b - a) / 2;
		f_de_p = f(p);

		if (f_de_p == 0 || ((b-a)/2) < tol)
			return p;

		if( (f_de_a * f_de_p) > 0 ){
			a = p;
			f_de_a = f_de_p;
		} else {
			b = p;
		}

		i++;
	}
	printf("The method failed after %d iterations.\n", n);
}

int main(){
	/* === INSERT DATA HERE === */
	int n;
	double a;
	double b;
	double tol;

	/* === CALCULATE THE BISECTION === */
	double r = Bisection(a, b, n, tol);
	printf("%lf\n", r);

	return 0;
}
