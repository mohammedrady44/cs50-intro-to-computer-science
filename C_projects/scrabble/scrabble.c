 #include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../samples.h"

void force_upper(char *word);
int get_score(char*word,char*pattern[],int points[]);


int main(void)
{
    char *input1 = get_string("Player 1: ");
    char *input2 = get_string("Player 2: ");
    char*pattern[7] = {"EAIONRTLSU","DG","BCMP","FHVWY","K","JX","QZ"};
    int points[7] = {1,2,3,4,5,8,10};//dual array
    force_upper(input1);
    force_upper(input2);
    int player1 = get_score(input1,pattern,points);
    int player2 = get_score(input2,pattern,points);
    
    if(player1 > player2 )
    {
      printf("Player 1 wins!");
    }
    else if(player1 < player2)
    {
      printf("Player 2 wins!");
    }
    else
    {
      printf("Tie!");
    }
    free(input1);
    free(input2);
    
}


void force_upper(char *word)
{
    for(int i = 0, n = strlen(word); i < n; i++)
    {
        word[i] = toupper(word[i]);
    }
}

int get_score(char*word,char*pattern[],int points[])
{
    int sum = 0;
    for(int i = 0, n = strlen(word); i < n; i++)
    {
       bool known = false;
        for(int j = 0; j < 7; j++)
        {
            for(int q = 0, w = strlen(pattern[j]); q < w; q++)
            {
                if(pattern[j][q] == word[i])
                {
                    sum += points[j];
                    known = true;
                    break;
                }
            }
            
            if(known == true)
            {
                break;
            }
        }
    }
    return sum;

}
