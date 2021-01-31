function XI = SimpsonRule(f, a, b, n)
	h = (b - a) / n;
	XI0 = XI1 = XI2 = 0;

	for i = 0:2:n-1
		X = a + i * h;
		XI0 += f(X);
	endfor

	for i = 1:2:n-1
		X = a + i * h;
		XI1 += f(X);
	endfor

	for i = 2:2:n
		X = a + i * h;
		XI2 += f(X);
	endfor

	XI = (h/3) * (XI0 + 4*XI1 + XI2);
endfunction
