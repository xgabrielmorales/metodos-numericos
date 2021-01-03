#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return pow(x, 2) * (1 - pow(sin(3*x), 2));
}

double simpsions(double a, double b, int n){
	double h   = (b - a) / n;
	double XI0 = f(a) + f(b);

	double XI1, XI2;
	XI1 = XI2 = 0;

	double X, XI;

	for(int i=1; i<n; i++){
		X = a + i * h;
		if ((i % 2) == 0)
			XI2 += f(X);
		else
			XI1 += f(X);
	}

	XI = (h / 3.0) * (XI0 + 2*XI2 + 4*XI1);

	return XI;
}

int main(){
	int n;
	double a, b;
	/* === INSERT DATA HERE === */

	/* === CALCULATE === */
	double r = simpsions(a, b, n);
	printf("%lf\n", r);

	/* === EXIT === */
	return 0;
}
