function yuv_export(Y,U,V,filename,numfrm,mode)

if nargin<6  
    mode = 'a'; 
end;
fid=fopen(filename,mode);
if (fid < 0) 
    error('Could not open the file!');
end;
for i=1:numfrm
    Yd = Y{i}';
    fwrite(fid,Yd,'uint8');    
    UVd = U{i}';  
    fwrite(fid,UVd,'uint8');
    UVd = V{i}'; 
    fwrite(fid,UVd,'uint8');   
end;
fclose(fid);