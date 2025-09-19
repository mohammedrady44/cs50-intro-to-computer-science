#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "../samples.h"
int letters(char *text);
int words(char *text);
int sentences(char *text);

int main(void)
{
    char *x = get_string("Text: ");
    int num_l = letters(x);
    int num_w = words(x);
    int num_s = sentences(x);
    double l = (num_l / (double)num_w)*100;//average letters per 100 words
    double s = (num_s / (double)num_w)*100;//average sentences per 100 words
    double index = 0.0588 * l - 0.296 * s - 15.8;
    int final = round(index);//for round to nearest integer
    
    if(final < 1)
    {
        printf("Before Grade 1");
    }
    else if(final >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i",final);
    }
    free(x);
          
}

int letters(char *text)
{
    int letters = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if((text[i] >= 'a'&& text[i] <= 'z')||(text[i] >= 'A'&& text[i] <= 'Z'))
        {
            letters += 1;
        }
        
    }
    return letters;
}

int words(char *text)
{
    int words = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == ' ')
        {
            words += 1;
        }
    }
    return words+1;
    
}

int sentences(char *text)
{
    int sentences = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if((text[i] == '.')||(text[i] == '!')||(text[i] == '?'))
        {
            sentences += 1;
        }
    }
    return sentences;
    
}

