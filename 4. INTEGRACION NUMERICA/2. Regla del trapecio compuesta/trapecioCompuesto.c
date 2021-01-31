#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double trapecioCompuesto(double a, double b, int n){
	double h = (b - a)/n;
	double X, XI1, XI0 = f(a) + f(b);

	for (int i = 1; i<=(n-1); i++){
		X = a + i*h;
		XI1 += f(X);
	}

	double XI = (h/2) * (XI0 + 2*XI1);

	return XI;
}

int main(){
	/* === INSERT DATA HERE === */
	int n;
	double a, b;

	/* === CALCULATE === */
	double r = trapecioCompuesto(a, b, n);
	printf("%lf\n", r);

	/* === EXIT === */
	return 0;
}
