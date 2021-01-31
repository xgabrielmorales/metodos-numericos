#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double puntoMedioSimple(double a, double b){
	double h = b - a;
	double m = (a + b)/2;
	return h * f(m);
}

int main(){
	/* === INSERT DATA HERE === */
	double a, b;

	/* === CALCULATE === */
	double r = puntoMedioSimple(a, b);
	printf("%lf\n", r);

	/* === EXIT === */
	return 0;
}
