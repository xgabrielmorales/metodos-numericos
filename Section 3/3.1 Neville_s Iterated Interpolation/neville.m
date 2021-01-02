# Neville's Iterated Iterpolation

# Input
# n:    Number of x's minus one unit
# x:    Number  -> x
# xr[]: Numbers -> x_0, x_1, ..., x_n
# f[]:  Values  -> f(x_0), f(x_1), ..., f(x_n)

# Output
# The table Q with P(x) = Q(n)(n)

function r = neville(n, x, xr, f)
	Q = zeros(n+1, n+1);
	for i = 1:n+1
		Q(i,1) = f(i);
	endfor

	for i = 1:n
		for j = 1:i
			Q(i+1, j+1) = (((x - xr((i-j)+1)) * Q(i+1, j)) - (x - xr(i+1))*Q(i, j)) / (xr(i+1) - xr((i-j)+1));
		endfor
	endfor

	r = Q(n+1, n+1);
endfunction
