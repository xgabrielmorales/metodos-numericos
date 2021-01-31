#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double compositeSimpson38(double a, double b, int n){
	double h = (b - a)/n;
	double XI0 = f(a) + f(b);
	double X, XI1, XI2, XI3;

	for (int i=1; i<=n-2; i=i+3){
		X = a + i*h;
		XI1 += f(X);
	}
	for (int i=2; i<=n-1; i=i+3){
		X = a + i*h;
		XI2 += f(X);
	}
	for (int i=2; i<=n-3; i=i+3){
		X = a + i*h;
		XI3 += f(X);
	}

	double XI = (0.375)*h*(XI0 + 3*XI1 + 3*XI2 + 2*XI3);

	return XI;
}

int main(){
	/* === INSERT DATA HERE === */
	int n;
	double a, b;

	/* === CALCULATE === */
	double r = compositeSimpson38(a, b, n);
	printf("%lf\n", r);

	/* === EXIT === */
	return 0;
}
