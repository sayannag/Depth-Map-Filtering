A=double(loadFileYUV(1024,768,1,'F:\33-47\depth_recV1.0000.yuv',1,1))/255;
size(A)
Y = A(:,:,1);
U = A(:,:,2);
V = A(:,:,3);
size(Y)
size(U)
size(V)
figure;
imshow(A)
% C = yuv2rgb(Y,U,V,'YUV444_8');
% size(C)

% %[a,b]=yuvpsnr('F:\33-47\depth_recV1.0000.yuv','F:\image_proc-kgp\depth100\depth1.yuv',1024,768,'420','y')
% Y = bilateral_filter(A,3,1,10);
% 
% %figure;
% %output=getframe; 
% %imwrite(B,'F:\KGP-Depth Map\NEW_OP_29_6_2016\depth_recV1.0000_op2_bf.yuv');
% yuv_export(Y,U,V,'F:\33-47\depth_recV1.0000_op.yuv',1);