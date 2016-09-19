input1= imread('F:\KGP-Depth Map\bridge_shotnoise_10percent.jpg');
%imshow(input1);
input1= double(input1);

size(input1)
[m, n]= size(input1);
output=zeros(size(input1));
g=pi/(2.0*255.0);
f=0.0;
for i=2:m-1
    for j=2:n-1                
                    input1(i,j)
%                       a=sin((input1(i,j)-input1(i+1,j))/g)*sin((input1(i,j)-input1(i+1,j))/g);
%                       b=sin((input1(i,j)-input1(i,j+1))/g)*sin((input1(i,j)-input1(i,j+1))/g);
%                     f=input1(i,j)+(a*(input1(i-1,j)+(1-a)*input1(i+1,j)-1.0*input1(i,j))/(1.0*(1+2.303^(-10000.0*(input1(i,j)-input1(i-1,j))*(input1(i,j)-input1(i+1,j)))))+(b*input1(i,j-1)+(1-b)*input1(i,j+1)-1.0*input1(i,j))/(1.0*(1+2.303^(-10000.0*(input1(i,j)-input1(i,j-1))*(input1(i,j)-input1(i,j+1))))))/2.0;
                    f=input1(i,j)+((input1(i-1,j)+input1(i+1,j)-2.0*input1(i,j))/(2.0*(1+2.303^(-10000.0*(input1(i,j)-input1(i-1,j))*(input1(i,j)-input1(i+1,j)))))+(input1(i,j-1)+input1(i,j+1)-2.0*input1(i,j))/(2.0*(1+2.303^(-10000.0*(input1(i,j)-input1(i,j-1))*(input1(i,j)-input1(i,j+1))))))/2.0;
%                     max=0.0;
%                     c=0;
%                     sum=0.0;
%                     for x=1:m
%                         for y=1:n
%                             if(abs(i-x)<=2&&abs(y-j)<=2)
%                               if (x~=i && y~=j)
%                                   if(input1(x,y)~=0)
%                                   sum=sum+input1(x,y);
%                                   c=c+1;
%                                   end
%                                   if(max<=input1(x,y))
%                                         max=input1(x,y);
%                                   end
%                               end
%                             end
%                         end
%                     end
%                     sum=sum/c;
%                     f=0.8*max+0.2*sum;
%                 end
                output(i,j)=uint8(f);
    end
end

%output
 K = mat2gray(output);
 output=getframe; 
 imwrite(K,'F:\KGP-Depth Map\NEW_OP_29_6_2016\bridge_shotnoise_10percent_proposed_op.jpg');