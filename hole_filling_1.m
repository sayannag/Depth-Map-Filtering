input1= imread('F:\KGP-Depth Map\DepthImagekinnect1.png');
%imshow(input1);
input1= double(input1);

size(input1)
[m, n]= size(input1);
%sigma_s = 10.0;
%sigma_r = 2.0;
r=10;
c=10;
output=zeros(size(input1));


for i=1:m
    for j=1:n
                f=input1(i,j);
%                 bilateral=0.0;
% 				W=0.0;
% 				weight = 0.0;
% 				weight_range = 0.0;
% 				weight_spatial=0.0;
% 				weight_range_texture=0.0;
                
%                 for x=1:m
% 					for y=1:n
%                         if(abs(sqrt((i-x)*(i-x)+(y-j)*(y-j)))<=(6*sigma_s))
%                              if (x~=i && y~=j)
%                                 weight_spatial= weight_spatial+2.303^((-1.0*((x-i)*(x-i)+(y-j)*(y-j)))/(2*sigma_s*sigma_s)); %((x-i)^20+(y-j)^20)/(2*sigma_s*sigma_s);				
%                                 weight_range=weight_range+2.303^(-1.0*((input1(i,j))-(input1(x,y)))*((input1(i,j))-(input1(x,y)))/(2*sigma_r*sigma_r));
%                                 %weight_range=weight_range+2.303^(-1.0*(log10(input1(i,j))-log10(input1(x,y)))*(log10(input1(i,j))-log10(input1(x,y)))/(2*sigma_r*sigma_r));
%                                 weight=weight+ weight_spatial*weight_range;
%                                 bilateral= bilateral+ weight*(input1(i,j));
%                                 %bilateral= bilateral+ weight*log10(input1(i,j));
%                                 W=W+ weight;
%                              end
%                         end
%                     end
%                 end
% 				bilateral=bilateral/W;
%                 %bilateral_new=10.0^(bilateral)
%                 %bilateral_new = int8(bilateral_new);
%                 bilateral = int8(bilateral)
% 				output(i, j)= bilateral;
%                 %output(i, j)= bilateral_new;
% 				%printf("B.F for pixel (%d, %d): %f\n", i, j, bilateral);
                if(input1(i,j)==0)
                    input1(i,j)
                    max=0.0;
                    c=0;
                    sum=0.0;
                    for x=1:m
                        for y=1:n
                            if(abs(i-x)<=2&&abs(y-j)<=2)
                              if (x~=i && y~=j)
                                  if(input1(x,y)~=0)
                                  sum=sum+input1(x,y);
                                  c=c+1;
                                  end
                                  if(max<=input1(x,y))
                                        max=input1(x,y);
                                  end
                              end
                            end
                        end
                    end
                    sum=sum/c;
                    %f=0.8*max+0.2*sum;
                    f=max;
                end
                output(i,j)=uint8(f);
    end
end

%output
 K = mat2gray(output);
imshow(K)