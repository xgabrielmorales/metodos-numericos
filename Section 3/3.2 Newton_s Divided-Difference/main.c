#include <stdio.h>
#include <stdlib.h>

void NewtonsDividedDifference(int n, double *xr, double *f){
	double **F;

	F = malloc(sizeof(double) * (n+1));
	for(int i=0; i<n+1; i++)
		F[i] = malloc((n+1) * sizeof(double));

	if(!F){
		printf("No se pudo reservar memoria para hacer los calculos.\n");
		exit(0);
	}

	for(int i=0; i<=n; i++)
		F[i][0] = f[i];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			F[i][j] = (F[i][j-1] - F[i-1][j-1]) / (xr[i] - xr[i-j]);

	for(int i=0; i<=n; i++){
		printf("F_{%d, %d} = %lf\n", i, i, F[i][i]);
	}

	return;
}

int main(){
	/* === INSERT DATA HERE === */
	int n = 4;
	double *xr, *f;

	xr = malloc((n+1) * sizeof(double));
	f =  malloc((n+1) * sizeof(double));

	xr[0] = 1.0;
	xr[1] = 1.3;
	xr[2] = 1.6;
	xr[3] = 1.9;
	xr[4] = 2.2;

	f[0] = 0.7651977;
	f[1] = 0.6200860;
	f[2] = 0.4554022;
	f[3] = 0.2818186;
	f[4] = 0.1103623;

	/* === Calculate === */
	NewtonsDividedDifference(n, xr, f);

	return 0;
}
