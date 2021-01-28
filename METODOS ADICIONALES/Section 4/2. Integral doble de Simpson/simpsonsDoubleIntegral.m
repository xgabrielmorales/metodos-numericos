function J = simpsonsDoubleIntegral(f, c, d, a, b, m, n)
	h = (b - a) / n;

	J_1 = J_2 = J_3 = 0;

	for i = 0:n
		x = a + i * h;

		HX = (d(x) - c(x)) / m;

		K_1 = f(x, c(x)) + f(x, d(x));
		K_2 = K_3 = 0;

		for j = 1:m-1
			y = c(x) + j*HX;
			Q = f(x, y);

			if mod(j, 2) == 0
				K_2 += Q;
			else
				K_3 += Q;
			endif
	 	endfor

		L = (K_1 + 2*K_2 + 4*K_3) * HX / 3;

		if i == 0 || i == n
			J_1 += L;
		else if mod(i, 2) == 0
			J_2 += L;
			else
				J_3 += L;
			endif
		endif
	endfor

	J = h * (J_1 + 2*J_2 + 4*J_3) / 3;
endfunction
