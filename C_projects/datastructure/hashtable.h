#define size 26

typedef struct data
{
    char *name;
    char *number;
    struct data *next;
}
data;

typedef struct 
{
    data *poistions[size];
}
hash_tab;

data *temps[size];

void add(hash_tab *model, char *key,char *value);
void declare_instance(hash_tab *model);
void show(hash_tab *model);
char *binary_search(hash_tab *model,char *key);
