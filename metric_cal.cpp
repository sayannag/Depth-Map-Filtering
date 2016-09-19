#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#define ly 1024
#define wy 768


//void yuvOpenInputFile( char *file_name) {

  
//}


int main()
{
	//yuvOpenInputFile ("depth1.yuv");

  long int file_size;
  long int leny,lenu,lenv;
  leny = ly*wy;
  lenu = leny/4;
  lenv = leny/4;
  int p,q;
  //int y[ly][wy];
 //FILE* file = fopen("DataSet1.txt","r");
  //if( file == NULL ){
    //printf("yuvOpenInputFile: Could not open the file %s\n", file_name);
  //}

  /* Check the file size */
 // fseek(file,0,SEEK_END);
  //file_size = ftell(file);
  //*frame_count = ( file_size /(leny+lenu+lenv) ); //applicable for video files, not separated into frames

  /* Set the file position back to the beginning of the file */
  //fseek(file,0,SEEK_SET);
  //return file;
  
  //rewind(file);
 /* float a;
  for(p=0;p<ly;p++)
  {
  	for(q=0;q<wy;q++)
  	{
  		fscanf(file,"%f",&a);
  		printf("%f ",a);
	}
  }*/
  int n = 1;
   char v2;
FILE *fa=fopen("depth1.yuv","r");
while(n<7000)    //v2!='\n'
{
	fscanf(fa,"%c",&v2);
	//v2 = fgetc(fa);
	//if(v2=='\t')
	n++;
	printf("%d",(int)v2);
}
  
	getch();
	return 0;
}

