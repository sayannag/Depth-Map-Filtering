#include <opencv\cv.h> 
#include <opencv\highgui.h> 

//using namespace cv;


int main() 
{ 

//	Mat Image;
	
//	VideoCapture cap;
//	cap.open(0);

//while(1)
//{
	
//	cap>>image;
//	imshow("window",image);
	
//}

    int i , j; 
    int b1,b2,g1,g2,r1,r2;
    float sum = 0.0;
    IplImage* input1;   
    IplImage* intput2; 
    
    double psnr;
    
    input1=cvLoadImage("a1.jpg",0);   
    cvNamedWindow("ii",0); 
    cvShowImage("ii",input1); 
    
    input2=cvLoadImage("a2.jpg",0);   
    cvNamedWindow("jj",0); 
    cvShowImage("jj",input2);
    
   // printf("nChannels=%d width=%d  height=%d widthstep=%d  depth=%d  align=%d",input->nChannels,input->width,input->height,input>widthStep,input->depth,input->align);        
    uchar *pinput1   =  (uchar*)input1->imageData; 
    
    uchar *pinput2   =  (uchar*)input2->imageData; 
     
     for(i=0;i<input1->height;i++) 
            {
            	for(j=0;j<input1->width;j++)
				{
					b1= pinput[i*input1->widthStep + j];  
					//g1= pinput[i*input1->widthStep + j*input1->nChannels+1];  
	 				//r1= pinput[i*input1->widthStep + j*input1->nChannels+2]; 
	
	
     				b2= pinput[i*input2->widthStep + j];  
	 			//	g2= pinput[i*input2->widthStep + j*input2->nChannels+1];  
	 			//	r2= pinput[i*input2->widthStep + j*input2->nChannels+2];
	 				
	 				sum += ((b1-b2)*(b1-b2))/(input1->height*input1->width);
	 				
	 			}
	 		}
	 		
	 		printf("MSE: %f", sum);
	 		
	 		
	 		psnr = 20*2.303*log(255.0)-10*2.303*log((double)sum);
	 		
	 		printf("Psnr: %e",psnr);
	 		
	 		 
   		//	cvWaitKey(0); 
   		
   			cvDestroyWindow("ii");
			    
   			cvDestroyWindow( "jj" );
			     
   			cvReleaseImage( &input1 );
			    
    		cvReleaseImage( &input2 ); 
	 		
	 	return 0;	
	 		
	 	}
	 				
	 				
					
    
     
