#include <stdio.h>
#include <math.h>

double f(double x){
	return 0;
}

double cuadraturaLobatto(double a, double b, double* x, double* w, int n){
	double G[n];
	for(int i=0; i<n; i++)
		G[i] = ((b-a) * x[i] + a + b)/2;

	double sum;
	for(int i = 1; i<n-1; i++)
		sum += w[i] * f(G[i]);

	return (b - a) * (0.5) * (w[0] * f(G[0]) + w[n-1] * f(G[n-1]) + sum);
}

int main(){
	double a, b;
	double x[] = {};
	double w[] = {};
	int n;

	double r = cuadraturaLobatto(a, b, x, w, n);
	printf("r = %lf\n", r);

	return 0;
}
