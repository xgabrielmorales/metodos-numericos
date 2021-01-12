#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}
double fp(double x){
	/* === DEFINE THE DERIVATIVE OF THE FUNCTION f(x) */
	return 0;
}

double Newton(int n_0, double p_0, double tol){
	double p;

	int i = 1;
	while (i <= n_0){
		p = p_0 - f(p_0) / fp(p_0);
		if (fabs(p - p_0) < tol){
			return p;
		}
		i++;
		p_0 = p;
	}
	printf("The method failed after %d iterations.", n_0);
}

int main(){
	/* === INSERT DATA HERE === */
	int n_0;
	double p_0;
	double tol;

	/* === CALCULATE THE NEWTON'S METHOD === */
	double r = Newton(n_0, p_0, tol);
	printf("%lf\n", r);

	return 0;
}
