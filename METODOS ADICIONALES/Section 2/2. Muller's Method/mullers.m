function r = mullers(f, n_0, tol, p_0, p_1, p_2)
	h_1 = p_1 - p_0;
	h_2 = p_2 - p_1;

	eps_1 = (f(p_1) - f(p_0)) / h_1;
	eps_2 = (f(p_2) - f(p_1)) / h_2;

	d = (eps_1 - eps_2) / (h_1 + h_2);

	i = 3;

	while i<=n_0
		b = eps_2 + (h_2 * d);

		D = sqrt(power(b, 2) - (4 * f(p_2) * d));

		if abs(b - D) <  abs(b + D)
			E = b + D;
		else
			E = b - D;
		endif

		h = (-2 * f(p_2)) / E;
		p = p_2 + h;

		if abs(h) < tol
			r = p;
			return;
		endif

		p_0 = p_1;
		p_1 = p_2;
		p_2 = p;

		h_1 = p_1 - p_0;
		h_2 = p_2 - p_1;

		eps_1 = (f(p_1) - f(p_0)) / h_1;
		eps_2 = (f(p_2) - f(p_1)) / h_2;

		d = (eps_2 - eps_1) / (h_1 + h_2);
		i++;
	endwhile

	printf("Method falied after %d iterations.\n", n_0);
endfunction
