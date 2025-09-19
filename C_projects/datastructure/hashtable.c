#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    hash_tab diction;
    declare_instance(&diction);
    add(&diction,"mohamed","5-1-2005");
    add(&diction,"Amal","24-4-2000");
    add(&diction,"salma","23-5-2013");
    add(&diction,"Mahmoud","999999");
    add(&diction,"sara","23-7-2004");
    add(&diction,"osama","12-1-2008");
    //show(&diction);
    printf("Mohamed born in %s loves sara born in %s",binary_search(&diction,"mohamed"),binary_search(&diction,"sara"));   
}

void add(hash_tab *model, char *key,char *value)
{
    int index = toupper(key[0]) - 'A';
    if(model->poistions[index] == NULL)
    {
        model->poistions[index] = malloc(sizeof(data));
        model->poistions[index]->name = key;
        model->poistions[index]->number = value;
        model->poistions[index]->next = NULL;
        temps[index] = model->poistions[index];
    }
    else
    {
        temps[index]->next = malloc(sizeof(data));
        temps[index]->next->name = key;
        temps[index]->next->number = value;
        temps[index]->next->next = NULL;
        temps[index] = temps[index]->next;
    }
    
}

void declare_instance(hash_tab *model)
{
    for(int i = 0; i < size; i++)
    {
        model->poistions[i] = NULL;
    }
}

void show(hash_tab *model)
{
    int p = 0;
    hash_tab count = *model;
    for(int i = 0; i < size; i++)
    {
        while (count.poistions[i] != NULL )
        {
            p = 1;
            printf("%s , %s",count.poistions[i]->name,count.poistions[i]->number);
            count.poistions[i] = count.poistions[i]->next;
            printf("/");
        }
        
        if(p == 1)
        {
            printf("\n");;
        }
        p = 0;        
    }
}

char *binary_search(hash_tab *model,char *key)
{
    int index = toupper(key[0]) - 'A';
    hash_tab count = *model;
    while (count.poistions[index] != NULL)
    {
        if(strcmp(count.poistions[index]->name,key) == 0)
        {
            return count.poistions[index]->number;
        }
        count.poistions[index] = count.poistions[index]->next;
    }
    return "not found";    
}