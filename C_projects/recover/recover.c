#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t byte;
bool check_bytes(int data[],byte first_four[],int length);

int main(int length, char *arg[])
{
    if(length != 2)
    {
        printf("Usage: recover name of a forensic image\n");
        return 1;
    }
    FILE *memory_card = fopen(arg[1],"rb");
    if(memory_card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    int arr_length = 4;
    int data[] = {0xff,0xd8,0xff,0xe0};
    byte actual_data[512];
    int count = 0;
    FILE *des;
    bool continu = false;
    while(fread(actual_data,1,512,memory_card)!= 0)
    {
        if(check_bytes(data,actual_data,arr_length) == true)
        {
            if(count != 0)
            {
                fclose(des);
            }
            char *file_name = malloc(20);
            sprintf(file_name,"%03i.jpg",count);
            des = fopen(file_name,"wb");
            fwrite(actual_data,1,512,des);
            count += 1;
            free(file_name);
        }
        else if(count != 0)
        {
            fwrite(actual_data,1,512,des);

        }
    }

    fclose(memory_card);
    fclose(des);
}

bool check_bytes(int data[],byte first_four[],int length)
{
    for(int i = 0; i < length; i++)
    {
        if(i == length - 1)
        {
            for(int j = 0; j < 16; j++)
            {
                if(data[i] + j != first_four[i]);

                else
                {
                   return true;
                }
            }
            return false;
        }
        else
        {
            if(data[i] != first_four[i])
            {
                return false;
            }
        }

    }
}
