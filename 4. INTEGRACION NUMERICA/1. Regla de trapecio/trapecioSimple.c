#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double trepecioSimple(double a, double b, int n){
	double h = (b - a) / n;
	return (0.5) * h * (f(a) + f(b));
}

int main(){
	/* === INSERT DATA HERE === */
	int n;
	double a, b;

	/* === CALCULATE === */
	double r = trepecioSimple(a, b, n);
	printf("%lf\n", r);

	/* === EXIT === */
	return 0;
}
