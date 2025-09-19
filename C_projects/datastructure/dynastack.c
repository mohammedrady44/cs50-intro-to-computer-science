#include <stdio.h>
#include "dynastack.h"
#include <stdlib.h>

int main(void)
{
    stack *model = NULL;
    push(&model,1);
    push(&model,2);
    push(&model,3);
    push(&model,4);
    pop(&model);
   show(&model);
   clear(&model);

}

void push(stack **model,int number)
{
    if(*model == NULL)
    {
        temp = malloc(sizeof(stack));
        temp->number = number;
        temp->next = NULL;
        temp->previous = NULL;
        *model = temp;
        return;
    }
    temp->next = malloc(sizeof(stack));
    temp->next->number = number;
    temp->next->next = NULL;
    temp->next->previous = temp;
    temp = temp->next;       
}

int pop(stack **model)
{
    if(temp == NULL)
    {
        printf("empty stack");
        exit(2);
    }
    int deleted = temp->number;
    temp = temp->previous;
    if(temp == NULL)
    {
        free(*model);
        *model = temp;
    }
    else
    {
        free(temp->next);
        temp->next = NULL; 
    }
    return deleted;   
}

void show(stack **model)
{
    stack*count = *model;
    while (count != NULL)
    {
        printf("%i ",count->number);
        count = count->next;
    }    
}

void clear(stack **model)
{
    stack*count = *model;
    while (count != NULL)
    {
        if(count->next == NULL)
        {
            free(count);
            break;
        }
        count = count->next;
    }    free(count->previous);    
}

