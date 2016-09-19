#include <conio.h>
#include <stdio.h>
#include <math.h>

#define sigma_s 8.0
#define sigma_r 0.2
#define ly 1024
#define wy 768
#define pi 3.14


int main()
{
	
	FILE *file1, *file2, *file3, *file4, *file5;
	
	int leny,lenu,lenv;
  	leny = ly*wy;
  	lenu = leny/4;
  	lenv = leny/4;
	
	file1 = fopen("F:/KGP-Depth Map/depth1.yuv","r");
	file2 = fopen("F:/KGP-Depth Map/depth1.yuv","r");
	file4 = fopen("F:/KGP-Depth Map/image100/kendo1.yuv","r");
	file5 = fopen("F:/KGP-Depth Map/image100/kendo1.yuv","r");
	file3 = fopen("Bilateral_Filtering1.txt", "w");
	
	
	fseek(file1, 0 ,SEEK_END);
  	int file_size = ftell(file1);
  	int len_per_frame= leny+lenu+lenv ;
  	int frame_count = ( file_size /len_per_frame ); 
  	//printf("%d ", frame_count);
  	
  	unsigned char var1, var2, var3, var4;
  	
  	int i, j, x, y, loop;
  	
  	float weight_spatial, weight_range, weight, bilateral, W,weight_range_texture;
	
	rewind(file1);
	/*for (j=0; j<5; j++)	
			{
				fscanf(file1, "%c", &var1);
				printf("%f\t", (float)var1);
			}
	*/
	frame_count=1;
	for (loop=0; loop<frame_count; loop++)
	{
		for (i=0; i<ly; i++)
		{	
			for (j=0; j<wy; j++)	
			{
				fscanf(file1, "%c", &var1);
				fscanf(file4, "%c", &var3);
				printf("%c\t", var3);
				printf("%c\t", var1);
				bilateral=0.0;
				W=0.0;
				weight = 0.0;
				weight_range = 0.0;
				weight_spatial=0.0;
				weight_range_texture=0.0;
				fseek(file2,(loop*leny*3/2), SEEK_SET);
				fseek(file5,(loop*leny*3/2), SEEK_SET);
				for (x=0; x<ly; x++)
				{
					for (y=0; y<wy; y++)
					{
						fscanf(file2, "%c", &var2);
						fscanf(file5, "%c", &var4);
						if (x!=i && y!=j)
						{	
							weight_spatial+= (exp(-1.0*((x-i)*(x-i)+(y-j)*(y-j)))/(2*sigma_s*sigma_s));
		
							
						 	weight_range+=(exp(-1.0*((float)var1-(float)var2)*((float)var1-(float)var2)))/(2*sigma_r*sigma_r);
						 	
						 	weight_range_texture+=(exp(-1.0*((float)var3-(float)var4)*((float)var3-(float)var4)))/(2*sigma_r*sigma_r);
							weight+=weight_spatial*weight_range*weight_range_texture;
							bilateral+=weight*(float)var1;
							W+=weight;
						//printf("%f",bilateral);
					    }
					}
				}
				bilateral=bilateral/W;
				fprintf(file3, "%f", bilateral);
				//fprintf(file3, "%c", (char)bilateral);
				//printf("%c", (char)bilateral);
				printf("B.F for pixel (%d, %d): %f\n", i, j, bilateral);
			}	
			
		}
		fseek(file1,((loop+1)*leny*3/2), SEEK_SET);
		fseek(file2,((loop+1)*leny*3/2), SEEK_SET);
		fseek(file4,((loop+1)*leny*3/2), SEEK_SET);
		fseek(file5,((loop+1)*leny*3/2), SEEK_SET);
		
	}
	
	
	fclose(file1);
	fclose(file2);
	fclose(file3);
	fclose(file4);
	fclose(file5);	
		
	getch();
	return 0;
	
}
