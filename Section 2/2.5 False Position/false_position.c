#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double FalsePosition(double p_0, double p_1, int n, double tol){
	double p, q;
	double q_0 = f(p_0);
	double q_1 = f(p_1);

	int i = 2;
	while (i < n){
		p = p_1 - (q_1 * (p_1 - p_0) / (q_1 - q_0));

		if (fabs(p - p_1) < tol)
			return p;

		i++;
		q = f(p);

		if ((q * q_1) < 0){
			p_0 = p_1;
			q_0 = q_1;
		}

		p_1 = p;
		q_1 = q;
	}
	printf("The method failed after %d iterations.\n", n);
}

int main(){
	/* === INSERT DATA HERE === */
	double n;
	double p_0;
	double p_1;
	double tol;

	/* === CALCULATE === */
	double r = FalsePosition(p_0, p_1, n, tol);
	printf("%lf\n", r);
	return 0;
}
