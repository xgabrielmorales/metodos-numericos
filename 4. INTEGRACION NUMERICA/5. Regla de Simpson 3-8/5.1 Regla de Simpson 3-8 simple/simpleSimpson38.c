#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double simpleSimpson38(double a, double b){
	double h = (b - a) / 3;

	double x1 = a + h;
	double x2 = x1 + h;

	double XI = (0.375) * h * (f(a) + 3*f(x1) + 3*f(x2) + f(b));

	return XI;
}

int main(){
	/* === INSERT DATA HERE === */
	double a, b;

	/* === CALCULATE === */
	double r = simpleSimpson38(a, b);
	printf("%lf\n", r);

	/* === EXIT === */
	return 0;
}
