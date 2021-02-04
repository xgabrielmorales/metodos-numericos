function r = richardson(f, x, h, n)
	# Derivada
	N = @(h, x) (f(x + h) - f(x)) / h;

	R = zeros(n+1, n+1);
	R(1, 1) = N(h, x);

	t = 2;
	tt = 0;

	for i = 2:n
		for j = 1:i
			if (j == 1)
				tt = power(t, i-j);
				R(i, j) = N(h/tt, x);
			else
				R(i, j) = R(i, j-1) + (R(i, j-1) - R(i-1, j-1)) / (power(t, j - 1) - 1);
			endif
		endfor
	endfor
	r = R(n, n);
endfunction
