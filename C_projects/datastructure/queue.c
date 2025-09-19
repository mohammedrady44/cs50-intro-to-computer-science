#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include <stdlib.h>

int main(void)
{
    queue mymodel;
    mymodel.size = 0;
    enqueue(&mymodel,1);
    enqueue(&mymodel,9);
    dequeue(&mymodel);
    show(&mymodel);
}

void enqueue(queue *mymodel,int number)
{
    if( mymodel->size == CAPACITY)
    {
        printf("size is too big, limit is 50\n");
        exit(2);
    }

    mymodel->arr[mymodel->size].number = number;
    mymodel->size ++;
}

int dequeue(queue *mymodel)
{
    if(mymodel->size == 0)
    {
        printf("queue is empty\n");
        exit(1);
    }

    for(int i = 0; i < mymodel->size - 1; i++)
    {
        int right = mymodel->arr[i+1].number;
        mymodel->arr[i+1].number = mymodel->arr[i].number;
        mymodel->arr[i].number = right;
    }
    mymodel->size --;
    return mymodel->arr[mymodel->size].number;
}

void show(queue *mymodel)
{
    for(int i = 0; i < mymodel->size; i++)
    {
        printf("%i ",mymodel->arr[i].number);       
    }
}