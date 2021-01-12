function r = falseposition(f, p_0, p_1, n, tol)
	q_0 = f(p_0);
	q_1 = f(p_1);

	i = 2;
	while i < n
		p = p_1 - (q_1 * (p_1 - p_0) / (q_1 - q_0));

		if (abs(p - p_1) < tol)
			r = p;
			return;
		endif

		i++;
		q = f(p);

		if (q*q_1) < 0
			p_0 = p_1;
			q_0 = q_1;
		endif

		p_1 = p;
		q_1 = q;
	endwhile
	printf("The method failed after %d iterations.\n", n);
endfunction
