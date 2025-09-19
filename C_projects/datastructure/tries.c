#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tries.h"
#include <ctype.h>

int main(void)
{
   
    tries my_instance;
    declare_diction(&my_instance);
    insert(&my_instance,"mohamed","5-1-2005");
    insert(&my_instance,"mohamedrady","no birth");
    insert(&my_instance,"sara","23-7-2004");
    insert(&my_instance,"Amal","24-4-2000");
    insert(&my_instance,"salma","23-5-2013");
    insert(&my_instance,"mahmoud","8-1-2005");
    insert(&my_instance,"osama","12-1-2008");
    insert(&my_instance,"khaled","5-1-2009");
    printf("%s\n",search(&my_instance,"yasser"));
    printf("%s\n",search(&my_instance,"mohamed"));
    printf("%s\n",search(&my_instance,"sara"));
    printf("%s\n",search(&my_instance,"Amal"));
    printf("%s\n",search(&my_instance,"salma"));
    printf("%s\n",search(&my_instance,"osama"));
    printf("%s\n",search(&my_instance,"mohamedrady"));

}

void declare_diction(tries *model)
{
    for(int i = 0; i < size; i++)
    {
        model->postions[i] = NULL;
    }
}

void insert(tries *model,char *key,char *number)
{
    for(int i = 0, n = strlen(key); i < n; i++)
    {
        int index = toupper(key[i]) - 'A';
        if(model->postions[index] == NULL)
        {
            model ->postions[index] = malloc(sizeof(tries));
            model = model ->postions[index];
            declare_diction(model);
        }
        else
        {
            model = model ->postions[index];
        } 
    }
    if( strlen(key) != 0)
    {
        model-> number = number;
    }
}

char *search(tries *model,char *key)
{
    for(int i = 0, n = strlen(key); i < n; i++)
    {

        int index = toupper(key[i]) - 'A';
        if(model->postions[index] == NULL)
        {
            return "not found";
        }
        model = model->postions[index];
    }
    return model->number;    
}