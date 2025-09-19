#include <stdio.h>
#include "../samples.h"//path to the file header
int main(void)
{
   int row;
   do
   {
      row = get_int("Height: ");
   } 
   while (row < 1 || row > 8);
   
   int space = row - 1;

   for(int i = 0 ; i < row ; i++)
   {

      for(int j = 0 ; j < space ; j++)
      {
         printf(" ");
      }
      space -= 1;
      
      for(int w = 0 ; w < i + 1 ; w++) 
      {
         printf("#");
      }

      printf("  ");
      
      for(int t = 0 ; t < i + 1 ;t++) 
      {
         printf("#");
      }
      
      printf("\n");
      
   }

}