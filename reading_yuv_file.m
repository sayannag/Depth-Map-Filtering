function Y=reading_yuv_file(input_file)
nFrame=100;
fid = fopen(input_file,'r');
% nRow=144;
% nColumn=176;
%checking whether the file is qcif or cifs
nRow = 768;
nColumn = 1024;

% end of checking
%Reading the File
for i = 1: nFrame
    %reading Y component 
	img_y= fread(fid, nRow * nColumn, 'uchar');            
    img_y= reshape(img_y , nColumn , nRow );
    img_y = img_y';
%     figure;
%     imshow(uint8(img_y));
    %yout=sprintf('Y_Frame%d',i);
%     yout=[YOutRootname,num2str(i)];
  
%     save(yout,'img_y');
     Y(:,:,i)=img_y(:,:);
   
%     youtT=[yout,'.txt'];
%     save(youtT,'img_y','-ASCII');
      

    %reading U component    
    img_u = fread(fid, nRow * nColumn / 4, 'uchar');
    img_u = reshape(img_u, nColumn/2, nRow/2);
    img_u = img_u';
    U(:,:,i)=img_u(:,:);
    %uout=sprintf('U_Frame%d',i);
%     uout=[UOutRootname,num2str(i)];
%     save(uout,'img_u');
     
    %reading V component
    img_v = fread(fid, nRow * nColumn / 4, 'uchar');
    img_v = reshape(img_v, nColumn/2, nRow/2);
    img_v = img_v';
    V(:,:,i)=img_v(:,:);
    %vout=sprintf('V_Frame%d',i);
%     vout=[VOutRootname,num2str(i)];
%     save(vout,'img_v'); 
 
end