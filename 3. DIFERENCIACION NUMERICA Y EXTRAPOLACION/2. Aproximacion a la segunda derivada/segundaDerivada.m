function r = segundaDerivada(x, y, i)
	h = x(i) - x(i-1);
	r = (y(i+1) - 2*y(i) + y(i-1)) / (h*h);
endfunction
