#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double Secant(double p_0, double p_1, int n, double tol){
	double p;
	int i = 2;

	double q_0 = f(p_0);
	double q_1 = f(p_1);

	while (i < n){
		p = p_1 - (q_1 * (p_1 - p_0) / q_1 - q_0);

		if (fabs(p - p_1) < tol)
			return p;

		i++;
		p_0 = p_1;
		p_1 = p;

		q_0 = q_1;
		q_1 = f(p);
	}
	printf("The method failed after %d iterations.\n", n);
}

int main(){
	/* === INSERT DATA HERE === */
	int n;
	double p_0;
	double p_1;
	double tol;

	/* === CALCULATE THE SECANT === */
	double r = Secant(p_0, p_1, n, tol);
	printf("%lf\n", r);

	return 0;
}
