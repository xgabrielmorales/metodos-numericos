function r = cuadraturaLobatto(f, a, b, x, w, n)
	G = zeros(1, n);
	for i = 1:n
		G(i) = ((b-a) * x[i] + a + b)/2;
	endfor

	suma = 0;
	for i = 2:n-1
		suma += w(i) * f(G(i));
	endfor

	return (b - a) * (0.5) * (w(1) * f(G(1)) + w(n) * f(G[n]) + suma);
endfunction
