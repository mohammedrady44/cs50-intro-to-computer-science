#include <stdio.h>
#include <stdbool.h>
#include "../samples.h"
#include <string.h>
#include <stdlib.h>

bool check_master(int w);
int main(void)
{
    char *number = get_string("Number: ");
    int limit = strlen(number);
    int base = 0;
    int rest = 0;
    bool alter = false;
    char *n = malloc(sizeof(char)*2);
    for(int i = strlen(number) - 1 ; i < 0 ; i--)
    {
        sprintf(n,"%c%c",number[i],'\0');
        if(alter == false)
        {
            rest += atoi(n);
            alter = true;
        }
        else
        {
            int check = 2 * atoi(n);
            char str[3];
            sprintf(str,"%i",check);//convert from integer to string
            if(strlen(str) != 1)
            {
                base += (check % 10) + (check / 10);
            }
            else
            {
                base += check;
            }
            alter = false;
        }
    }
   int checksum = base + rest;

   if(checksum % 10 == 0 && limit > 1)
   {
        char subset[3];
        sprintf(subset,"%c%c%c",number[0],number[1],'\0');//for concetenating anything
        sprintf(n,"%c%c",subset[0],'\0');
        if(limit == 15 && (atoi(subset) == 34 || atoi(subset) == 37) )
        {
            printf("AMEX\n");
        }
        else if(limit == 16 && check_master(atoi(subset)))
        {
            printf("MASTERCARD\n");
        }
        else if((limit == 16 || limit == 13) && atoi(n) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
   }
  else
   {
        printf("INVALID\n");
   }
   free(number);
   free(n);
}

bool check_master(int w)
{
    for(int i = 51 ; i < 56 ; i++)
    {
        if(w == i)
        {
            return true;
        }

    }
    return false;
}
