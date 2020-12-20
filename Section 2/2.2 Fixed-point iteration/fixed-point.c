#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double g(double p){
	/* === Define the fuction to use ===*/
	return cos(p);
}

void FixedPoint(double p_0, int n, double tol){
	double p, i = 1;

	while (i < n){
		p = g(p_0);

		if (fabs(p - p_0) < tol){
			printf("%f\n", p);
			exit(0);
		}
		i = i + 1;
		p_0 = p;
	}

	printf("El metodo ha fallado después de %d iteraciones.");
}

int main(){
	/* === INSERT DATA HERE === */
	int n = 100;
	double p_0 = 0;
	double tol = pow(10, -6);

	/* === Calculate the fixed point === */
	FixedPoint(p_0, n, tol);
	return 0;
}
