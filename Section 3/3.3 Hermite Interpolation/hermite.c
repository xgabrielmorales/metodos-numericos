#include <stdio.h>
#include <stdlib.h>

double *Hermite(int n, double *x, double *f, double *fp){
	int size = (2*n);
	double *z = malloc(size * sizeof(double));

	double **Q = malloc(size * sizeof(double *) );
	for (int i=0; i<size; i++)
		Q[i] = malloc(size * sizeof(double) );

	for(int i=0; i<n; i++){
		z[2*i]        = x[i];
		z[(2*i)+1]    = x[i];

		Q[2*i][0]     = f[i];
		Q[(2*i)+1][0] = f[i];

		Q[(2*i)+1][1] = fp[i];

		if(i != 0)
			Q[2*i][1] = (Q[2*i][0] - Q[(2*i)-1][0]) / (z[2*i] - z[(2*i)-1]);
	}

	for(int i=2; i<size; i++)
		for(int j=2; j<=i; j++)
			Q[i][j] = (Q[i][j-1] - Q[i-1][j-1]) / (z[i] - z[i-j]);

	double *r = malloc(2*n * sizeof(double));
	for(int i=0; i<size; i++)
		r[i] = Q[i][i];

	while(size) free(Q[--size]);
	free(Q);
	free(z);

	return r;
}

int main(){
	int n;
	double *x;
	double *f;
	double *fp;
	/* === INSERT DATA HERE === */

	/* === CALCULATE === */
	double *r = Hermite(n, x, f, fp);
	for(int i=0; i<2*n; i++)
		printf("Q_{%d, %d} = %lf\n", i, i, r[i]);

	/* === EXIT === */
	free(r);
	return 0;
}
