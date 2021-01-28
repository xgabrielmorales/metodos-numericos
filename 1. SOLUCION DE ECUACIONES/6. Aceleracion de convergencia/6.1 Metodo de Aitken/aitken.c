#include <stdio.h>
#include <math.h>

double g(double n){
	/* === DEFINE THE FUCTION TO USE ===*/
	return 0;
}

double aitken(double p_0){
	double p_1 = g(p_0);
	double p_2 = g(p_0 + 1);
	double p_3 = g(p_0 + 2);

	double p = p_1 - (pow(p_2 - p_1, 2) / (p_3 - 2*p_2 + p_1));

	return p;
}

int main(){
	/* === INSERT DATA HERE === */
	double p_0;

	/* === CALCULATE === */
	double r = aitken(p_0);
	printf("%lf\n", r);
	return 0;
}
