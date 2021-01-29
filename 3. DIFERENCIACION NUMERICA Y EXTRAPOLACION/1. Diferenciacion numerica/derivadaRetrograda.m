function r = derivadaRetrograda(i, x, y)
	r = (y(i) - y(i-1)) / (x(i) - x(i-1));
endfunction
