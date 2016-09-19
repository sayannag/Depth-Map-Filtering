#include <stdio.h>
#include <conio.h>
#include <math.h>

#define ly 4
#define wy 3
#define blocksize 3

void sort (int *a, int n)
{
	int c, d, t;
	
	for (c = 1 ; c <= n - 1; c++) 
	{
    	d = c;
 
    	while ( d > 0 && *(a+d) < *(a+d-1)) 
		{
      		t          = *(a+d);
      		*(a+d)   = *(a+d-1);
      		*(a+d-1) = t;
 
      		d--;
    	}
  	}
}


int median_cal(int *a, int n)
{
	return *(a+n/2);
}

int main()
{
	//yuvOpenInputFile ("depth1.yuv");
	FILE *file1, *file2;
  	//long int file_size;
  	int leny,lenu,lenv;
  	leny = ly*wy;
  	lenu = leny/4;
  	lenv = leny/4;
  	
  	file1 = fopen("sample.txt","r");
  	file2 = fopen("median_filtering.txt", "w");
  	
  	
  	fseek(file1, 0 ,SEEK_END);
  	int file_size = ftell(file1);
  	int frame_count = ( file_size /(leny+lenu+lenv) ); 
  	//printf("%d ", frame_count);
  	
  	rewind (file1);
  	
  	unsigned char var1, var2;
  	int i, j;
	
//	rewind (file2);
	int p, q, loop;
	
	int no_of_blocks= leny/blocksize*blocksize;
	frame_count=1;
	int count=0;
	
	int *arr;
	int index;
	int med;
	
	for ( loop=0; loop<frame_count; loop++)
	{
		for (i=0; i<ly; i++)
		{
			for (j=0; j<wy; j++)
			{
				
				/*if (i==0 || i==(ly-1) || j==0 || j==(wy-1))
				{
					//count++;
					fprintf(file2, "%f", (float)var1);
					//printf("%c\t", var1);
				}
				else
				{
					
				}*/
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
				
				sort(arr, index);
				med= median_cal(arr, index);
				//fprintf(file2, "%d ", med);	
				printf("%d ", med);
				
				fseek(file1, -2*ly+2, SEEK_CUR);
			}
		}
		
		fseek(file1, lenu+lenv ,SEEK_CUR);
	}
	
	printf("%d ", count);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
/*	int *arr;
	
	int loop;
	int x, y;
	int median;
	for ( loop=0; loop<frame_count; loop++)
	{
		for (x=0; x<no_of_blocks; x++)
		{
			
			for (y=0; y<blocksize; y++)
			{
				fscanf(file1, "%c", &var1);
				//printf("%f\t", (float)var1);
				*(arr+y)=var1;
				
			}
			sort (arr, blocksize);
			median=*(arr+blocksize/2);
			for (j=0; j<blocksize; j++)
			{
				//fprintf(file2, "%d", *(arr+j));
				if (j==blocksize/2)
					//fprintf(file2, "%d", median);
			}
		}
		fseek(file1, lenu+lenv ,SEEK_CUR);	
	}	
	
/*	int *arr;
	int i;
	for (i=0; i<5; i++)
	{
		*(arr+i)= 10-i;
		printf("%d ", *(arr+i));
	}
	printf("\n");
	sort(arr, 5);
	for (i=0; i<5; i++)
	{
		printf("%d ",*(arr+i));
	}
	*/
	
	getch();
	return 0;
	
}
