function sum= convol(m, n, img1_x, img1_y, sigma_s, sigma_r, x, t)

sum=0.0;
for i=1:m
    for j=1:n
      if (((i-img1_x)^2+ (j-img1_y)^2)<=3*sigma_s)
          if(i~=img1_x && j~=img1_y)
             h=t- x(i, j)
             F=(2.303^(- h^2/(2*sigma_r^2)))
             sum=sum + 2.303^(((i-img1_x)^2+ (j-img1_y)^2)/(2*sigma_s^2)) * 2.303^(-F^2/(2*sigma_r^2));
          end
       end
    end
end




