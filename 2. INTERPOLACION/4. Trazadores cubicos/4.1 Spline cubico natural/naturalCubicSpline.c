#include <stdio.h>

void naturalCubicSpline(int n, double *x, double *a){
	double h[n];
	double alp[n];
	double l[n];
	double m[n+1];
	double z[n+1];
	double c[n+1];
	double d[n];
	double b[n];

	for (int i=0; i<=n-1; i++)
		h[i] = x[i+1] - x[i];

	for (int i=1;i<=n-1;i++)
		alp[i] = (3.0 / h[i]) * (a[i+1] - a[i]) - (3.0 / h[i-1]) * (a[i] - a[i-1]);

	l[0] = 1;
	m[0] = 0;
	z[0] = 0;

	for(int i=1; i<=n-1; i++){
		l[i] = (2 * (x[i+1] - x[i-1])) - (h[i-1] * m[i-1]);
		m[i] = h[i] / l[i];
		z[i] = (alp[i] - (h[i-1] * z[i-1])) / l[i];
	}

	l[n] = 1;
	z[n] = 0;
	c[n] = 0;

	for(int j=n-1; j>=0; j--){
		c[j] = z[j] - m[j] * c[j+1];
		b[j] = ((a[j+1] - a[j]) /h[j]) - ((h[j] * (c[j+1] + 2.0 * c[j])) / 3.0);
		d[j] = (c[j+1] - c[j]) / (3.0 * h[j]);
	}

	for(int j=0; j<=n-1; j++){
		printf("a_{%d} = %lf\t", j, a[j]);
		printf("b_{%d} = %lf\t", j, b[j]);
		printf("c_{%d} = %lf\t", j, c[j]);
		printf("d_{%d} = %lf\t", j, d[j]);
		printf("\n");
	}
}

int main(){

	/* === INSERT DATA HERE === */
	int n;
	double x[] = {};
	double a[] = {};

	/* === CALCULATE === */
	naturalCubicSpline(n, x, a);

	/* === EXIT === */
	return 0;
}
