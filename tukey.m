function kernel=tukey(a,b,r)

kernel=0.0;

kernel = 0.5*(1-(a-b)*(a-b)/(r*r))^2;

end