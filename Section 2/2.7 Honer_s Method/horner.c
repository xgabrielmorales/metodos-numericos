#include <stdio.h>
#include <stdlib.h>

int *Horner(int n, int *a, int x_0){
	int y = a[n];
	int z = a[n];

	for(int j=n-1; j>0; j--){
		y = (x_0 * y) + a[j];
		z = (x_0 * z) + y;
	}

	y = (x_0 * y) + a[0];

	int *r = malloc(2 * sizeof(int));
	r[0] = y, r[1] = z;

	return r;
}

int main(){
	/* === INSERT DATA HERE === */

	// Polynomial: 2x^4 - 3x^2 + 3x^1 - 4
	int a[] = {-4, 3, -3, 0, 2};
	int x_0 = -2;
	int n = 4;

	/* === Calculate === */
	int *p = Horner(n, a, x_0);

	printf("y = %d, z = %d", p[0], p[1]);

	free(p);
	return 0;
}
