#define CAPACITY 50

typedef struct
{
    int number;
}
mark;
typedef struct
{
    mark arr[CAPACITY];
    int size;
}
stack;
void push(stack *mymodel,int number);
int pop(stack *mymodel);
void show(stack *mymodel);