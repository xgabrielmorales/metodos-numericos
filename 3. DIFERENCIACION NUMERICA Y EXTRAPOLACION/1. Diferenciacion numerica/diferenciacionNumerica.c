#include <stdio.h>

double derivadaProgresiva(int i, double *x, double *y){
	return (y[i+1] - y[i]) / (x[i+1] - x[i]);
}
double derivadaRetrograda(int i, double *x, double *y){
	return (y[i] - y[i-1]) / (x[i] - x[i-1]);
}
double derivadaCentral(int i, double *x, double *y){
	return  0.5 * ( ((y[i+1] - y[i]) / (x[i+1] - x[i])) + ((y[i] - y[i-1]) / (x[i] - x[i-1])) );
}

int main(){
	/* === INSERT DATA HERE === */
	int i;
	double x[] = {};
	double y[] = {};

	/* === CALL THE FUNCTION YOU ARE GOING TO USE === */
	double r = derivadaProgresiva(i, x, y);
	printf("f'(%g) = %lf\n", x[i], r);
	return 0;
}
