function XI = puntoMedioCompuesto(f, a, b, n)
	h = (b - a)/n;
	X = XI0 = 0;

	for i = 1:2:n-1
		X = a + i*h;
		XI0 += f(X);
	endfor

	XI = 2 * h * XI0;
endfunction
