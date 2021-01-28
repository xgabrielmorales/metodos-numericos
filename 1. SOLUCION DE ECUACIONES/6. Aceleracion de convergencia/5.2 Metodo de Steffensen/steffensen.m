function r = steffensen(g, p_0, n, tol)
	p_1 = 0;
	p_2 = 0;

	i = 1;
	while i<n
		p_1 = g(p_0);
		p_2 = g(p_1);
		p = p_0 - ( power(p_1 - p_0, 2) / (p_2 - 2*p_1 + p_0) );

		if abs(p - p_0) < tol
			r = p;
			return;
		endif

		p_0 = p;
		i++;
	endwhile
	printf("Method Failed after %d iterations", n);
endfunction
