function r = trapecioSimple(f, a, b, n)
	h = (b - a)/n;
	r = (0.5) * h * (f(a) + f(b));
endfunction
