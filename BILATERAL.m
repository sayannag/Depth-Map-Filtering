input1= imread('F:\KGP-Depth Map\depth_wine.jpg');
input1 = double (input1);
% imshow(input1);
% set(gca,'position',[0 0 1 1],'units','normalized');

[m, n]= size(input1);
sigma_s = 10.0;
sigma_r = 0.5;

output=zeros(size(input1));

N=5 ; %window size

for i=1:m
    
    iMin = max(i-N,1);
    iMax = min(i+N,m);
    
    for j=1:n
                
        jMin = max(j-N,1);
        jMax = min(j+N, n);
        
        I = input1(iMin:iMax,jMin:jMax);
        
        bilateral=0.0;
		W=0.0;
		weight = 0.0;
		weight_range = 0.0;
		weight_spatial=0.0;
				%weight_range_texture=0.0;
                
                for x=iMin:iMax
					for y=jMin:jMax
						if (x~=i && y~=j && ((x-i)*(x-i)+(y-j)*(y-j))<=4*sigma_s*sigma_s)
							weight_spatial= weight_spatial +2.303^((-1.0*(double((x-i)*(x-i)+(y-j)*(y-j))))/(2*sigma_s*sigma_s));				
						 	weight_range= weight_range+2.303^((-1.0* (input1(i,j)-input1(x,y))*(input1(i,j)-input1(x,y)))/(2*sigma_r*sigma_r));
                            %weight_range= weight_range+2.303^((-1.0* (log10(input1(i,j))-log10(input1(x,y)))*(log10(input1(i,j))-log10(input1(x,y))))/(2*sigma_r*sigma_r));
							weight= weight+ weight_spatial*weight_range;
							bilateral= bilateral+ weight* input1(i,j);
							W=W+ weight;
                        end
                    end
                end
				bilateral=uint8(bilateral/W);
                %bilateral_new=10^(bilateral);
                %bilateral_new= int8(bilateral_new);
				%output(i, j)= bilateral_new;
				%printf("B.F for pixel (%d, %d): %f\n", i, j, bilateral);
                output(i, j)= bilateral;
    end
end

%output
K= mat2gray (output);
output=getframe; 
imwrite(K,'F:\KGP-Depth Map\NEW_OP_29_6_2016\test1.jpeg');

%set(gca,'position',[0 0 1 1],'units','normalized');
%iptsetpref('ImshowBorder','tight');
%imshow(K);


%removes menu and toolbar from all new figures
%>>set(0,'DefaultFigureMenu','none');
%makes disp() calls show things without empty lines
%>>format compact;