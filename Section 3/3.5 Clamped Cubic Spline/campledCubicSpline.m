function campledCubicSpline(n, x, a, FPO, FPN)
	h   = zeros(1, n);
	alp = zeros(1, n+1);
	l   = zeros(1, n+1);
	m   = zeros(1, n+1);
	z   = zeros(1, n+1);
	c   = zeros(1, n+1);
	d   = zeros(1, n);
	b   = zeros(1, n);

	for i = 1:n
		h(i) = x(i+1) - x(i);
	endfor

	alp(1) = ((3.0 * (a(2) - a(1))) / h(1)) - (3.0 * FPO);
	alp(n+1) = (3.0 * FPN) - ((3.0 * (a(n+1) - a(n))) / h(n));

	for i=2:n
		alp(i) = (3.0 / h(i)) * (a(i+1) - a(i)) - (3.0 / h(i-1)) * (a(i) - a(i-1));
	endfor

	l(1) = 2 * h(1);
	m(1) = 0.5;
	z(1) = alp(1) / l(1);

	for i = 2:n
		l(i) = 2 * (x(i+1) - x(i-1)) - (h(i-1) * m(i-1));
		m(i) = h(i) / l(i);
		z(i) = (alp(i) - h(i-1) * z(i-1)) / l(i);
	endfor

	l(n+1) = h(n) * (2 - m(n));
	z(n+1) = (alp(n+1) - (h(n) * z(n))) / l(n+1);
	c(n+1) = z(n+1);

	for j = n:-1:1
		c(j) = z(j) - m(j) * c(j + 1);
		b(j) = ((a(j+1) - a(j))/h(j)) - (h(j) * (c(j+1) + 2.0 * c(j)) / 3.0);
		d(j) = (c(j+1) - c(j)) / (3*h(j));
	endfor

	for j = 1:n
		printf("a_{%d} = %f\t", j, a(j));
		printf("b_{%d} = %f\t", j, b(j));
		printf("c_{%d} = %f\t", j, c(j));
		printf("d_{%d} = %f\t", j, d(j));
		printf("\n");
	endfor
endfunction
