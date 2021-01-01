# Fixed-POINT METHOD

# Input
# g(p): Function to use
# p_0:  Initial approximation
# n:    Maximum number of iterations
# tol:  Maximum tolerated error

# Output
# Approximate solution p or message of failure.

function r = fixedpoint(g, p_0, n, tol)
	i = 1;
	while i < n
		p = g(p_0);
		if abs(p - p_0) < tol
			r = p;
			return;
		endif
		i++;
		p_0 = p;
	endwhile
	printf("The method failed after %d iterations.\n", n);
endfunction
