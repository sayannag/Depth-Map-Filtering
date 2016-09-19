sigma_s=8;
sigma_r=0.5;

T=255;
gamma=pi/(2*T);
row=gamma*sigma_r;
if (sigma_r> (gamma^(-2)))
    N= 10 ^5
else
    N= row^(-2);
end

input1= imread('F:\KGP-Depth Map\lena_200x200.jpg');
input1 = double (input1);
imshow(input1);

[m, n]= size(input1);
sigma_s = 10.0;
sigma_r = 0.5;

output=zeros(size(input1));

for i=1:m
    for j=1:n
                input1(i,j)
                bilateral=0.0;
				W=0.0;
				weight = 0.0;
				weight_range = 0.0;
				weight_spatial=0.0;
				weight_range_texture=0.0;
                
                for x=1:m
					for y=1:n
						if (x~=i && y~=j && ((x-i)*(x-i)+(y-j)*(y-j))<=4*sigma_s*sigma_s)
							weight_spatial= weight_spatial +2.303^((-1.0*(double((x-i)*(x-i)+(y-j)*(y-j))))/(2*sigma_s*sigma_s));				
						 	weight_range= weight_range+ cos (gamma* (input1(i, j)- input1(x, y))/(row*sqrt(N)))^N;
							weight= weight+ weight_spatial*weight_range;
							bilateral= bilateral+ weight*(input1(i,j));
							W=W+ weight;
                        end
                    end
                end
				bilateral=(bilateral/W);
                bilateral_new=(bilateral);
                bilateral_new= uint8(bilateral_new)
				output(i, j)= bilateral_new;
				%printf("B.F for pixel (%d, %d): %f\n", i, j, bilateral);     
    end
end

%output
K= mat2gray (output);
imshow(K)