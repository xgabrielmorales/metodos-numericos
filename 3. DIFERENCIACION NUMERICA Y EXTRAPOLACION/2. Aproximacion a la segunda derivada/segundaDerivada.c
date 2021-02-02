#include <stdio.h>

double segundaDerivadaProgresiva(double* x, double* y, int i){
	double h = x[i] - x[i-1];
	return (y[i+2] - 2*y[i+1] + y[i]) / (h*h);
}
double segundaDerivadaCentral(double* x, double* y, int i){
	double h = x[i] - x[i-1];
	return (y[i+1] - 2*y[i] + y[i-1]) / (h*h);
}
double segundaDerivadaRetrograda(double* x, double* y, int i){
	double h = x[i] - x[i-1];
	return (y[i] - 2*y[i] + y[i-2]) / (h*h);
}

int main(){
	/* === INSERT DATA HERE === */
	int i;
	double x[] = {};
	double y[] = {};

	/* === CALCULATE === */
	double r = segundaDerivadaProgresiva(x, y, i);
	printf("%lf\n", r);

	return 0;
}
