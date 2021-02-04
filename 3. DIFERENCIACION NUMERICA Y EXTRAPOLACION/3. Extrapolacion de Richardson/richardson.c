#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double N(double h, double x){
	return (f(x + h) - f(x)) / h;
}

double richardson(double x, double h, int n){
	double R[n+1][n+1];

	R[0][0] = N(h, x);

	int tt, t = 2;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=i; j++){
			if (j == 0){
				tt = pow(t, i - j);
				R[i][j] = N(h/tt, x);
			} else {
				R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1]) / (pow(t, j) - 1);
			}
		}
	}

	return R[n][n];
}

int main(){
	/* === INSERT DATA HERE === */
	double x;
	double h;
	int Oi;

	/* === CALCULATE === */
	double r = richardson(x, h, Oi);
	printf("%lf\n", r);

	/* === EXIT === */
	return 0;
}
