function r = dividedDifference(n, xr, f)
	F = zeros(n+1, n+1);
	for i=0:n
		F(i+1, 1) = f(i+1);
	endfor

	for i=1:n
		for j=1:n
			if (i-j) < 0
				tmp = 0;
			else
				tmp = xr(i-j+1);
			endif
			F(i+1, j+1) = (F(i+1, j) - F(i, j)) / (xr(i+1) - tmp);
		endfor
	endfor

	r = zeros(n+1);
	for i=0:n
		r(i+1, i+1) = F(i+1, i+1);
	endfor
endfunction
