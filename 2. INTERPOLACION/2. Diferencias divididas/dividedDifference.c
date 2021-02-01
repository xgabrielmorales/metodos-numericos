#include <stdio.h>

void DividedDifference(int n, double *xr, double *f){
	double F[n+1][n+1];

	for(int i=0; i<=n; i++)
		F[i][0] = f[i];

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			F[i][j] = (F[i][j-1] - F[i-1][j-1]) / (xr[i] - xr[i-j]);

	for(int i=0; i<=n; i++)
		printf("F_{%d, %d} = %lf\n", i, i, F[i][i]);

	return;
}

int main(){
	/* === INSERT DATA HERE === */
	int n;
	double xr[] = {};
	double f[] = {};

	/* === CALCULATE === */
	DividedDifference(n, xr, f);

	/* === EXIT === */
	return 0;
}
