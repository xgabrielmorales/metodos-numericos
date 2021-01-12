function r = secant(f, p_0, p_1, n, tol)
	q_0 = f(p_0);
	q_1 = f(p_1);

	i = 2;
	while i<n
		p = p_1 - (q_1 * (p_1 - p_0) / (q_1 - q_0));

		if abs(p - p_1) < tol
			r = p;
			return;
		endif

		i++;
		p_0 = p_1;
		p_1 = p;

		q_0 = q_1;
		q_1 = f(p);
	endwhile
	printf("The method failed after %d iterations.\n", n);
endfunction
