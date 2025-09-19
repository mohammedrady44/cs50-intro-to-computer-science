#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>//prototype function covert between two data types
#include "../samples.h"

bool check_decimal(char *key);
void encrypt(char *text,int key);

int main(int length,char*arg[])
{
    if(length != 2)// length of command arguments
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    if(check_decimal(arg[1]) == false)// the string is decimal from 0 to 9
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    int key = atoi(arg[1]);//conversion from string to int
    char *text = get_string("plaintext:  ");
    encrypt(text,key);
    printf("ciphertext: %s",text);
    free(text);
    return 0;
}

bool check_decimal(char *key)
{
    for(int i = 0, n = strlen(key); i < n; i++)
    {
        if(key[i] < '0' || key[i] > '9')
        {
            return false;
        }
    }
    return true;
}

void encrypt(char *text,int key)
{
    int limit;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if((text[i] >= 'A' && text[i] <= 'Z')||(text[i] >= 'a' && text[i] <= 'z'))
        {
            if(text[i] > 90)//letter lowercase or uppercase
            {
                limit = 122;
            }
            else
            {
                limit = 90;

            }
            
            int result = text[i] + key;

            while(result > limit)
            {
                result -= 26;
            }

            text[i] = result;
        }
    }
}


