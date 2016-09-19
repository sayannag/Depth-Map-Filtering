function Out = bilateral_filter1(In,N,sigma_d,sigma_r)

N1=1;
T=255;
gamma=pi/(2*T);
row=gamma*sigma_r;
if (sigma_r> (gamma^(-2)))
    N1 = 10^1
else
    N1= row^(-2);
end




%
Len = size(In);
Out = zeros(Len);


[X,Y] = meshgrid(-N:N,-N:N);
G = exp(-(X.^2+Y.^2)/(2*sigma_d^2));



for i = 1:Len(1)
    
          
         iMin = max(i-N,1);
         iMax = min(i+N,Len(1));
         
   for j = 1:Len(2)
      
         
         jMin = max(j-N,1);
         jMax = min(j+N,Len(2));
         
         I = In(iMin:iMax,jMin:jMax,:);
      
         dL = I(:,:,1)-In(i,j,1);
%             da = I(:,:,2)-In(i,j,2);
%             db = I(:,:,3)-In(i,j,3);
            % H = exp(-(dL.^2+da.^2+db.^2)/(2*sigma_r^2));
      %   H = (0.5*(1-(dL.^2)/(sigma_r*sigma_r)).^3).*(cos (gamma* (dL)/(row*sqrt(N1)))); 
       %    H=(cos (gamma* (dL)/(row*sqrt(N1))));
%              H=0.0;
%              if(abs(dL)<=sigma_r)
%              H = 0.5*(1-(dL.^2)/(sigma_r*sigma_r)).^2;
%              end
         
           H =exp(-(dL.^2)/(2*sigma_r^2));
      

         tmp = H.*G((iMin:iMax)-i+N+1,(jMin:jMax)-j+N+1);
         norm_tmp = sum(tmp(:));
         Out(i,j,1) = sum(sum(tmp.*I(:,:,1)))/norm_tmp;
%           Out(i,j,2) = sum(sum(tmp.*I(:,:,2)))/norm_tmp;
%           Out(i,j,3) = sum(sum(tmp.*I(:,:,3)))/norm_tmp;
                
   end
end
