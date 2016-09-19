function [Y,U,V]=rgb2yuv(R,G,B,yuvformat,convmtrx)


if (nargin < 4)
    yuvformat = 'YUV444_8';
end;
if (nargin < 5)
    convmtrx = 'BT709_l';
end;
if (strcmp(yuvformat,'YUV420_8') && (exist('imresize','file') ~= 2))
    error('For YUV420 subsampling rgb2yuv requires Image Processing Toolbox (TM) function imresize!');
end;

if strcmp(convmtrx,'BT601_f')
   load('BT601_f.mat','-mat');
elseif strcmp(convmtrx,'BT601_l')
   load('BT601_l.mat','-mat');
elseif strcmp(convmtrx,'BT601_219')
   load('BT601_219.mat','-mat');
elseif strcmp(convmtrx,'BT709_f')
   load('BT709_f.mat','-mat');
elseif strcmp(convmtrx,'BT709_l')
   load('BT709_l.mat','-mat');
elseif strcmp(convmtrx,'SMPTE_240M')
   load('SMPTE_240M.mat','-mat');
end;

T = rgb2yuvT;
R = double(R);
G = double(G);
B = double(B);
Y = T(1,1) * R + T(1,2) * G + T(1,3) * B + yuvoffset(1);
U = T(2,1) * R + T(2,2) * G + T(2,3) * B + yuvoffset(2);
V = T(3,1) * R + T(3,2) * G + T(3,3) * B + yuvoffset(3);
if (strcmp(yuvformat,'YUV420_8'))
    U = imresize(U,0.5,'bicubic');
    V = imresize(V,0.5,'bicubic');
elseif (strcmp(yuvformat,'YUV444_8'))
%do nothing, already in the correct subsampling format
end;
Y = uint8(round(Y));
U = uint8(round(U));
V = uint8(round(V));

