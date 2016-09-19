input1= imread('F:\KGP-Depth Map\lena_sigma25.png');
imshow(input1);
input1= double(input1);

size(input1)
[m, n]= size(input1);
sigma_s = 25.0;
sigma_r = 2.0;

output=zeros(size(input1));

for i=1:350
    for j=1:350
                input1(i,j)
                bilateral=0.0;
				W=0.0;
				weight = 0.0;
				weight_range = 0.0;
				weight_spatial=0.0;
				weight_range_texture=0.0;
                
                for x=1:m
					for y=1:n
                        if(abs(sqrt((i-x)*(i-x)+(y-j)*(y-j)))<=(6*sigma_s))
                             if (x~=i && y~=j)
                                weight_spatial= weight_spatial+2.303^((-1.0*((x-i)*(x-i)+(y-j)*(y-j)))/(2*sigma_s*sigma_s)); %((x-i)^20+(y-j)^20)/(2*sigma_s*sigma_s);				
                                weight_range=weight_range+tukey(input1(i,j),input1(x,y),sigma_r);
                                %weight_range=weight_range+2.303^(-1.0*(log10(input1(i,j))-log10(input1(x,y)))*(log10(input1(i,j))-log10(input1(x,y)))/(2*sigma_r*sigma_r));
                                weight=weight+ weight_spatial*weight_range;
                                bilateral= bilateral+ weight*(input1(i,j));
                                %bilateral= bilateral+ weight*log10(input1(i,j));
                                W=W+ weight;
                             end
                        end
                    end
                end
				bilateral=bilateral/W;
                %bilateral_new=10.0^(bilateral)
                %bilateral_new = int8(bilateral_new);
                bilateral = uint8(bilateral)
				output(i, j)= bilateral;
                %output(i, j)= bilateral_new;
				%printf("B.F for pixel (%d, %d): %f\n", i, j, bilateral);     
    end
end

%output
K = mat2gray(output);
imshow(K)