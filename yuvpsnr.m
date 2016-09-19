function [PSNR, msemean] = yuvpsnr(File1,File2,width,height,format,parameter)

   
    fwidth = 0.5;
    fheight= 0.5;
    if strcmp(format,'400')
        fwidth = 0;
        fheight= 0;
    elseif strcmp(format,'411')
        fwidth = 0.25;
        fheight= 1;
    elseif strcmp(format,'420')
        fwidth = 0.5;
        fheight= 0.5;
    elseif strcmp(format,'422')
        fwidth = 0.5;
        fheight= 1;
    elseif strcmp(format,'444')
        fwidth = 1;
        fheight= 1;
    else
        display('Error: wrong format');
    end
  
    filep = dir(File1); 
    fileBytes = filep.bytes;
    clear filep
   framenumber1 = fileBytes/(width*height*(1+2*fheight*fwidth)); 

    filep = dir(File1); 
    fileBytes = filep.bytes; 
    clear filep
    framenumber2 = fileBytes/(width*height*(1+2*fheight*fwidth)); 
    if mod(framenumber1,1) ~= 0 | mod(framenumber2,1) ~= 0 | framenumber1~=framenumber2
        display('Error: wrong resolution, format, filesize or different video lengths');
    else
        h = waitbar(0,'Please wait ... ');
        for cntf = 1:framenumber1
            waitbar(cntf/framenumber1,h);
            cntf
            
            YUV1 = loadFileYUV(width,height,cntf,File1,fheight,fwidth);
            YUV2 = loadFileYUV(width,height,cntf,File2,fheight,fwidth);
           
            if parameter == 'y'
                mse1(cntf) = sum(sum((double(YUV1(:,:,1))-double(YUV2(:,:,1))).^2))/(width*height);

            elseif parameter == 'u'
                mse1(cntf) = sum(sum((double(YUV1(:,:,2))-double(YUV2(:,:,2))).^2))/(width*height);
                filename='D:\distortion\mseu.xlsx';xlswrite(filename,mse1);
            elseif parameter == 'v'
                mse1(cntf) = sum(sum((double(YUV1(:,:,3))-double(YUV2(:,:,3))).^2))/(width*height);

            elseif parameter == 'yuv'
                mse1(cntf) = sum((double(YUV1(:))-double(YUV2(:))).^2)/length(YUV1(:));

            end
        end
        
        msemean = (sum(mse1)/length(mse1));
        %psnr 
        if msemean ~= 0
            PSNR = 10*log10((255^2)/msemean)
        else
            PSNR = Inf;
        end
        close(h);
    end