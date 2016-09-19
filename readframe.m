clc;
clear all;
close all;

cam_no1 = 2;
cam_no2 = 4;

cam1=num2str(cam_no1);
cam2=num2str(cam_no2);

sequence = 'Ballet';
frame_no = 0;
fr_no_new = num2str(frame_no);

cd(strcat('D:\Research\vij\Original\',sequence,'\Cam',cam1,'_Original'));
in1 = imread(strcat('color-cam',cam1,'-f00',fr_no_new,'.bmp'));
imshow(in1);

