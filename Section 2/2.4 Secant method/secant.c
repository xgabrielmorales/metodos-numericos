#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x){
	/* === Define the fuction to use ===*/
	return cos(x) - x;
}

void Secant(double p_0, double p_1, int n, double tol){
	double p;
	int i = 2;

	double q_0 = f(p_0);
	double q_1 = f(p_1);

	while (i < n){
		p = p_1 - (q_1 * (p_1 - p_0) / q_1 - q_0);

		if (fabs(p - p_1) < tol){
			printf("%.7f\n", p);
			exit(0);
		}

		i++;
		p_0 = p_1;
		p_1 = p;

		q_0 = q_1;
		q_1 = f(p);
	}

	printf("The method failed after %d iterations.\n", n);
	return;
}

int main(){
	/* === INSERT DATA HERE === */
	int n = 100;
	double p_0 = 0.5;
	double p_1 = 1;
	double tol = pow(10, -6);

	/* === Calculate the secant === */
	Secant(p_0, p_1, n, tol);

	return 0;
}
