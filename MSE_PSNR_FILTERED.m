input1= imread('F:\KGP-Depth Map\NEW_OP_29_6_2016\24-38\depth1frame40_orgbw.jpg');
%imshow(input1);
 %input1(1,1:10)
n=size(input1);
 M=n(1);
 N=n(2);
 
input2=imread('F:\KGP-Depth Map\NEW_OP_29_6_2016\24-38\depthrecV1frame40_bw.jpg');


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
