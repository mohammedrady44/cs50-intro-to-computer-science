#define size 26

typedef struct tries
{
    char *number;
    struct tries *postions[size];
}
tries;

void declare_diction(tries *model);
void insert(tries *model,char *key,char *number);
char *search(tries *model,char *key);

