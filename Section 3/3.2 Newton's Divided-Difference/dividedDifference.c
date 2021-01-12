#include <stdio.h>
#include <stdlib.h>

double **DividedDifference(int n, double *xr, double *f){
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

	return F;
}

int main(){
	int n;
	double *xr, *f;
	/* === INSERT DATA HERE === */

	/* === CALCULATE === */
	double **r = DividedDifference(n, xr, f);
	for(int i=0; i<=n; i++)
		printf("F_{%d, %d} = %lf\n", i, i, r[i][i]);

	/* === EXIT === */
	while(n+1) free(r[--n+1]);
	free(r);
	free(xr);
	free(f);

	return 0;
}
