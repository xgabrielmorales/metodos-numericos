#include <stdio.h>
#include <math.h>

double f(double x){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double Mullers(double n_0, double tol, double p_0, double p_1, double p_2){
	double h_1 = p_1 - p_0;
	double h_2 = p_2 - p_1;

	double eps_1 = (f(p_1) - f(p_0)) / h_1;
	double eps_2 = (f(p_2) - f(p_1)) / h_2;

	double d = (eps_1 - eps_2) / (h_1 + h_2);

	double b;
	double D;
	double E;
	double p;
	double h;

	int i = 3;
	while(i <= n_0){
		b = eps_2 + (h_2 * d);

		D = sqrt(pow(b, 2) - (4 * f(p_2) * d));

		if(fabs(b - D) <  fabs(b + D))
			E = b + D;
		else
			E = b - D;

		h = (-2 * f(p_2)) / E;
		p = p_2 + h;

		if(fabs(h) < tol){
			return p;
		}

		p_0 = p_1;
		p_1 = p_2;
		p_2 = p;

		h_1 = p_1 - p_0;
		h_2 = p_2 - p_1;

		eps_1 = (f(p_1) - f(p_0)) / h_1;
		eps_2 = (f(p_2) - f(p_1)) / h_2;

		d = (eps_2 - eps_1) / (h_1 + h_2);
		i++;
	}

	printf("Method Failed after %d iterations.\n", n_0);
	return 0;
}

int main(){
	/* === INSERT DATA HERE === */
	int n_0;
	double p_0;
	double p_1;
	double p_2;
	double tol;

	/* === CALCULATE === */
	double r = Mullers(n_0, tol, p_0, p_1, p_2);
	printf("%lf\n", r);
	return 0;
}
