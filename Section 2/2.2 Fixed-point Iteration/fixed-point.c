#include <stdio.h>
#include <math.h>

double g(double p){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double FixedPoint(double p_0, int n, double tol){
	double p, i = 1;

	while (i < n){
		p = g(p_0);

		if (fabs(p - p_0) < tol){
			return p;
		}
		i = i + 1;
		p_0 = p;
	}
	printf("The method failed after %d iterations.\n", n);
}

int main(){
	/* === INSERT DATA HERE === */
	int n;
	double p_0;
	double tol;

	/* === CALCULATE THE FIXED POINT === */
	double r = FixedPoint(p_0, n, tol);
	printf("%lf\n", r);

	return 0;
}
