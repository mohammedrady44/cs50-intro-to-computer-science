#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>
#include "../samples.h"
bool check_string(char *candidate,char *arg[],int length);
typedef struct 
{
    char *name;
    int voters;
}
mydata;
void get_winner(char *arg[],int lenght1,char *voters[],int lenght2);
void clear(char *voters[],int length);

int main(int length,char *arg[])
{
    if(length > 10 || length < 3)// check the command arguments
    {
        if(length > 10)
        {
            printf("number of candidate up to max of 9");
        }
        else if (length == 2 )
        {
            printf(arg[1]);            
        }
        
        else
        {
            printf("Usage: plurality [candidate ...]");
        }
        return 1;
    }

    int number = get_int("Number of voters: ");
    int known = number;
    char *voters[number];
    
    for(int i = 0; i < number; i++)
    {
        char *instance = get_string("Vote: ");
        if(check_string(instance,arg,length) == false)
        {
            printf("Invalid vote.\n");
            number -= 1;
            i -= 1;
        }
        else
        {
            voters[i] = instance;
        }
    }
     
   if(number < 1)
   {
      printf("all of %i votes are finshed",known);
      return 1;
   }
   
   get_winner(arg,length,voters,number);     
}

bool check_string(char *candidate,char *arg[],int length)
{
    for(int i = 1; i < length; i++)
    {
        if(strcasecmp(arg[i],candidate) == 0)
        {
            return true;
        }
    }
    return false;
}

void get_winner(char *arg[],int lenght1,char *voters[],int lenght2)
{
    int actual_size = lenght1-1;
    mydata candidates[actual_size];
    int o = 1;
    for(int i = 0; i < actual_size; i++)
    {
        candidates[i].name = arg[o];
        candidates[i].voters = 0;
        o += 1;
    }
    for(int i = 0; i < lenght2; i++)
    {
        for(int j = 0; j < actual_size; j++)
        {
            if(strcasecmp(candidates[j].name,voters[i]) == 0)
            {
                candidates[j].voters += 1;
                break;
            }
        }
    }
    int greater = candidates[0].voters;
    for(int i = 1; i < actual_size; i++)
    {
        if(candidates[i].voters > greater)
        {
            greater = candidates[i].voters;
        }
    }
    for(int i = 0; i < actual_size; i++)
    {
        if(candidates[i].voters == greater)
        {
            printf("%s\n",candidates[i].name);
        }
    }
    clear(voters,lenght2);  
}
void clear(char *voters[],int length)
{
    for(int i = 0; i < length; i++)
    {
        free(voters[i]);
    }
}