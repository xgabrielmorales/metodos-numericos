#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double cuadraturaKronrod(double a, double b, int n, double *x, double *w){
	double G[n];
	double sum = 0;

	for(int i=0; i<n; i++){
		G[i] = ((b-a) * x[i] + a + b)/2;
		sum += w[i] * f(G[i]);
	}

	return (b-a) * (0.5) * sum;
}

int main(){
	/* === INSERT DATA HERE === */
	double a = 0, b = 2;
	int n = (2*b) + 1;

	double x[] = {};
	double w[] = {};

	/* === CALCULATE === */
	double r = cuadraturaKronrod(a, b, n, x, w);
	printf("%lf\n", r);

	/* === EXIT === */
	return 0;
}
