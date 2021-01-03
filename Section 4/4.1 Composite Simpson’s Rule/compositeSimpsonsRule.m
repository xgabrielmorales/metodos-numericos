# Composite Simpson's Rule

# Input
# f:    Function to use
# a, b: Intervals in which the function is defined
# n:    Number of intervals

# Output
# Approximation XI to I

function XI = simpsions(f, a, b, n)
	h = (b - a) / n;
	XIO = f(a) + f(b);
	XI1 = XI2 = 0;

	for i = 2:n
		X = a + (i-1) * h;
		if mod(i, 2) == 0
			XI1 += f(X);
		else
			XI2 += f(X);
		endif
	endfor

	XI = (h * (XIO + 2*XI2 + 4*XI1)) / 3;
endfunction
