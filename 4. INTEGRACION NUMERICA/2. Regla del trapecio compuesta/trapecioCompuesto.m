function XI = trapecioCompuesto(f, a, b, n)
	h = (b - a)/n;
	XI0 = f(a) + f(b);

	X = XI1 = 0;
	for i = 1:n-1
		X = a + i*h;
		XI1 += f(X);
	endfor

	XI = (h/2) * (XI0 + 2*XI1);
endfunction
