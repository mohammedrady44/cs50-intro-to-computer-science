#include <stdio.h>
#include "dynaqueue.h"
#include <stdlib.h>

int main(void)
{
    queue *mymodel = NULL;
    enqueue(&mymodel,1);
    enqueue(&mymodel,2);
    enqueue(&mymodel,3);
    enqueue(&mymodel,4);
    dequeue(&mymodel);
    
    show(&mymodel);
    clear(&mymodel);


}

void enqueue(queue **model,int number)
{
    if(*model == NULL)
    {
        temp = malloc(sizeof(queue));
        temp->number = number;
        temp->next = NULL;
        temp->previous = NULL;
        *model = temp;
        return;
    }
    temp->next = malloc(sizeof(queue));
    temp->next->number = number;
    temp->next->next = NULL;
    temp->next->previous = temp;
    temp = temp->next;       
}

int dequeue(queue **model)
{
    if(*model == NULL)
    {
        printf("empty queue");
        exit(2);
    }
    
    int deleted = (*model)->number;
    *model = (*model)->next;
    
    if(*model == NULL)
    {
        free(temp);
        temp = *model;
    }
    else
    {
        free((*model)->previous);
        (*model)->previous = NULL;
    }
    return deleted;  
}

void show(queue **model)
{
    queue*count = *model;
    while (count != NULL)
    {
        printf("%i ",count->number);
        count = count->next;
    }
    
}

void clear(queue **model)
{
    queue*count = *model;
    while (count != NULL)
    {
        if(count->next == NULL)
        {
            free(count);
            break;
        }
        count = count->next;
        free(count->previous);
    }    
}
