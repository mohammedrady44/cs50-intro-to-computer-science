typedef struct stack
{
    int number;
    struct stack *next;
    struct stack *previous;
}
stack;

stack *temp;
void push(stack **module,int number);
int pop(stack **model);
void show(stack **model);
void clear(stack **model);
