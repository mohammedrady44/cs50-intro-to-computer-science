#include <stdio.h>
#include "../samples.h"//path to the file header
int main(void)
{
    int change_owed;
    //reprompt the user if input negative
    do
    {
        change_owed = get_int("change owed: ");
    } 
    while (change_owed < 0);        
    int coins[] = {25,10,5,1};
    int count = 0;
    int index = 0;
    while(change_owed > 0)
    {
        if(change_owed >= coins[index])
        {
            change_owed -= coins[index];
            count +=1;
        }
        else
        {
            index +=1;
        }
    }

    printf("%i",count);
}