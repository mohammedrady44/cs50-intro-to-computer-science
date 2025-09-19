#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../samples.h"
#include <strings.h>
typedef struct
{
    char *owner;
    char *loser;
    int difference;
    bool status;
}
mydata;
typedef struct
{
    char *name;
    int point;
    bool eleminated;
}
mydata2;
int candi_size;
int voters_num;
int length1;
int size_edge;
void get_result(int help,char *voters[][help],char *arg[]);
bool check_string(char *text,char *arg[]);
char *check_cycle(mydata2 candidates[],mydata relations[],int slice);
void clear(int help,char *voters[][help]);

int main( int length,char *arg[])
{
    if(length > 9 || length < 2)
    {
        if(length > 9)
        {
            printf("number of candidate up to max of 9");
        }
        else
        {
            printf("Usage: tideman [candidate ...]");
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
    size_edge = (candi_size*(candi_size-1))/2;
    mydata relations[size_edge];//represent edges
    
    for(int i = 0; i < size_edge; i++)
    {
        relations[i].status = false;
    }
    
    mydata2 candidates[candi_size];
    for(int i = 0; i < candi_size; i++)//fill struct
    {
        candidates[i].name = arg[i+1];
        candidates[i].point = 0;
    }

    int edge_index = 0;
    for(int i = 0; i < candi_size; i++)//for the first candidate
    {
        for(int j = i+1; j < candi_size; j++)//for other candidates
        {
            for(int o = 0; o < candi_size; o++)//for excluding candidates
            {
                if(o != i && o!= j )
                {
                    candidates[o].eleminated = true;
                }
                else
                {
                    candidates[o].eleminated = false;
                }
            }

            for(int a = 0; a < voters_num; a++)
            {
                bool known = false;
                for(int b = 0; b < candi_size; b++)
                {
                    for(int c = 0; c < candi_size; c++)
                    {
                        if(candidates[c].eleminated == false)
                        {
                            if(strcasecmp(candidates[c].name,voters[a][b]) == 0)
                            {
                                candidates[c].point += 1;
                                known = true;
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
            if(candidates[i].point > candidates[j].point)
            {
                relations[edge_index].owner = candidates[i].name;
                relations[edge_index].loser = candidates[j].name;
                relations[edge_index].difference = candidates[i].point - candidates[j].point;
            }
            else if (candidates[j].point > candidates[i].point)
            {
                relations[edge_index].owner = candidates[j].name;
                relations[edge_index].loser = candidates[i].name;
                relations[edge_index].difference = candidates[j].point - candidates[i].point;
            }
            edge_index += 1;
            for(int d = 0; d < candi_size; d++)
            {
                candidates[d].point = 0;
            }
        }
    }

    int small;
    char *owner;
    char *loser;
    for(int i = 0; i < size_edge; i++)
    {
        bool swaps = false;
        for(int j = 0; j < size_edge - 1; j++)
        {
            if(relations[j].difference < relations[j+1].difference)
            {
                small = relations[j].difference;
                relations[j].difference = relations[j+1].difference;
                relations[j+1].difference = small;               
                owner = relations[j].owner;
                relations[j].owner = relations[j+1].owner;
                relations[j+1].owner = owner;
                loser = relations[j].loser;
                relations[j].loser = relations[j+1].loser;
                relations[j+1].loser = loser;
                swaps = true;
            }
        }
        if(swaps == false)
        {
            break;
        }
    }

    char *source;
    int slice = 1;
    for(int i = 0; i <= size_edge; i++)
    {
        if(i == size_edge)
        {
            slice = size_edge;
        }        
        source = check_cycle(candidates,relations,slice);
        if(i < size_edge)
        {
            if(strcmp(source,"cycle") == 0)
            {
                relations[i].status = true;
            }
        }
        slice += 1;
    }
    printf(source);
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

char *check_cycle(mydata2 candidates[],mydata relations[],int slice)
{
    char *source = "cycle";
    for(int i = 0; i < candi_size; i++)
    {
        bool known = false;
        for(int j = 0; j < slice; j++)
        {
            if(relations[j].status == false)
            {
                if(strcasecmp(relations[j].loser,candidates[i].name) == 0)
                {
                    known = true;
                    break;
                }
            }
        }
        if(known == false)
        {
            source = candidates[i].name;
            break;
        }
    }
    return source;
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