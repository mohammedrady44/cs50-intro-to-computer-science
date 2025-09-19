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
queue;
void enqueue(queue *mymodel,int number);
int dequeue(queue *mymodel);
void show(queue *mymodel);