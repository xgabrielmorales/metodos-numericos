function r = derivadaCentral(i, x, y)
	r = (0.5) * ( ((y(i+1) - y(i)) / (x(i+1) - x(i))) + ((y(i) - y(i-1)) / (x(i) - x(i-1))));
endfunction
