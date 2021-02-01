#include <stdio.h>

void Hermite(int n, double *x, double *f, double *fp){
	double Q[(2*n)+1][(2*n)+1];
	double z[(2*n)+1];

	for(int i=0; i<=n; i++){
		z[2*i] = x[i];
		z[(2*i)+1] = x[i];

		Q[2*i][0] = f[i];
		Q[(2*i)+1][0] = f[i];

		Q[(2*i)+1][1] = fp[i];

		if(i != 0)
			Q[2*i][1] = (Q[2*i][0] - Q[(2*i)-1][0]) / (z[2*i] - z[(2*i)-1]);
	}

	for(int i=2; i<=(2*n)+1; i++)
		for(int j=2; j<=i; j++)
			Q[i][j] = (Q[i][j-1] - Q[i-1][j-1]) / (z[i] - z[i-j]);

	for(int i=0; i<=(2*n)+1; i++)
		printf("Q[%d][%d] = %lf\n", i, i, Q[i][i]);
}

int main(){
	/* === INSERT DATA HERE === */
	int n;
	double x[] = {};
	double f[] = {};
	double fp[] = {};

	/* === CALCULATE === */
	Hermite(n, x, f, fp);

	/* === EXIT === */
	return 0;
}
