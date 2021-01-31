function XI = compositeSimpson38(f, a, b, n)
	h = (b - a)/n;
	XI0 = f(a) + f(b);
	X = XI1 = XI2 = XI3 = 0;

	for i = 1:3:n-2
		X = a + i*h;
		XI1 += f(X);
	endfor
	for i = 2:3:n-1
		X = a + i*h;
		XI2 += f(X);
	endfor
	for i = 2:3:n-3
		X = a + i*h;
		XI3 += f(X);
	endfor
	XI = (0.375) * h * (XI0 + 3*XI1 + 3*XI2 + 2*XI3);
endfunction
