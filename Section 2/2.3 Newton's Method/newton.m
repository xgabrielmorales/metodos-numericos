function r = newton(f, fp, n_0, p_0, tol)
	i = 1;
	while i < n_0
		p = p_0 - f(p_0) / fp(p_0);
		if abs(p - p_0) < tol
			r = p;
			return;
		endif
		i++;
		p_0 = p;
	endwhile
	printf("The method failed after %d iterations.\n", n_0);
endfunction
