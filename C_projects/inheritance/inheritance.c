#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

typedef struct 
{
    char *parent1;
    char *parent2;
}
family;

char *caculate_child(family myarr[]);
bool check(int length,char *myarr[],char *test);
void clear(int length,char *myarr[]);

int main(void)
{
    int size = 9;
    char *combinations[size];
    char genes[3] = {'A','B','O'};
    int count = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            combinations[count] = malloc(sizeof(3));//two for two genes and one for null terminator  
            combinations[count][0] = genes[i];
            combinations[count][1] = genes[j];
            combinations[count][2] = '\0';
            count++;
        }
    }

    family myarr[3];
    srand(time(NULL));
    //this formula for get int between two numbers(inclusive)rand() % (max - min + 1) + min;
    int rand_index1 = rand() % (8 - 0 + 1) + 0; 
    int rand_index2 = rand() % (8 - 0 + 1) + 0;   
    
    for(int i = 0; i < 2; i++)
    {
        int rand_index1 = rand() % (8 - 0 + 1) + 0; 
        int rand_index2 = rand() % (8 - 0 + 1) + 0;
        myarr[i].parent1 = combinations[rand_index1];
        myarr[i].parent2 = combinations[rand_index2];
    }
    myarr[2].parent1 = malloc(3);
    myarr[2].parent2 = malloc(3);
    char *child = caculate_child(myarr);
   // printf("grandparent1:%s grandparent2: %s parent1: %s\n",myarr[0].parent1,myarr[0].parent2,myarr[2].parent1);
   // printf("grandparent1:%s grandparent2: %s parent2: %s\n",myarr[1].parent1,myarr[1].parent2,myarr[2].parent2);
   // printf("parent1:%s parent2: %s child: %s\n",myarr[2].parent1,myarr[2].parent2,child);
    printf("Child (Generation 0): blood type %s\n",child);
    printf("    Parent (Generation 1): blood type %s\n",myarr[2].parent1);
    printf("        Grandparent (Generation 2): blood type %s\n",myarr[0].parent1);
    printf("        Grandparent (Generation 2): blood type%s\n",myarr[0].parent2);
    printf("    Parent (Generation 1): blood type %s\n",myarr[2].parent2);
    printf("        Grandparent (Generation 2): blood type%s\n",myarr[1].parent1);
    printf("        Grandparent (Generation 2): blood type%s\n",myarr[1].parent2);   
    clear(size,combinations);
    free( myarr[2].parent1);
    free( myarr[2].parent2);
    free(child);
}

char *caculate_child(family myarr[])
{
    char *test = malloc(3);
    char *child_combin[8];
    char *child = malloc(3);
    int current_length = 0;
    for(int i = 0; i < 8; i++)
    {
        child_combin[i] = malloc(3);
    }

    for(int i = 0; i < 3; i++)
    {
        current_length = 0;
        for(int j = 0; j < 2; j++)
        {
            for(int u = 0; u < 2; u++)
            {
                test[0] = myarr[i].parent1[j];
                test[1] = myarr[i].parent2[u];
                test[2] = '\0';
                if(check(current_length,child_combin,test)== false);
                else
                {
                    if(test[0] != test[1])
                    {
                        strcpy(child_combin[current_length],test);
                        char temp = test[0];
                        test[0] = test[1]; // just substitute the (AB -> BA) if two literals are different
                        test[1] = temp;
                        current_length++;
                        strcpy(child_combin[current_length],test);
                        current_length++;
                    }
                    else
                    {
                        strcpy(child_combin[current_length],test);
                        current_length++;
                    }
                }
            }
        }
        srand(time(NULL));
        int rand_index1 = rand() % ((current_length - 1) - 0 + 1) + 0; 
        if( i == 0)
        {
            strcpy(myarr[2].parent1, child_combin[rand_index1]);;
        }
        else if(i == 1)
        {
            strcpy(myarr[2].parent2, child_combin[rand_index1]);
        }
        else
        {
            strcpy(child, child_combin[rand_index1]);
        }       
    }
    clear(current_length,child_combin);
    free(test);
    return child;
}

bool check(int length,char *myarr[],char *test)
{
    if(length == 0)
    {
        return true;
    }
    for(int i = 0; i < length; i++)
    {
        if(strcmp(test,myarr[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

void clear(int length,char *myarr[])
{
    for (int i = 0; i < length; i++)
    {
        free(myarr[i]);
    }
    
}