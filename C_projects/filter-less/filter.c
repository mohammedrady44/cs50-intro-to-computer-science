#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "datatyp.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);

int main(int length,char *arg[])
{
    if(length != 4)
    {
        printf("./filter -flag inputfile outputfile\n");
        return 1;
    }

    char flag = arg[1][1];
    char *allf = "bgsr";
    bool check = false;
    for(int i = 0; i < 4; i++)
    {
        if(allf[i] == flag)
        {
            check = true;
        }
    }
    
    if(!check)
    {
        printf("invaild flag\n");
        return 1;
    }
    
    FILE *src = fopen(arg[2],"rb");
    if(src == NULL)
    {
        printf("could not open inputfile\n");
        return 2;
    }

    FILE *des = fopen(arg[3],"wb");
    if(des == NULL)
    {
        printf("could not open outputfile\n");
        return 2;
    }

    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    fread(&bf,sizeof(bf),1,src);
    fwrite(&bf,sizeof(bf),1,des);

    fread(&bi,sizeof(bi),1,src);
    fwrite(&bi,sizeof(bi),1,des);
    int height = abs(bi.biHeight);
    int width = abs(bi.biWidth);
    RGBTRIPLE image[height][width];
    int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

    for(int i = 0; i < height; i++)
    {
        fread(image[i],sizeof(RGBTRIPLE),width,src);
        fseek(src,padding,SEEK_CUR);
    }
    
    switch (flag)
    {
        case 'g':
            grayscale(height,width,image);
            break;
        case 'b':
            blur(height,width,image);
            break;
        case 'r':
            reflect(height,width,image);
            break;
        case 's':
            sepia(height,width,image);
            break;        
    }

    for (int i = 0; i < height; i++)
    {
        fwrite(&image[i],sizeof(RGBTRIPLE),width,des);
        for(int k = 0; k < padding; k++)
        {
            fputc(0x00,des);
        }
    }
    fclose(src);
    fclose(des);   
}


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int sum = image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen;
            int value = round(sum / 3.0);
            image[i][j].rgbtRed = value;
            image[i][j].rgbtBlue = value;
            image[i][j].rgbtGreen = value;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int color[3];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            color[0] = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);//red
            color[1] = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue); //green
            color[2] = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue); //blue
            for(int u = 0; u < 3; u++)
            {
                if(color[u] > 255)
                {
                    color[u] = 255;
                }
            }
            image[i][j].rgbtRed = color[0];
            image[i][j].rgbtGreen = color[1];
            image[i][j].rgbtBlue = color[2];
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        int high = width - 1;
        for(int j = 0; j <= high; j++)
        {
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;
            image[i][j].rgbtBlue = image[i][high].rgbtBlue;
            image[i][j].rgbtGreen = image[i][high].rgbtGreen;
            image[i][j].rgbtRed = image[i][high].rgbtRed;
            image[i][high].rgbtBlue = blue;
            image[i][high].rgbtRed = red;
            image[i][high].rgbtGreen = green;
            high -= 1;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int r_sum = 0;
    int b_sum = 0;
    int g_sum = 0;
    int count = 0;
    RGBTRIPLE back_up[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int r = i;
            int top = i;
            if(i+1 < height)
            {
                r = i+1;
            }
            if(i-1 >= 0)
            {
                top = i-1;
            }
            while(r >= top)
            {
                int p = j;
                int left = j;
                if(j+1 < width)
                {
                    p = j+1;
                }
                if(j-1 >= 0)
                {
                    left = j-1;
                }
                while(p >= left)
                {
                    r_sum += image[r][p].rgbtRed;
                    b_sum += image[r][p].rgbtBlue;
                    g_sum += image[r][p].rgbtGreen;
                    count += 1;
                    p -= 1;
                }
                r -= 1;
            }

             back_up[i][j].rgbtRed = round(r_sum / (float) count);
             back_up[i][j].rgbtGreen = round(g_sum / (float) count);
             back_up[i][j].rgbtBlue = round(b_sum / (float) count);
            r_sum = 0;
            g_sum = 0;
            b_sum = 0;
            count = 0;
        }
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = back_up[i][j].rgbtRed;
            image[i][j].rgbtGreen = back_up[i][j].rgbtGreen;
            image[i][j].rgbtBlue = back_up[i][j].rgbtBlue;
        }
    }
    return;
}
