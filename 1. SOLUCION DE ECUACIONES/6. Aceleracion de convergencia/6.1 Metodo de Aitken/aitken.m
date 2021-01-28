function p = aitken(g, p_0)
		p_1 = g(p_0);
		p_2 = g(p_0 + 1);
		p_3 = g(p_0 + 2);
		p = p_1 - (power(p_2 - p_1, 2) / (p_3 - 2*p_2 + p_1) );
endfunction
