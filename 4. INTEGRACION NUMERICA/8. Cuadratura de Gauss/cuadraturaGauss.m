function XI = cuadraturaGauss(f, a, b)
	gt  = ((b - a) * (-sqrt(3)/3) + a + b) * (0.5);
	gpt = ((b - a) * ( sqrt(3)/3) + a + b) * (0.5);

	XI = (b-a) * (0.5) * (f(gt) + f(gpt));
endfunction
