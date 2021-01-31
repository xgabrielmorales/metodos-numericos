function XI = simpleSimpson38(f, a, b)
	h = (b - a) / 3;

	x1 = a + h;
	x2 = x1 + h;

	XI = (0.375) * h * (f(a) + 3*f(x1) + 3*f(x2) + f(b));
endfunction
