#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double cuadraturaGauss(double a, double b){
	double gt  = ((b - a) * (-sqrt(3)/3) + a + b) * (0.5);
	double gpt = ((b - a) * ( sqrt(3)/3) + a + b) * (0.5);

	double XI = (b-a) * (0.5) * (f(gt) + f(gpt));

	return XI;
}

int main(){
	/* === INSERT DATA HERE === */
	double a, b;

	/* === CALCULATE === */
	double r = cuadraturaGauss(a, b);
	printf("%lf\n", r);

	/* === EXIT === */
	return 0;
}
