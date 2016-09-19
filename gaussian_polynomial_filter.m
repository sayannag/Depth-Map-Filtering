img1= imread ('F:\KGP-Depth Map\lena_200x200.jpg');
%imshow(img1);
img1 = double (img1);

%x= impixel(img1)
%[m, n]= size(img1);
m=10;
n=10;
% for i=1:10
%     for j=1:10
%         fprintf('%d\t', img1(i, j));
%     end
%     fprintf('\n');
% end
u=sum(sum(img1));
t= 1/(m*n)*u;

sigma_r= 2.0*10^4.5;
sigma_s= 10.0;

%h=zeros(m, n);
%G=zeros(m, n);
%F=zeros(m, n);
%P=zeros(m, n);
%Q=zeros(m, n);
%H=zeros(m, n);
%F_bar=zeros(m, n);
f_output=zeros(m, n);

N=10;

for i=1:100
    for j=1:100

        h = t- img1(i, j)
        G = 1.0;
        F = (2.303^(- (h*h)/(2*sigma_r^2)));
        P = 0.0;
        Q = 0.0;
        F_bar = 0.0;
        H = h/sigma_r;
       % F_bar = convol(m, n, i, j, sigma_s, sigma_r, img1, t); 
    for x=1:m
        for y=1:n
            if (((i-x)^2+ (j-y)^2)<=6*sigma_s)
                if(i~=x && j~=y)
                    h=t- img1(i, j);
                    F=(2.303^(- (h*h)/(2*sigma_r^2)));
                    F_bar=F_bar + 2.303^(((i-x)^2+ (j-y)^2)/(2*sigma_s^2)) * 2.303^(-F^2/(2*sigma_r^2));
                end
            end
        end
    end
        
        c=1.0;
        for loop=1:N
            Q = Q + c*G*F_bar;
            F = H*F;
            F_bar=0.0;
            %F_bar = convol(m, n, i, j, sigma_s, sigma_r, img1, t);
    for x=1:m
        for y=1:n
            if (((i-x)^2+ (j-y)^2)<=6*sigma_s)
                if(i~=x && j~=y)
                    h=t- img1(i, j);
                    F=(2.303^(- (h*h)/(2*sigma_r^2)));
                    F_bar=F_bar + 2.303^(((i-x)^2+ (j-y)^2)/(2*sigma_s^2)) * 2.303^(-F^2/(2*sigma_r^2));
                end
            end
        end
    end
            P=P+ c*G*F_bar;
            G=H*G;
            c=c/(loop+1);
        end
        
        f_filter= (sigma_r* P/Q + t)/(2.303*10^3)
        f_output(i,j) = int8(f_filter);
    end
end

%f_filter= int8(f_filter);
K= mat2gray (f_output);
imshow(K)