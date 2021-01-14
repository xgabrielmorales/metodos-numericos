function bezierCurve(n, x, y, xPlus, yPlus, xMinus, yMinus)
	a_0 = zeros(1, n);
	a_1 = zeros(1, n);
	a_2 = zeros(1, n);
	a_3 = zeros(1, n);

	b_0 = zeros(1, n);
	b_1 = zeros(1, n);
	b_2 = zeros(1, n);
	b_3 = zeros(1, n);

	for i = 1:n
		a_0(i) = x(i);
		b_0(i) = y(i);

		a_1(i) = 3 * (xPlus(i) - x(i));
		b_1(i) = 3 * (yPlus(i) - y(i));

		a_2(i) = 3 * (x(i) + xMinus(i) - 2 * xPlus(i));
		b_2(i) = 3 * (y(i) + yMinus(i) - 2 * yPlus(i));

		a_3(i) =  x(i+1) - x(i) + 3 * xPlus(i) - 3 * xMinus(i);
		b_3(i) =  y(i+1) - y(i) + 3 * yPlus(i) - 3 * yMinus(i);

		printf("a_0\ta_1\ta_2\ta_3\n");
		printf("%.3f %.3f %.3f %.3f\n", a_0(i), a_1(i), a_2(i), a_3(i));

		printf("b_0\tb_1\tb_2\tb_3\n");
		printf("%.3f %.3f %.3f %.3f\n", b_0(i), b_1(i), b_2(i), b_3(i));

	endfor
endfunction
