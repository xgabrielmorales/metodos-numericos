#include <stdio.h>
#include <stdlib.h>

double Neville(int n, double x, double *xr, double *f){
	double **Q;

	Q = malloc((n+1) * sizeof(double *));
	for(int i=0; i<n+1; i++)
		Q[i] = malloc((n+1) * sizeof(double));

	if(!Q){
		printf("No se pudo asignar la memoria.\n");
		exit(0);
	}

	for (int i=0;i<=n;i++){
		Q[i][0]=f[i];
	}

	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++){
			Q[i][j]= ((x-xr[i-j])*Q[i][j-1]-(x-xr[i])*Q[i-1][j-1]) / (xr[i]-xr[i-j]);
		}

	double r = Q[n][n];

	while(n+1) free(Q[--n+1]);
	free(Q);

	return r;
}

int main(){
	int n;
	double x, *xr, *f;
	/* === INSERT DATA HERE === */

	/* === CALCULATE === */
	double r = Neville(n, x, xr, f);
	printf("%lf\n", r);

	/* === EXIT === */
	free(xr);
	free(f);
	return 0;
}
