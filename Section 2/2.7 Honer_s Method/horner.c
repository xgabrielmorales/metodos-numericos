#include <stdio.h>
#include <stdlib.h>

void Horner(int n, double *a, double x_0){
	double y = a[n];
	double z = a[n];

	for(int j=n-1; j>0; j--){
		y = (x_0 * y) + a[j];
		z = (x_0 * z) + y;
	}

	y = (x_0 * y) + a[0];

	printf("y = %lf\tz = %lf\n", y, z);
	return;
}

int main(){
	/* === INSERT DATA HERE === */

	// Polynomial: 2x^4 - 3x^2 + 3x^1 - 4
	double a[] = {-4, 3, -3, 0, 2};
	double x_0 = -2;
	int n = 5;

	/* === Calculate === */
	Horner(n, a, x_0);

	return 0;
}
