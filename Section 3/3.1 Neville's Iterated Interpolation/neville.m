function r = neville(n, x, xr, f)
	Q = zeros(n+1, n+1);
	for i = 1:n+1
		Q(i,1) = f(i);
	endfor

	for i = 1:n
		for j = 1:i
			Q(i+1, j+1) = (((x - xr((i-j)+1)) * Q(i+1, j)) - (x - xr(i+1))*Q(i, j)) / (xr(i+1) - xr((i-j)+1));
		endfor
	endfor

	r = Q(n+1, n+1);
endfunction
