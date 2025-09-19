#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t byte;
typedef int16_t dbyte;

int main(int length,char *arg[])
{
    if(length != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor");
        return 1;
    }
    FILE *scr = fopen(arg[1],"rb");
    
    if(scr == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    
    FILE *des = fopen(arg[2],"wb");
    
    if(des == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

   byte arr[44];//header
   fread(arr,1,44,scr);
   fwrite(arr,1,44,des);
   
   float factor = atof(arg[3]);
   dbyte sample;
   while(fread(&sample,2,1,scr) != 0)//samples
   {
     sample = sample * factor;
     fwrite(&sample,2,1,des);
   }
   fclose(scr);
   fclose(des);
   



   


}