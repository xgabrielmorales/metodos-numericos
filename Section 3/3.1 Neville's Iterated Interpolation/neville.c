#include <stdio.h>
#include <stdlib.h>

void Neville(int n, double x, double *xr, double *f){
	double **Q;

	Q = malloc((n+1) * sizeof(double *));
	for(int i=0; i<n+1; i++)
		Q[i] = malloc((n+1) * sizeof(double));

	for (int i=0;i<=n;i++){
		Q[i][0]=f[i];
	}

	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			Q[i][j]= ((x-xr[i-j])*Q[i][j-1]-(x-xr[i])*Q[i-1][j-1]) / (xr[i]-xr[i-j]);

	for(int i=0; i<=n; i++){
		for(int j=0; j<=i; j++){
			printf("Q[%d][%d] = %lf\n", i, j, Q[i][j]);
		}
		printf("\n");
	}

	while(n+1) free(Q[--n+1]);
	free(Q);
}

int main(){
	/* === INSERT DATA HERE === */
	int n;
	double x;
	double *xr, *f;

	/* === CALCULATE === */
	Neville(n, x, xr, f);

	/* === EXIT === */
	return 0;
}
