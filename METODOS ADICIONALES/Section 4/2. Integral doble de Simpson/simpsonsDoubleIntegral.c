#include <stdio.h>
#include <math.h>

/* === DEFINE THE FUCTION TO USE ===*/
double f(double x, double y){
	return 0;
}

double c(double x){
	return 0;
}

double d(double x){
	return 0;
}

double simpsonsDoubleIntegral(double a, double b, int m, int n){
	double x, HX;
	double K_1, K_2, K_3;
	double y, Q, L, J;

	double h = (b - a) / n;

	double J_1 = 0;
	double J_2 = 0;
	double J_3 = 0;

	for (int i=0; i<=n; i++){
		x = a + i*h;

		HX = (d(x) - c(x)) / m;

		K_1 = f(x, c(x)) + f(x, d(x));
		K_2 = K_3 = 0;

		for (int j=1; j<=m-1; j++){
			y = c(x) + j*HX;
			Q = f(x, y);

			if((j % 2) == 0)
				K_2 += Q;
			else
				K_3 += Q;
		}

		L = (K_1 + 2*K_2 + 4*K_3) * HX / 3;

		if (i == 0 || i == n)
			J_1 = J_1 + L;
		else if ((i % 2) == 0)
			J_2 = J_2 + L;
		else
			J_3 = J_3 + L;
	}

	J = h * (J_1 + 2*J_2 + 4*J_3) / 3;

	return J;
}

int main(){
	/* === INSERT DATA HERE === */
	int m, n;
	double a, b;

	/* === CALCULATE === */
	double J = simpsonsDoubleIntegral(a, b, m, n);
	printf("J = %lf\n", J);

	/* === EXIT === */
	return 0;
}
