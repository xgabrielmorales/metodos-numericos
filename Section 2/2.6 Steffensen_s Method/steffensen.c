#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double g(double p){
	/* === Define the fuction to use ===*/
	return cos(p);
}

void Steffensen(double p, int n, double tol){
	double p_0, p_1, p_2;
	int i = 1;

	while (i < n){
		p_1 = g(p_0);
		p_2= g(p_1);
		p = p_0 - ( pow(p_1-p_0, 2) / (p_2 - 2*p_1 + p_0) );

		if (fabs(p - p_0) < tol){
			printf("%f\n", p);
			exit(0);
		}

		p_0 = p;
		i++;
	}

	printf("Method failed after %d iterations", n);
	return;
}

int main(){
	/* === INSERT DATA HERE === */
	int n = 50;
	double p = 0;
	double tol = pow(10, -6);

	/* === Calculate === */
	Steffensen(p, n, tol);
	return 0;
}
