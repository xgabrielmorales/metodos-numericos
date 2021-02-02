#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double puntoMedioCompuesto(double a, double b, int n){
	double h = (b - a)/n;
	double X, XI0 = 0;

	for(int i=1; i<n; i+=2){
		X = a + i*h;
		printf("%lf\n", X);
		XI0 += f(X);
	}

	double XI = 2 * h * XI0;

	printf("\n");
	return XI;
}

int main(){
	/* === INSERT DATA HERE === */
	int n;
	double a, b;

	/* === CALCULATE === */
	double r = puntoMedioCompuesto(a, b, n);
	printf("%lf\n", r);

	/* === EXIT === */
	return 0;
}
