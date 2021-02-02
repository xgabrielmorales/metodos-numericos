function r = cuadraturaKronrod(f, a, b, n, x, w)
	G = zeros(1, n);
	suma = 0;

	for i = 1:n
		G(i) = ((b-a) * x(i) + a + b)/2;
		suma += w(i) * f(G(i));
	endfor

	r = (b-a) * (0.5) * suma;
endfunction
