#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
//reprompt user for int (user-friendly)
int get_int(char *format,...)
{
    va_list args;
    va_start(args,format);
    int size = 12; //the maximum number of digits supposed to be 10 but 1 for \n and for \0
    int actual_size;
    char potential[size];
    bool error;
    do
    {
        error = false;
        vprintf(format,args);
        fgets(potential,size,stdin);
        if(potential[0] == '\n')
        {
            error = true;
        }  
        for(int i = 0; i < size; i++)  //checking for null terminator
        {
            if(potential[i] == '\n')
            {
                actual_size = i;
                break;
            }
        }
        int index = 0;
        if(potential[0] == '-')
        {
            index = 1;
        }
        while(index < actual_size) //checking if digit or not
        {
            if(potential[index] < '0'|| potential[index] > '9')
            {
                error = true;
                break;
            }
            index++;
        }
    }
    while(error == true);
    va_end(args);
    int number =  atoi(potential);
    free(potential);
    return number;
}

long long get_long(char *format,...)
{
    va_list args;
    va_start(args,format);
    int size = 21;
    int actual_size;
    char potential[size];
    bool error;
    do
    {
        error = false;
        vprintf(format,args);
        fgets(potential,size,stdin);
        if(potential[0] == '\n')
        {
            error = true;
        }  
        for(int i = 0; i < size; i++)  //checking for null terminator
        {
            if(potential[i] == '\n')
            {
                actual_size = i;
                break;
            }
        }
        int index = 0;
        if(potential[0] == '-')
        {
            index = 1;
        }
        while(index < actual_size) //checking if digit or not
        {
            if(potential[index] < '0'|| potential[index] > '9')
            {
                error = true;
                break;
            }
            index++;
        }
    }
    while(error == true);
    long long number =  atoll(potential);
    va_end(args);
    free(potential);
    return number;

}

//must free the pointer
char *get_string(char *format,...) 
{
    va_list args;//declare 
    va_start(args,format);//intialize the arg with arguments ...
    int capacity = 4;
    int current = 0;
    char *text = malloc(sizeof(char) * capacity);
    char l;
    vprintf(format,args);
    va_end(args);//clean
    while ((l = getchar()) != '\n' && l != EOF )
    {
        if(current == capacity)
        {
            capacity *= 2;
            text =  realloc(text,sizeof(char) * capacity);
            if(text == NULL)
            {
                printf("no memory");
                exit(-1);
            }
        }
        text[current] = l;
        current++;
    }
    text[current] = '\0';
    return text;   
}