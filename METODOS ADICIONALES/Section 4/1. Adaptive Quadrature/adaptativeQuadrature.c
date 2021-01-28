#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double adaptiveQuadrature(double A, double B, double tol, int n){
	double *TOL = malloc(n * sizeof(double));
	double *a   = malloc(n * sizeof(double));
	double *h   = malloc(n * sizeof(double));
	double *FA  = malloc(n * sizeof(double));
	double *FB  = malloc(n * sizeof(double));
	double *FC  = malloc(n * sizeof(double));
	double *S   = malloc(n * sizeof(double));
	double *L   = malloc(n * sizeof(double));
	double *v   = malloc(8 * sizeof(double));

	double APP = 0;
	int i = 1;

	TOL[i] = 10*tol;
	a[i]   = A;
	h[i]   = (B - A) / 2;

	FA[i] = f(A);
	FC[i] = f(A + h[i]);
	FB[i] = f(B);

	S[i] = h[i] * (FA[i] + 4 * FC[i] + FB[i]) / 3;

	L[i] = 1;

	double FD, FE, S1, S2;
	while (i > 0){
		FD = f(a[i] + h[i]/2);
		FE = f(a[i] +  (3*h[i])/2);

		S1 = h[i] * (FA[i] + 4 * FD + FC[i]) / 6;
		S2 = h[i] * (FC[i] + 4 * FE + FB[i]) / 6;

		v[0] = a[i];
		v[1] = FA[i];
		v[2] = FC[i];
		v[3] = FB[i];
		v[4] = h[i];
		v[5] = TOL[i];
		v[6] = S[i];
		v[7] = L[i];

		i--;

		if (fabs(S1 + S2 - v[6]) < v[5]){
			APP += (S1 + S2);
		} else {
			if (v[7] >= n){
				break;
			} else {
				i++;
				a[i]   = v[0] + v[4];
				FA[i]  = v[2];
				FC[i]  = FE;
				FB[i]  = v[3];
				h[i]   = v[4]/2;
				TOL[i] = v[5]/2;
				S[i]   = S2;
				L[i]   = v[7] + 1;

				i++;

				a[i]   = v[0];
				FA[i]  = v[1];
				FC[i]  = FD;
				FB[i]  = v[2];
				h[i]   = h[i-1];
				TOL[i] = TOL[i-1];
				S[i]   = S1;
				L[i]   = L[i-1];
			}
		}
	}

	free(TOL);
	free(a);
	free(h);
	free(FA);
	free(FB);
	free(FC);
	free(S);
	free(L);
	free(v);

	return APP;
}

int main(){
	/* === INSERT DATA HERE === */
	double A, B;
	double tol;
	int n;

	/* === CALCULATE === */
	double r = adaptiveQuadrature(A, B, tol, n);
	printf("r = %lf\n", r);

	/* === EXIT === */
	return 0;
}
