#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../samples.h"
char *check_key(char *text);
void force_upper(char *text);
void encrypt(char *text,char *key);

int main(int length,char*arg[])
{
    if(length != 2)// length of command arguments
    {
        printf("Usage: ./Substitution key");
        return 1;
    }

    force_upper(arg[1]);
    char *check = check_key(arg[1]);
    if(strcmp(check,"valid") != 0)
    {
        printf(check);
        return 1;
    }
    char *text = get_string("plaintext:  ");
    encrypt(text,arg[1]);
    printf("ciphertext: %s",text);
    free(text);    
}

char *check_key(char *text)
{      
    int letters = 0;
    char box[strlen(text)+1];//check repeated characters
    for(int i = 0, n = strlen(text); i < n; i++ )
    {
        if(text[i] < 'A' || text[i] > 'Z')// contain only alphabetic character
        {
            return "key must only contain alphabetic characters.";
        }
        for(int j = 0, w = strlen(box); j < w; j++)
        {
            if(text[i] == box[j])
            {
                return "key must not contain repeated characters.";
            }
        }
        
        box[i] = text[i];
        letters += 1;
    }
    if(letters != 26)
    {
        return "key must contain 26 characters.";
    }

    return "valid";
    
}

void force_upper(char *text)
{
    for(int i = 0, n = strlen(text); i < n; i++ )//force key to be uppercase
    {
        text[i] = toupper(text[i]);
        
    }
}

void encrypt(char *text,char *key)
{
    int number = 26;
    int size = 3;
    char letters[number][size];
    int ascii = 65;
    for(int i = 0; i < number; i++)// fill array uppercase and lowercase
    {
        letters[i][0] = ascii;
        letters[i][1] = ascii + 32;
        letters[i][2] = '\0';
        ascii += 1;
    }
    
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        { 
            int magic = 0;
            int logic = 0;
            
            if(text[i] > 90)// check if letter is lowercase,"we assume the letter is uppercase unless opposite happens"
            {
                magic = 1;// every lowercase letter in letters array
                logic = 32;// encrypted letter should be in lowercase
            }
            
            for(int j = 0; j < number; j++)
            {
                if(text[i] == letters[j][magic])
                {
                    text[i] = key[j] + logic;
                    break;
                }                
            }
        }      
    }    
}

   
