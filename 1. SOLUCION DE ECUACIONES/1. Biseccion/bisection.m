function r = bisection(f, a, b, n, tol)
	f_de_a = f(a);

	i = 1;
	while i <= n
		p = a + (b - a) / 2;
		f_de_p = f(p);
		if f_de_p == 0 || ((b - a)/2) < tol
			r = p;
			return;
		endif
		if (f_de_a * f_de_p) > 0
			a = p;
			f_de_a = f_de_p;
		else
			b = p;
		endif
		i++;
	endwhile
	printf("The method failed after %d iterations.\n", n);
endfunction
