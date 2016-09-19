#include <conio.h>
#include <stdio.h>
#include<math.h>

#define ly 1024
#define wy 768
#define c1 (0.01*0.01*255*255)
#define c2 (0.03*0.03*255*255)


int main()
{
	
	FILE *file1, *file2, *file3;//, *file3, *file4, *file5, *file6; //*fout;
  	
  	int leny,lenu,lenv;
  	leny = ly*wy;
  	lenu = leny/4;
  	lenv = leny/4;
  	int p,q;
  	float psnr;
  	file1 = fopen("F:/image_proc-kgp/depth100/depth3.yuv","r");
  	file2 = fopen("F:/33-47/depth_recV3.0000.yuv", "r");  //F:/24-38/depth_recV3.0000
  	
  	file3 = fopen("F:/SSIM_Results/33-47_depth3.txt","w");
  	
  	

  /* Check the file size */
  fseek(file1, 0 ,SEEK_END);
  int file_size = ftell(file1);
  int frame_count = ( file_size /(leny+lenu+lenv) ); 
  //printf("%d ", frame_count);

  
unsigned char var1, var2;
  	
  	int i;
 
  

rewind (file1);
rewind (file2);

//double sq_sum1=0.0, sq_sum2=0.0, variance1, variance2;

float sum1=0.0, sum2=0.0;
float mse=0.0, mse_mean=0.0, sum1_mean=0.0, sum2_mean=0.0;
int loop,index;
//fseek(file2, 89*(leny+lenu+lenv), SEEK_CUR);
/*for (i=0; i<10; i++)
	{
		
		fscanf(file2, "%c", &var2);	
		printf("%f\t", (float)var2);
	}
*/
int x, j;
int arr1[260],arr2[260];
float sq_sum1, sq_sum2, sq_sum12, ssim_bl, ssim_fr=0.0; 
int blocksize=16;
int r;
int no_of_blocks= leny/(blocksize*blocksize);
//printf("%d\t", no_of_blocks);



fprintf(file3,"FRAME\t");
fprintf(file3,"  MSE\t\t");
fprintf(file3,"  PSNR\t\t");
fprintf(file3,"  SSIM\n");


//frame_count = 10;
for (loop=0; loop<frame_count; loop++)
{
	//ssim_fr=0.0;
	mse=0.0;
	sum1=0.0;
	sum2=0.0;
	for (i=0; i<leny; i++)
	{
		////loop++;
		fscanf(file1, "%c", &var1);
		fscanf(file2, "%c", &var2);	
		//printf("%f\t", (float)var1);
		sum1+=((float)var1)/((float)leny);
		//printf("%f\t", sum1);
		sum2+=((float)var2)/((float)leny);
		//printf("%f\t", (float)var2);
		//printf("%f\t", sum2);
		
		mse+= (((float)var1-(float)var2)*((float)var1-(float)var2))/((float)leny);
		
				
	}
	//printf("Sum1: %f\t", sum1);
	//printf("Sum2: %f\t", sum2);
	//mse_mean+=mse/frame_count;
	printf("MSE: %f\n", mse);
	
	//fseek(file1,-(leny),SEEK_CUR);
	//fseek(file2,-(leny),SEEK_CUR);
	
	
	fseek(file1,(loop*leny*3/2), SEEK_SET);
	fseek(file2,(loop*leny*3/2), SEEK_SET);
	
	
	//sq_sum1_bl=0.0;
	//sq_sum2_bl=0.0;
	//sq_sum12_bl=0.0;
	//no_of_blocks = 3;
	
	ssim_bl = 0.0;
	
	for (x=0; x<no_of_blocks; x++)
	{
		sq_sum1=0.0;
		sq_sum2=0.0;
		sq_sum12=0.0;
		////loop++;
			//for (j=0; j<wy; j++)
			//{
				index=0;
					
				for (p=0; p<blocksize; p++)
				{
					for (q=0; q<blocksize; q++)
					{
						
						fscanf(file1, "%c", &var1);
						fscanf(file2, "%c", &var2);
					//	printf("value %d\n",(int)var1);
						
						arr1[index]=(int)var1;
						arr2[index]=(int)var2;
					//	printf("var1: %d\nindex: %d\n",arr1[index],index);
						
						index++;
						
						//printf("!!: %d\nindex: %d\n",arr1[index],index);
					}
					fseek(file1, ly-blocksize, SEEK_CUR);
					fseek(file2, ly-blocksize, SEEK_CUR);
				}
				
							
				
				r=index;
				index = 0;
				while(index<r)
				{
					
					sq_sum1+=((float) arr1[index]-sum1)*( (float)arr1[index]-sum1)/( (blocksize*blocksize)-1);  
					//printf("%f\t", sq_sum1);
					sq_sum2+=( (float)arr2[index]-sum2)*((float)arr2[index]-sum2)/( (blocksize*blocksize)-1);
					//printf("%f\t",  var2);
					//printf("%f\t", sq_sum2);
					sq_sum12+=( (float)arr1[index]-sum1)*( (float)arr2[index]-sum2)/( (blocksize*blocksize)-1); 
					index++;		
				}	
				
				//sort(arr, index);
				//med= median_cal(arr, index);
				//fprintf(file2, "%d ", med);	
				//printf("%d ", med);
				fseek(file1, -(ly-blocksize), SEEK_CUR);
				fseek(file2, -(ly-blocksize), SEEK_CUR);
				fseek(file1, -(2*ly), SEEK_CUR);
				fseek(file2, -(2*ly), SEEK_CUR);
			//}
	
		ssim_bl += (((2*sum1*sum2 + c1) * (2*(sq_sum12)+ c2)) / ((sum1*sum1 + sum2*sum2 + c1) * ( sq_sum1+ sq_sum2 + c2)));
		//printf("SSIM: %f\t", ssim_fr);
	}
	
	//printf("Sq_sum1: %f", sq_sum1_bl);
	//printf("Sq_sum2: %f", sq_sum2_bl);
	//printf("%d\t", ftell(file1));
//sum1_mean+=sum1/frame_count;
	//sum2_mean+=sum2/frame_count;
	
	//printf("Sum1: %f\t", sum1);
	//printf("Sum2: %f\t", sum2);
	//printf("Sq_sum12: %f\t", sq_sum12_bl);
	//printf("Sq_sum1: %f\t", sq_sum1_bl);
//	printf("Sq_sum2: %f\t", sq_sum2_bl);
	
	psnr= 20*0.434*log(255.0)-10*0.434*log(mse);
	
	ssim_fr = ssim_bl/no_of_blocks;	////////////////////////////ssim per frame
	
	fprintf(file3,"  %d\t",loop+1);
	fprintf(file3,"%f\t", mse);
	fprintf(file3,"%f\t", psnr);
  	fprintf(file3,"%f\n", ssim_fr);
  	
  	printf("  %d\t",loop+1);
	printf("%f\t", mse);
	printf("%f\t", psnr);
  	printf("%f\n", ssim_fr);
	
	
	
	
	//printf("Sum1: %f\t", sum1_mean);
	//printf("Sum2: %f\n", sum2_mean);

	
	fseek(file1, ((loop+1)*(leny*3/2)) ,SEEK_SET);
	fseek(file2, ((loop+1)*(leny*3/2)) ,SEEK_SET);
	
	//printf("%d\t", ftell(file1));

}

//printf("Sum2: %f\n", sum2_mean);
//printf("Sum1: %f\t", sum1_mean);
//printf("%d\n", loop);
//printf("\n\n%f\t", sum1);
//printf("%f\n", sum2);
//printf("MSE: %f\n", mse_mean);
rewind (file1);
rewind (file2);



 	//psnr= 20*0.434*log(255.0)-10*0.434*log(mse_mean);
 	
  
  	//printf("MSE: %e\n", mse);
  	//printf("MSE: %f\n", mse_mean);
  	//printf("PSNR: %f\n", psnr);
  	//printf("SSIM: %f", ssim_fr/frame_count);
  	
  	fclose(file1);
  	fclose(file2);
  	fclose(file3);
  
	getch();
	return 0;
}

