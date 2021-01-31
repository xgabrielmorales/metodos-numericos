#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double SimpsonRule(double a, double b, int n){
	double h = (b - a) / n;
	double X, XI, XI0, XI1, XI2;

	for(int i=0; i<n; i+=2){
		X = a + i*h;
		XI0 += f(X);
	}
	for(int i=1; i<n; i+=2){
		X = a + i*h;
		XI1 += f(X);
	}
	for(int i=2; i<=n; i+=2){
		X = a + i*h;
		XI2 += f(X);
	}

	XI = (h/3) * (XI0 + 4*XI1 + XI2);

	return XI;
}

int main(){
	/* === INSERT DATA HERE === */
	int n;
	double a, b;

	/* === CALCULATE === */
	double r = SimpsonRule(a, b, n);
	printf("%lf\n", r);

	/* === EXIT === */
	return 0;
}
