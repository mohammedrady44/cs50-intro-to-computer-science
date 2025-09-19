#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>
#include "../samples.h"
typedef struct
{
    char *name;
    int point;
    bool eleminated;
}
mydata;

typedef struct
{
    char *owner;
    bool status;
}
myart;

bool check_string(char *text,char *arg[]);
int one_win(mydata candidates[]);
bool tie(mydata candidates[]);
int fewer(mydata candidates[]);
bool edit_elemination(int point,bool eleminated,int min);
void get_result(int help,char *voters[][help],char *arg[]);
void clear(int help,char *voters[][help]);
int candi_size;
int voters_num;
int length1;

int main(int length,char *arg[])
{
    if(length > 9 || length < 2)
    {
        if(length > 9)
        {
            printf("number of candidate up to max of 9");
        }
        else
        {
            printf("Usage: runoff [candidate ...]");
        }
        return 1;
    }
    
    length1 = length;   
    candi_size = length1 - 1;
    voters_num = get_int("Number of voters: ");
    char *voters[voters_num][candi_size];
    for(int i = 0; i < voters_num; i++)
    {
        for(int j = 0; j < candi_size; j++)
        {
            char *instance = get_string("Rank %i: ",j+1);
            if(check_string(instance,arg) == false)
            {
                printf("Invalid vote.");
                return 1;
            }
            voters[i][j] = instance;
        }
        printf("\n"); 
    }
    get_result(candi_size,voters,arg);      
}

void get_result(int help,char *voters[][help],char *arg[])
{
    myart dual_arr[voters_num];//fill dual_arr that has owner and status for list of voters 
    for(int i = 0; i < voters_num; i++)
    {
        dual_arr[i].status = false;
    }    
    
    mydata candidates[candi_size];
    
    for(int i = 0; i < candi_size; i++)//fill struct
    {
        candidates[i].name = arg[i+1];
        candidates[i].point = 0;
        candidates[i].eleminated = false;
    }
   bool condition = false;
   int value;
    while(true)
    {
        for(int i = 0; i < voters_num; i++)
        {
            bool known = false;
            if(dual_arr[i].status == condition)
            {
                for(int j = 0; j < candi_size; j++)
                {
                    for(int o = 0; o < candi_size; o++)
                    {
                        if(candidates[o].eleminated == false)
                        {
                            
                            if(strcasecmp(candidates[o].name,voters[i][j]) == 0)
                            {
                                candidates[o].point += 1;
                                known = true;
                                dual_arr[i].owner = candidates[o].name;
                                dual_arr[i].status = false;
                                break;
                            }
                        }
                    }
                    
                    if(known == true)
                    {
                        break;
                    } 
                }
            }
        }
        condition = true;
        value = one_win(candidates);
        bool many = tie(candidates);
        
        if(value != -1 || many == true)
        {
            break;
        }

        int min = fewer(candidates);
        for(int i = 0; i < candi_size; i++)
        {
            candidates[i].eleminated = edit_elemination(candidates[i].point,candidates[i].eleminated,min);
        }

        for(int i = 0; i < candi_size; i++)
        {
            if(candidates[i].eleminated == true)
            {
                for(int j = 0; j < voters_num; j++)
                {
                    if(strcasecmp(dual_arr[j].owner,candidates[i].name) == 0)
                    {
                        dual_arr[j].status = true;
                    }
                }
            }
        }
    }
    
    if(value != -1)
    {
        printf(candidates[value].name);
    }
    else
    {
        for(int i = 0; i < candi_size; i++)
        {
            if(candidates[i].eleminated == false)
            {
                printf("%s\n",candidates[i].name);
            }
        }
    }
    clear(candi_size,voters);
} 


bool check_string(char *text,char *arg[])
{
    for(int i = 1; i < length1; i++)
    {
        if(strcasecmp(text,arg[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

int one_win(mydata candidates[])
{
    int half = voters_num / 2;
    for( int i = 0; i < candi_size; i++)
    {
        if(candidates[i].point > half)
        {
            return i;
        }
    }
    return -1;
}

bool tie(mydata candidates[])
{
    int number;
    for(int i = 0; i < candi_size; i++)
    {
        if(candidates[i].eleminated == false)
        {
            number = candidates[i].point;
            break;
        }
    }
    
    for(int i = 0; i < candi_size; i++)
    {
        if(candidates[i].eleminated == false)
        {
            if(number != candidates[i].point)
            {
                return false;
            }
        }
    }
    return true;
}

int fewer(mydata candidates[])
{
    int number;
    for(int i = 0; i < candi_size; i++)
    {
        if(candidates[i].eleminated == false)
        {
            number = candidates[i].point;
            break;
        }
    }
    for(int i = 0; i < candi_size; i++)
    {
        if(candidates[i].eleminated == false)
        {
            if( number > candidates[i].point)
            {
                number = candidates[i].point;
            }
        }
    }
    return number;

}

bool edit_elemination(int point,bool eleminated,int min)
{
    if(eleminated == false)
    {
        if(point == min)
        {
            return true;
        } 
        else
        {
            return false;
        }

    }
    else
    {
        return true;
    }
}

void clear(int help,char *voters[][help])
{
    for(int i =  0; i < voters_num; i++)
    {
        for(int j = 0; j < candi_size; j++)
        {
            free(voters[i][j]);
        }
    }
}
 

   



