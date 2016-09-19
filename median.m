I = imread('F:\KGP-Depth Map\bridge_shotnoise_10percent.jpg');

a = double(I)/255;
b = a;
[row, colm] = size(a);
for i = 2:1:row-1
    for j = 2:1:colm-1
        f=a(i,j)+((a(i-1,j)+a(i+1,j)-2.0*a(i,j))/(2.0*(1+2.303^(-10000.0*(a(i,j)-a(i-1,j))*(a(i,j)-a(i+1,j)))))+(a(i,j-1)+a(i,j+1)-2.0*a(i,j))/(2.0*(1+2.303^(-10000.0*(a(i,j)-a(i,j-1))*(a(i,j)-a(i,j+1))))))/2.0;
        a1 = [a(i-1,j-1) a(i-1,j) a(i-1,j+1) a(i,j-1) a(i,j) a(i,j+1)...
        a(i+1,j-1) a(i+1,j) a(i+1,j+1)];
        a2 = sort(a1);
        med = a2(5); % the 5th value is the median 
       %f=input1(i,j)+((input1(i-1,j)+input1(i+1,j)-2.0*input1(i,j))/(2.0*(1+2.303^(-10000.0*(input1(i,j)-input1(i-1,j))*(input1(i,j)-input1(i+1,j)))))+(input1(i,j-1)+input1(i,j+1)-2.0*input1(i,j))/(2.0*(1+2.303^(-10000.0*(input1(i,j)-input1(i,j-1))*(input1(i,j)-input1(i,j+1))))))/2.0;
        b(i,j) = (0.9*med+0.1*f);
    end
end
figure; 
imwrite(b,'F:\KGP-Depth Map\NEW_OP_29_6_2016\bridge_shotnoise_10percent_median_modified_op.jpg');