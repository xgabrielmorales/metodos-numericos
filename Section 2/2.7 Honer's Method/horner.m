# HORNER'S METHOD

# Input
# n:    Degree of the polynomial
# a[]:  Coefficients of the polinomial
# x_0:

# Output
# [P(x_0), P'(x_0)]

function r = horner(n, a, x_0)
	y = a(n+1);
	z = a(n+1);

	for j = n-1:-1:1
		y = (x_0 * y) + a(j+1);
		z = (x_0 * z) + y;
	endfor

	y = (x_0 * y) + a(1);

	r = [ y z ];
endfunction
