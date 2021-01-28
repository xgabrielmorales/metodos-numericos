function Romberg(f, a, b, n)
	h = b - a;

	R = zeros(n+1, n+1);
	R(1,1) = (h/2) * (f(a) + f(b));

	printf("R_{1, 1} = %f\n", R(1,1));

	for i = 2:n
		sumatoria = 0;
		for j = power(2, i-2)
			sumatoria += f(a + (j - 0.5) * h);
		endfor
		R(2, 1) = (0.5) * (R(1,1) + (h * sumatoria));

		for j = 2:i
			R(2, j) = R(2, j-1) + (R(2,j-1) - R(1,j-1)) / (power(4, j-1) - 1);
		endfor

		for j = 1:i
			printf("R_{2, %d} = %f\n", j, R(2, j));
		endfor

		h /= 2;

		for j = 1:i
			R(1, j) = R(2, j);
		endfor

	endfor
endfunction
