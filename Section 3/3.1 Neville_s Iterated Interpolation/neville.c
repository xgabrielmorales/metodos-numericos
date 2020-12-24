#include <stdio.h>
#include <stdlib.h>

void Neville(int n, double x, double *xr, double *f){
	double **Q;

	Q = malloc((n+1) * sizeof(double *));
	for(int i=0; i<n+1; i++)
		Q[i] = malloc((n+1) * sizeof(double));

	if(!Q){
		printf("No se pudo asignar la memoria.\n");
		exit(0);
	}

	for (int i=0;i<=n;i++)
		Q[i][0]=f[i];

	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			Q[i][j]=((x-xr[i-j])*Q[i][j-1]-(x-xr[i])*Q[i-1][j-1])/(xr[i]-xr[i-j]);

	printf("%lf\n", Q[n][n]);

	return;
}

int main(){
	/* === INSERT DATA HERE === */

	int n = 3;
	double x, *xr, *f, **Q;

	xr = malloc(sizeof(double) * (n+1));
	f =  malloc(sizeof(double) * (n+1));

	x = 8.4;
	xr[0] = 8.1;
	xr[1] = 8.3;
	xr[2] = 8.6;
	xr[3] = 8.7;

	f[0] = 16.944101;
	f[1] = 17.56492;
	f[2] = 18.50515;
	f[3] = 18.820091;

	/* === Calculate === */
	Neville(n, x, xr, f);

	/* === EXIT === */
	free(xr);
	free(f);
	return 0;
}
