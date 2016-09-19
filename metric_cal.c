
#include <conio.h>
#include <stdio.h>
#include<math.h>

#define ly 1024
#define wy 768


int main()
{
	//yuvOpenInputFile ("depth1.yuv");
	FILE *file1, *file2, *file3, *file4, *file5, *file6;
  	//long int file_size;
  	int leny,lenu,lenv;
  	leny = ly*wy;
  	lenu = leny/4;
  	lenv = leny/4;
  	int p,q;
  	
  	file1 = fopen("depth1.yuv","r");
  	file2= fopen("depth_recV1.0000.yuv", "r");
  	  	
  	
  //if( file == NULL ){
    //printf("yuvOpenInputFile: Could not open the file %s\n", file_name);
  //}

  /* Check the file size */
  fseek(file1, 0 ,SEEK_END);
  int file_size = ftell(file1);
  int frame_count = ( file_size /(leny+lenu+lenv) ); 
  //printf("%d ", frame_count);

  
unsigned char var1, var2;
  	
  	int i;
 
  

rewind (file1);
rewind (file2);
FILE* fp = fopen("tes.txt","w");
double sq_sum1=0.0, sq_sum2=0.0, variance1, variance2;

double sum1=0.0, sum2=0.0;
double mse=0.0, mse_mean=0.0, sum1_mean=0.0, sum2_mean=0.0;
int loop;
fseek(file2, 89*(leny+lenu+lenv), SEEK_CUR);
for (i=0; i<10; i++)
	{
		
		fscanf(file2, "%c", &var2);	
		printf("%f\t", (float)var2);
		fprintf(fp, "%c", var2);
	}

/*
for (loop=0; loop<frame_count; loop++)
{
	mse=0.0;
	sum1-0.0;
	sum1=0.0;
	for (i=0; i<leny; i++)
	{
		////loop++;
		fscanf(file1, "%c", &var1);
		fscanf(file2, "%c", &var2);	
		//printf("%f\t", (float)var1);
		sum1+=((double)var1)/((double)leny);
		//printf("%f\t", sum1);
		sum2+=((double)var2)/((double)leny);
		//printf("%f\t", (float)var2);
		//printf("%f\t", sum2);
		
		mse+= (((double)var1-(double)var2)*((double)var1-(double)var2))/((double)leny);
		//printf("%f \t", mse);
	}
	printf("****END OF LOOP: %d *****\n", loop);
	mse_mean+=mse/frame_count;
	sum1_mean+=sum1/frame_count;
	sum2_mean+=sum2/frame_count;
	
	printf("Sum1: %f\t", sum1_mean);
	printf("Sum2: %f\n", sum2_mean);
//	printf("MSE: %f\t", mse_mean);
	
	fseek(file1, lenu+lenv ,SEEK_CUR);
	fseek(file2, lenu+lenv ,SEEK_CUR);
	
	//printf("%d\t", ftell(file1));

}

//printf("%d\n", loop);
//printf("\n\n%f\t", sum1);
//printf("%f\n", sum2);
//printf("%f\n", mse_mean);
rewind (file1);
rewind (file2);

double psnr;
/*
for (i=0; i<leny; i++)
{
	fscanf(file1, "%c", &var1);
	fscanf(file2, "%c", &var2);	
	
	sq_sum1+=((int)var1-sum1);
	sq_sum2+=((int)var2-sum2);
}
	



	variance1= sq_sum1/(leny-1);
 	variance2= sq_sum2/(leny-1);
	*/
 /*	psnr= 20*0.434*log(255.0)-10*0.434*log(mse);
 	//ssim += (((2*mean1*mean2 + c1) * (2*sqrt(abs(variance1)) + c2)) / ((mean1*mean1 + mean2*mean2 + c1) * (sqrt(abs(variance1))*sqrt(abs(variance1)) + sqrt(abs(variance2))*sqrt(abs(variance1)) + c2)))/(BlockPerHeight * BlockPerWidth);
  
  	//printf("MSE: %e\n", mse);
  	//printf("PSNR: %e", psnr);
  	//printf("SSIM: %e", ssim);
  */
	getch();
	return 0;
}



