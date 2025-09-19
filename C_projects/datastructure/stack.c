#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include <stdlib.h>

int main(void)//implement stack using fixed array
{
    stack mymodel;
    mymodel.size = 0;
    push(&mymodel,1);
    push(&mymodel,9);
    push(&mymodel,0);
    printf("%i\n",pop(&mymodel));
    show(&mymodel);

}

void push(stack *mymodel,int number)
{

    if( mymodel->size == CAPACITY)
    {
        printf("size is too big, limit is 50\n");
        exit(2);
    }

    mymodel->arr[mymodel->size].number = number;
    mymodel->size ++;
}

int pop(stack *mymodel)
{
    if(mymodel->size == 0)
    {
        printf("stack is empty\n");
        exit(1);
    }

    mymodel->size --;
    return mymodel->arr[mymodel->size].number;
}

void show(stack *mymodel)
{
    for(int i = 0; i < mymodel->size; i++)
    {
        printf("%i ",mymodel->arr[i].number);       
    }
}


