#include <stdio.h>
#include <math.h>

double g(double p){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double Steffensen(double p_0, int n, double tol){
	double p, p_1, p_2;
	int i = 1;

	while (i < n){
		p_1 = g(p_0);
		p_2= g(p_1);
		p = p_0 - ( pow(p_1-p_0, 2) / (p_2 - 2*p_1 + p_0) );

		if (fabs(p - p_0) < tol)
			return p;

		p_0 = p;
		i++;
	}
	printf("Method failed after %d iterations", n);
}

int main(){
	/* === INSERT DATA HERE === */
	int n;
	double p_0;
	double tol;

	/* === CALCULATE === */
	double r = Steffensen(p_0, n, tol);
	printf("%lf\n", r);
	return 0;
}
