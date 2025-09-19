#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct data
{
    char word[46];
    struct data *next;
}
data;

data *postions[26][26][26];
data *past[26][26][26];
bool indexes(char *Word);
unsigned int hash(char *word);
void intial(void);
bool check(char *name);
void unload(void);
int index1,index2,index3;

int main(int length,char *arg[])
{
    char *dictionary = arg[1];
    FILE *scr = fopen(dictionary,"r");
    char current_word[46];
    intial();
    while (fscanf(scr,"%s",current_word) != EOF)
    {
       if (indexes(current_word) == true)
        {     
            if(postions[index1][index2][index3] == NULL)
            {                
                postions[index1][index2][index3] = malloc(sizeof(data));       
                strcpy(postions[index1][index2][index3]->word,current_word);
                postions[index1][index2][index3]->next = NULL;
                past[index1][index2][index3] = postions[index1][index2][index3];   
            }
            else
            {
                past[index1][index2][index3]->next = malloc(sizeof(data));
                strcpy(past[index1][index2][index3]->next->word,current_word);
                past[index1][index2][index3]->next->next = NULL;
                past[index1][index2][index3] = past[index1][index2][index3]->next;
            }     
        }                              
    }
    fclose(scr);
    FILE *des = fopen(arg[2],"r");
    char output[46];
    int known = 0;
    while (fscanf(des,"%s",output) != EOF)
    {
        if(check(output) == true)
        {
            known +=1;
        }
    }
    printf("%i",known);
    
}
unsigned int hash(char *word)
{
    return toupper(word[0]) - 'A';
}

bool indexes(char *word)
{
    int n = strlen(word);
    if(n > 0)
    {
        index1 = hash(&word[0]);
        index2 = index1;
        index3 = index1;

        if(n >= 2)
        {
            char temp = toupper(word[1]);
            if(temp < 'A' || temp > 'Z');
            else
            {
                index2 = hash(&word[1]);
            }            
        }

        if(n >= 3)
        {
            char temp = toupper(word[2]);
            if(temp < 'A' || temp > 'Z');
            else
            {
                index3 = hash(&word[2]);
            }  
        }      
    }    
    
    else
    {
        return false;
    }
    
    return true;  
}

void intial(void)
{
   for( int i = 0; i < 26; i++)
   {
        for(int j = 0; j < 26; j++)
        {
            for(int k = 0; k < 26; k++)
            {
                postions[i][j][k] = NULL;
            }
        }
   }
}

bool check(char *name)
{
    indexes(name);
    data *count = postions[index1][index2][index3];
    
    int n = strlen(name);
    char fixed[n+1];
    for(int i = 0; i <= n; i++)
    {
        fixed[i] = tolower(name[i]);
    }
    
    while(count != NULL)
    {
       if(strcmp(count->word,fixed) == 0)
       {
            return true;
       }
       count = count->next;
    }
    return false;
}

void unload(void)
{
    for( int i = 0; i < 26; i++)
   {
        for(int j = 0; j < 26; j++)
        {
            for(int k = 0; k < 26; k++)
            {
                while (postions[i][j][k] != NULL)
                {
                    data *count = postions[i][j][k];
                    postions[i][j][k] = postions[i][j][k]->next;
                    free(count->word);
                    free(count);
                }          
            }
        }
   }   
}