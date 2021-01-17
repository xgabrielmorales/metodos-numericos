function APP = adaptativeQuadrature(f, A, B, tol, n)
	TOL = zeros(1, n);
	a   = zeros(1, n);
	h   = zeros(1, n);
	FA  = zeros(1, n);
	FB  = zeros(1, n);
	FC  = zeros(1, n);
	S   = zeros(1, n);
	L   = zeros(1, n);
	v   = zeros(1, 8);

	APP = 0;
	i = 1;

	TOL(i) = 10 * tol;
	a(i) = A;
	h(i) = (B - A) / 2;

	FA(i) = f(A);
	FC(i) = f(A + h(i));
	FB(i) = f(B);

	S(i) = h(i) * (FA(i) + 4*FC(i) + FB(i)) / 3;

	L(i) = 1;

	while i > 0
		FD = f(a(i) + h(i)/ 2);
		FE = f(a(i) + (3*h(i))/2);

		S1 = h(i) * (FA(i) + 4*FD + FC(i)) / 6;
		S2 = h(i) * (FC(i) + 4*FE + FB(i)) / 6;

		v(1) = a(i);
		v(2) = FA(i);
		v(3) = FC(i);
		v(4) = FB(i);
		v(5) = h(i);
		v(6) = TOL(i);
		v(7) = S(i);
		v(8) = L(i);

		i++;

		if(abs(S1 + S2 - v(6)))
			APP += (S1 + S2);
		else
			if v(8) >= n
				break;
			else
				i++;
				a(i)   = v(1) + v(5);
				FA(i)  = v(3);
				FC(i)  = FE;
				FB(i)  = v(4);
				h(i)   = v(5)/2;
				TOL(i) = v(6)/2;
				S(i)   = S2;
				L(i)   = v(8) + 1;

				i++;

				a(i)   = v(1);
				FA(i)  = v(2);
				FC(i)  = FD;
				FB(i)  = v(2);
				h(i)   = h(i-1);
				TOL(i) = TOL(i-1);
				S(i)   = S1;
				L(i)   = L(i-1);
			endif
		endif
	endwhile
endfunction
