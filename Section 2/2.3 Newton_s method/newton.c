#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
	/* === Define the fuction to use ===*/
	return cos(x) - x;
}
double fp(double x){
	/* === Define the derivative of the function f(x) */
	return -sin(x) - 1;
}

void Newton(int n_0, double p_0, double tol){
	double p;

	int i = 1;
	while (i <= n_0){
		p = p_0 - f(p_0) / fp(p_0);
		if (fabs(p - p_0) < tol){
			printf("p = %lf\n", p);
			return;
		}
		i++;
		p_0 = p;
	}
	printf("The method failed after %d iterations.", n_0);
	return;
}

int main(){
	/* === INSERT DATA HERE === */
	int n_0 = 100;
	double p_0 = 0;
	double tol = pow(10, -6);

	/* === Calculate the Newton's Method === */
	Newton(n_0, p_0, tol);

	return 0;
}
