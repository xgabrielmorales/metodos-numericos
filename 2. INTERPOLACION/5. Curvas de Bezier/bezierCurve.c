#include <stdio.h>

void bezierCurve(
		int n,
		double *x,      double *y,
		double *xPlus,  double *yPlus,
		double *xMinus, double *yMinus
){
	double a_0[n];
	double a_1[n];
	double a_2[n];
	double a_3[n];

	double b_0[n];
	double b_1[n];
	double b_2[n];
	double b_3[n];

	for (int i=0; i<=n-1; i++){
		a_0[i] = x[i];
		b_0[i] = y[i];

		a_1[i] = 3 * (xPlus[i] - x[i]);
		b_1[i] = 3 * (yPlus[i] - y[i]);

		a_2[i] = 3 * (x[i] + xMinus[i] - 2 * xPlus[i]);
		b_2[i] = 3 * (y[i] + yMinus[i] - 2 * yPlus[i]);

		a_3[i] = x[i+1] - x[i] + 3 * xPlus[i] - 3 * xMinus[i];
		b_3[i] = y[i+1] - y[i] + 3 * yPlus[i] - 3 * yMinus[i];

		printf("a_{0}\t a_{1}\t a_{2}\t a_{3}\n");
		printf("%g\t %g\t %g\t %g\n", a_0[i], a_1[i], a_2[i], a_3[i]);

		printf("b_{0}\t b_{1}\t b_{2}\t b_{3}\n");
		printf("%g\t %g\t %g\t %g\n\n", b_0[i], b_1[i], b_2[i], b_3[i]);
	}

	return;
}


int main(){
	/* === INSERT DATA HERE === */
	int n = 2;
	double x[] = {0, 3, 5}, y[] = {0, 2, 1};
	double xPlus[] = {-1, 2}, yPlus[] = {1, -2};
	double xMinus[] = {3, 5}, yMinus[] = {4, 4};

	/* === CALCULATE === */
	bezierCurve(
		n,
		x,      y,
		xPlus,  yPlus,
		xMinus, yMinus
	);

	/* === EXIT === */
	return 0;
}
