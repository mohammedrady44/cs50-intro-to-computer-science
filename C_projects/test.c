#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "samples.h"
void my_sort(int numbers[], int length);
void touppe2(char *text);
char *concten(char *first,char *second);
bool check_string(char *text,char *arg[],int length);
void linked_list(void);
char *slice(char *base, int num);

typedef struct
{
    int *name;
    int point;

}
mydata;
typedef struct mydata2
{
    struct mydata2 *next;
    int number;

}
mydata2;

int main(int length,char *arg[])
{
   
    /*
    int numbers[] ={10,8,7,6,5,4,4,3,2,1};
    my_sort(numbers,10);
    bubble_sort(numbers,10);

    int candi_size = 3;
    int voters_num = 3;
    char *voters[voters_num][candi_size];//for status
    char o[50];
   
    for(int i = 1; i < length ; i++)
    {
        for(int j = 0, n = strlen(arg[i]); j < n; j++)
        {
            arg[i][j] = toupper(arg[i][j]);
        }
    }

    for(int i = 0; i < voters_num; i++)
    {
        for(int j = 0; j < candi_size; j++)
        {
            printf("Rank %i: ",j+1);
            scanf("%s",o);
            touppe2(o);
            if(check_string(o,arg,length) == false)
            {
                printf("Invalid vote.");
                return 1;
            }
            voters[i][j] = malloc(strlen(o) + 1);
            strcpy(voters[i][j],o);
        }
        printf("\n"); 
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%s ",voters[i][j]);
        }
        printf("\n");
    }

    */
    
}
   
void my_sort(int numbers[], int length)
{
    int small = 0;
    int index = 0;
    int start = 1;
    for(int i = 0; i < length; i++)
    {
        small = numbers[i];
        for(int j = start; j < length; j++)
        {
            if(small > numbers[j])
            {
                small = numbers[j];
                index = j;
            }
        }
        start += 1;
        if(small != numbers[i])
        {
            numbers[index] = numbers[i];
            numbers[i] = small;
        }
    }
    printf("selection sort: ");
    
    for(int i = 0; i < length; i++)
    {
        printf("%i ",numbers[i]);
    }
    
}

void bubble_sort(int numbers[], int length)
{
    int small;
    
    for(int i = 0; i < length; i++)
    {
        bool swaps = false;
        for(int j = 0; j < length - 1; j++)
        {
            if(numbers[j] > numbers[j+1])
            {
                small = numbers[j+1];
                numbers[j+1] = numbers[j];
                numbers[j] = small; 
                swaps = true;
            }
        }
        if(swaps == false)
        {
            break;
        }
    }
    printf("\nbubble sort:    ");
    for(int i = 0; i < length; i++)
    {
        printf("%i ",numbers[i]);
    } 

}


void linked_list(void)
{
    /*
    int input;
    printf("if you're enough,just enter no");
    mydata2 *list = NULL;
    while(true)
    {
        printf("Enter number: ");
        if (scanf("%i",&input) == 0)
        {
            break;
        }
        mydata2 *temp = malloc(sizeof(mydata2));
        temp->number = input;
        temp->next = list;
        list = temp;
    }
    mydata2 *count = list;    
    while(count != NULL)
    {
        printf("%i ",count->number);
        count = count->next;
    }
    free(list);
    ///////////////////////////////////////////////////
    mydata2 *list = malloc(sizeof(mydata2));
    mydata2 *temp = list;
    for(int i = 1; i < length; i++)
    {
        temp->number = atoi(arg[i]);
        temp->next = malloc(sizeof(mydata2));
        temp = temp->next;
    }
    
    mydata2 *counter = list;
    int count = 0;   
    while(count < length - 1)
    {
        printf("%i ",counter->number);
        counter = counter->next;
        count += 1;
    }
    */
    
}

char *concten(char *first,char *second)
{
    int size_1 = strlen(first);
    int size_2 = strlen(second);
    char *total = malloc(sizeof(char)*(size_1 + size_2 + 1));
    for(int i = 0; i < size_1; i++)
    {
        total[i] = first[i];
    }
    int sub = size_1;
    for(int i = 0; i < size_2; i++)
    {
        total[sub] = second[i];
        sub++;
    }
    total[sub] = '\0';
    return total;
}
char *slice(char *base, int num)
{
    char *subset = malloc(sizeof(char)*(num + 1));
    for(int i = 0; i < num; i++)
    {
        subset[i] = base[i];
    }
    subset[num] = '\0';
    return subset;
}   

