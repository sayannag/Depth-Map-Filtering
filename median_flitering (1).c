#include <stdio.h>
#include <conio.h>
#include <math.h>

#define ly 1024
#define wy 768
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
	FILE *file1, *file2, *file3;
  	//long int file_size;
  	int leny,lenu,lenv;
  	leny = ly*wy;
  	lenu = leny/4;
  	lenv = leny/4;
  	
  	file1 = fopen("C:/Dev-Cpp/KGP/depth1.yuv","r");
  	file2 = fopen("C:/Dev-Cpp/KGP/Mf/median_filtering.yuv", "w");
  	file3 = fopen("C:/Dev-Cpp/KGP/Mf/Mod_MF_output.yuv", "w");
  	
  	fseek(file1, 0 ,SEEK_END);
  	int file_size = ftell(file1);
  	int frame_count = ( file_size /(leny+lenu+lenv) ); 
  	//printf("%d ", frame_count);
  	//printf("%d\n", ftell(file1));
  	
  	rewind (file1);
  	
  	unsigned char var1, var2;
  	//int var1;
  	int i, j;
	
	int p, q, loop;
	
	//frame_count=1;
	//int count=0;
	
	int *arr;
	arr= (int *)malloc(blocksize*blocksize*sizeof(int));
	int index, iter=1;
	int med;
	
	int total_blocks= leny- (2*(ly+wy)-4);
	//printf("%d", total_blocks);
	
	for ( loop=0; loop<frame_count; loop++)
	{
				while (iter<=total_blocks)
				{
					index=0;
					for (p=0; p<blocksize; p++)
					{
						for (q=0; q<blocksize; q++)
						{	
							fscanf(file1, "%c", &var1);
							//printf("%d\t ", ftell(file1));
							//printf("%c ", var1);
							*(arr+index)= (int)var1;
							//printf("%d ", *(arr+index));
							index++;
						}
						fseek(file1, ly-blocksize, SEEK_CUR); 
					}
					//printf("%d\t ", ftell(file1)); //
					//printf("%d\n", index);
					//printf("\n");
					sort(arr, index);
					med= median_cal(arr, index);
					fprintf(file2, "%c", (char)med);
					//printf("\nMed: %d\n ", med);
					fseek(file1, -(ly-blocksize), SEEK_CUR);
					fseek(file1, -(2*ly), SEEK_CUR); //2*2 as 2 newlines are included
					//printf("%d ", ftell(file1));
					iter++;
				}	
			
		fseek(file1, (loop+1)*(leny*3/2), SEEK_SET);
	}
	
	fclose(file2);
	//printf("Iteration: %d ", iter-1);
	
	file2 = fopen("C:/Dev-Cpp/KGP/Mf/median_filtering.yuv", "r");
	
	rewind(file1);
	rewind(file2);
	
	for (loop=0; loop<frame_count; loop++)
	{
		for (i=0; i<ly; i++)
		{
			for (j=0; j<wy; j++)
			{
				if (i==0 || i==(ly-1) || j==0 || j==(wy-1))
				{
					fscanf(file1, "%c", &var2);
					fprintf(file3, "%c", var2);
					//printf("%c\t", var1);
				}
				else
				{
					fscanf(file2, "%c", &var2);
					fprintf(file3, "%c", var2);	
				}
			}
		}
	}
	
	printf("***End of program***");

	getch();
	return 0;
	
}
