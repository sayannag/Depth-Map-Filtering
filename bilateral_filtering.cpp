#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define sigma_s 8.0
#define sigma_r 0.2
#define ly 1024
#define wy 768
#define pi 3.14

double gaussian(double x, double y, double sigma)
{
	double c;
	c=exp(-((x)*(y))/(20000.0*sigma*sigma));
	return c;
}


int main()
{
	
	int T = 255;
/*	float gamma, row; 
	gamma = pi/(2*T);
	row= gamma*sigma_r;  */
//	int N;
	
/*	if (sigma_r> pow(gamma, -2))
		N=10000;
	else
		N= (int) (pow(row, -2));
*/		
	
	FILE *file1,*file2,*file3;
	file1=fopen("F:/KGP-Depth Map/depth1.yuv","r");
	file2=fopen("F:/KGP-Depth Map/depth1.yuv","r");
	file3=fopen("bilateral_depth1.yuv","w");
	int leny,lenu,lenv;
  	leny = ly*wy;
  	lenu = leny/4;
  	lenv = leny/4;
	fseek(file1, 0 ,SEEK_END);
  	int file_size = ftell(file1);
  	int frame_count = ( file_size /(leny+lenu+lenv) );
  	rewind(file1);
  	unsigned char var1,var2;
  	int i;
  	int loop,j;
  	double P,Q,F;
	double G,H,h;
  	double F_bar;
  	double c;
  	int n,N=5;
  	frame_count=1;
  	int x,y;
  	for(loop=0;loop<frame_count;loop++)
  	{
  		for(i=0;i<1;i++)
  		{
  			for(x=0;x<1;x++)
			{
	  			P=0.0;
	  			Q=0.0;
	  			G=1.0;
	  			fscanf(file1, "%c", &var1);
	  			//printf("%c",var1);
	  			fseek(file2,(loop*leny*3/2), SEEK_SET);
				
				h=(double)var1;
				//printf("%e",h);
				F=exp(-(h*h)/(20000.0*sigma_r*sigma_r));
			//	printf("%e",F);
				H=h/sigma_r;
				F_bar=0.0;
				c=1.0;
				for(j=0;j<ly;j++)
				{
					for(y=0;y<wy;y++)
					{
						fscanf(file2, "%c", &var2);
					//	printf("%c",var2);
						if(abs(sqrt((i-j)*(i-j)+(x-y)*(x-y)))<=(6*sigma_s))
						{
							//printf("%e\n", (double)var2);
							if(i!=j&&x!=y)
							{
								//printf("\nfffffffffffffff");
								F_bar+=exp(-((j)*(j))/(2.0*sigma_s*sigma_s))*gaussian((double)var2,(double)var2,sigma_r);
								printf("..........%e\n", F_bar);
							}
						}
					}
				}
				
				
				for(n=0;n<N;n++)
				{
					
					Q+=G*F_bar;
					F_bar=0.0;
					fseek(file2,(loop*leny*3/2), SEEK_SET);
					for(j=0;j<leny;j++)
					{
						for(y=0;y<wy;y++)
						{
							fscanf(file2, "%c", &var2);
							if(abs(sqrt((i-j)*(i-j)+(x-y)*(x-y)))<=(6*sigma_s))
							{
								//printf("%e\n", (double)var2);
							//	if(var1!=var2)
							//	{
									F_bar+=exp(-((j)*(j))/(2.0*sigma_s*sigma_s))*gaussian((double)var2,(double)var2,sigma_r);
									F_bar=F_bar*pow(((double)var2/sigma_r),n+1);							
									//printf("%e\n", F_bar);
							//	}
							}
						}
					}
					
					P+=G*F_bar;
					//printf("P	%e\n", P);
					G=H*G;
					G=G/n+1;		
				}
			//	printf("P	%e\n", P);
			//	printf("Q	%e\n", Q);
				F_bar=sigma_r*(P/Q);
					
			//	fprintf(file3, "%e", Ip);
				printf("%e\n", F_bar);
				
			}
		}
		fseek(file1,((loop+1)*leny*3/2), SEEK_SET);
		fseek(file2,((loop+1)*leny*3/2), SEEK_SET);
	}
	fclose(file1);
	fclose(file2);
	fclose(file3);
	
	
	
	
	getch();
	return 0;
	
}
