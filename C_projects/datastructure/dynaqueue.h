typedef struct queue
{
    int number;
    struct queue *next;
    struct queue*previous;
}
queue;

queue *temp;
void enqueue(queue **module,int number);
int dequeue(queue **model);
void show(queue **model);
void clear(queue **model);