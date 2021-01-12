#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

void Romberg(double a, double b, int n){

	double h = b - a;

	double **R = malloc((n+1) * sizeof(double *));
	for(int i=0; i<n+1; i++)
		R[i] = malloc((n+1) * sizeof(double));

	R[1][1] = (h/2) * (f(a)+f(b));

	printf("R_{1, 1} = %lf\n", R[1][1]);

	double sum;
	for(int i=2; i<n+1; i++){
		for(int j=1; j<=(pow(2,i-2)); j++)
			sum += f(a + (j - 0.5)*h);

		R[2][1] = (0.5) * (R[1][1] + (h * sum));

		for(int j=2; j<=i; j++)
			R[2][j] = R[2][j-1] + ((R[2][j-1] - R[1][j-1]) / (pow(4,j-1) - 1));

		for(int j=1; j<=i; j++)
			printf("R_{2, %d} = %lf\n", j, R[2][j]);

		h /= 2;

		for(int j=1; j<=i; j++)
			R[1][j] = R[2][j];
	}

	while(n+1) free(R[--n+1]);
	free(R);

	return;
}

int main(){
	/* === INSERT DATA HERE === */
	int n;
	double a, b;

	/* === CALCULATE === */
	Romberg(a, b, n);

	/* === EXIT === */
	return 0;
}
