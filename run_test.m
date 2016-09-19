clc
clear

% read the image
A=double(loadFileYUV(1024,768,1,'F:\33-47\depth_recV1.0000.yuv',1,1))/255;
C=double(loadFileYUV(1024,768,1,'F:\image_proc-kgp\depth100\depth1.yuv',1,1))/255;
% A = A+0.1*randn(size(A));
% A(A<0) = 0; A(A>1) = 1;
Y = A(:,:,1);
U = A(:,:,2);
V = A(:,:,3);
Y1 = C(:,:,1);
U1 = C(:,:,2);
V1 = C(:,:,3);
imshow(Y);
imwrite(Y,'F:\KGP-Depth Map\NEW_OP_30_6_2016_KENDO\33-47\depthrecV1frame1_bw.jpg');
imwrite(Y1,'F:\KGP-Depth Map\NEW_OP_30_6_2016_KENDO\33-47\depth1frame1_orgbw.jpg');
 % apply the filter
   B = bilateral_filter1(Y,3,2,30);
   
   figure;
   imshow(B)
    %output=getframe;  
   imwrite(B,'F:\KGP-Depth Map\NEW_OP_30_6_2016_KENDO\33-47\bfdepth1frame1triwtcos.jpg');
   
   input1= imread('F:\KGP-Depth Map\NEW_OP_30_6_2016_KENDO\33-47\depth1frame1_orgbw.jpg');
%imshow(input1);
 %input1(1,1:10)
n=size(input1);
 M=n(1);
 N=n(2);
 
input2=imread('F:\KGP-Depth Map\NEW_OP_30_6_2016_KENDO\33-47\bfdepth1frame1triwtcos.jpg');


% input2(1,2)
%input2(1,1:10)
%input2=imresize(input,[M N]);
%imshow(input2);
%size(input2)
 
 %x=(input1-input2).^2;
 %x(1, 1:10);
%  sum=0.0;
%  loop=0;
%  for i=1:2
%      for j=1:11
%          fprintf('%d\t%d',input1(i, j), input2(i, j));
%          
%          x=(input1(i, j)- input2(i, j))^2
% %          fprintf('x: %d\t', x*x);
% %          sum= sum+ x*x/M*N;
%          loop=loop+1;
%      end
%  end
 
 %fprintf('loop: %d', loop);
 %fprintf('sum: %f', sum);
 
 %(input1-input2).^2
 %((input1-input2).^2)/(M*N)
 %MSE1 = sum(((input1(:, :, 3)-input2(:, :, 3)).^2)/(M*N));
 
 MSE = sum(sum((double(input1)-double(input2(:, :, :))).^2))/(M*N);
 PSNR = 10*log10(255*255/MSE);
 %PSNR= psnr(input1, input2);
 fprintf('\nMSE: %7.2f ', MSE);
 %fprintf('\nMSE1: %7.2f ', MSE1);
 fprintf('\nPSNR: %9.7f dB', PSNR);
%  i1=input1(1:8, 1:8)
%  sum(sum(i1))/64