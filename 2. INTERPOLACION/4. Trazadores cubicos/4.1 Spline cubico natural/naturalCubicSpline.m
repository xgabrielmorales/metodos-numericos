function naturalCubicSpline(n, x, a)
	h   = zeros(1, n);
	alp = zeros(1, n);
	l   = zeros(1, n+1);
	m   = zeros(1, n+1);
	z   = zeros(1, n+1);
	c   = zeros(1, n+1);
	d   = zeros(1, n);
	b   = zeros(1, n);

	for i = 1:n
		h(i) = x(i+1) - x(i);
	endfor

	for i=2:n
		alp(i) = (3.0 / h(i)) * (a(i+1) - a(i)) - (3.0 / h(i-1)) * (a(i) - a(i-1));
	endfor


	l(1) = 1;
	m(1) = 0;
	z(1) = 0;

	for i = 2:n
		l(i) = 2 * (x(i+1) - x(i-1)) - (h(i-1) * m(i-1));
		m(i) = h(i) / l(i);
		z(i) = (alp(i) - h(i-1) * z(i-1)) / l(i);
	endfor

	l(n+1) = 1;
	z(n+1) = 0;
	c(n+1) = 0;

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