/*

for ( loop=0; loop<frame_count; loop++)
	{
		for (i=0; i<ly; i++)
		{
			for (j=0; j<wy; j++)
			{
				index=0;
					
				for (p=0; p<blocksize; p++)
				{
					for (q=0; q<blocksize; q++)
					{
						
						fscanf(file1, "%c", &var1);
						*(arr+index)= (int)var1;
						index++;
					}
					fseek(file1, ly-blocksize, SEEK_CUR);
				}
				
				//sort(arr, index);
				//med= median_cal(arr, index);
				//fprintf(file2, "%d ", med);	
				//printf("%d ", med);
				
				fseek(file1, -2*ly, SEEK_CUR);
			}
		}
		
		fseek(file1, lenu+lenv ,SEEK_CUR);
	}
	
	*/

/*

for (loop=0; loop<frame_count; loop++)
{
	sq_sum1_bl=0.0;
	sq_sum2_bl=0.0;
	sq_sum12_bl=0.0;
	
	for (i=0; i<no_of_blocks; i++)
	{
	sq_sum1=0.0;
	sq_sum2=0.0;
	sq_sum12=0.0;
		////loop++;
		for (j=0; j<blocksize; j++)
		{
			fscanf(file1, "%c", &var1);
			fscanf(file2, "%c", &var2);	
			//printf("%f\t", (float)var1);
			sq_sum1+=((float)var1-sum1_mean)*((float)var1-sum1_mean)/((float)blocksize-1); 
			//printf("%f\t", sum1);
			sq_sum2+=((float)var2-sum2_mean)*((float)var2-sum2_mean)/((float)blocksize-1);
			//printf("%f\t", (float)var2);
			//printf("%f\t", sum2);
			sq_sum12+=((float)var1-sum1_mean)*((float)var2-sum2_mean)/((float)blocksize-1); 
		
		}
	//	printf("a");
		sq_sum1_bl+=sq_sum1/no_of_blocks;
		sq_sum2_bl+=sq_sum2/no_of_blocks;
		sq_sum12_bl+=sq_sum12/no_of_blocks;
	}
	//printf("a");	
	//sq_sum1_mean+=sq_sum1_bl/frame_count; // variance1
	//sq_sum2_mean+=sq_sum2_bl/frame_count; //variance2
	//sq_sum12_mean+=sq_sum12_bl/frame_count;//covariance
	ssim_fr += (((2*sum1_mean*sum2_mean + c1) * (2*sqrt(abs(sq_sum12_bl)) + c2)) / ((sum1_mean*sum1_mean + sum2_mean*sum2_mean + c1) * ( sq_sum1_bl+ sq_sum2_bl + c2)))/blocksize;
	//printf("Sum1: %f\t", sum1_mean);
	//printf("Sum2: %f\n", sum2_mean);
//	printf("MSE: %f\t", mse_mean);
//printf("SSIM: %f\t", ssim_fr);
	
	fseek(file1, lenu+lenv ,SEEK_CUR);
	fseek(file2, lenu+lenv ,SEEK_CUR);
	
	//printf("%d\t", ftell(file1));

}
*/

