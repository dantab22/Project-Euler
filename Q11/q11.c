#include <stdio.h>

int max(int x, int y);

int main(void)
{
    FILE* fp = fopen("matrix.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file");
        return -1;
    }
    
    int buffer[419];
    for (int i = 0; i < 20; i++)
    {
        fscanf(fp, "%2d %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d",&buffer[(i*20)], &buffer[(i*20)+1], &buffer[(i*20)+2],
               &buffer[(i*20)+3], &buffer[(i*20)+4], &buffer[(i*20)+5], &buffer[(i*20)+6], &buffer[(i*20)+7], &buffer[(i*20)+8],&buffer[(i*20)+9],
               &buffer[(i*20)+10], &buffer[(i*20)+11], &buffer[(i*20)+12], &buffer[(i*20)+13], &buffer[(i*20)+14], &buffer[(i*20)+15],
               &buffer[(i*20)+16], &buffer[(i*20)+17], &buffer[(i*20)+18], &buffer[(i*20)+19]);
    }
    fclose(fp);
    
    int matrix[20][20];
    
    //stores values read from file to matrix
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            matrix[i][j] = buffer[(i*20)+j];
            //printf("matrix[%i][%i] = %i \n", i , j, matrix[i][j]);
        }
    }
    
    //due to commutivity of multiplication, we just need to look at right, diagl, diagr
    int maxr = 0; int maxdl = 0; int maxdr = 0; int temp;
    for (int i = 0; i < 20; i++)
    {
        //for each value in row
        for (int j = 0; j < 20; j++)
        {
            //checking right entries
            if (j < 17)
            {
                temp = matrix[i][j]*matrix[i][j+1]*matrix[i][j+2]*matrix[i][j+3];
                if (temp > maxr)
                    maxr = temp;
            }
            //checking diagl entries
            if ( (i < 17) && (j > 3) )
            {
                temp = matrix[i][j]*matrix[i+1][j-1]*matrix[i+2][j-2]*matrix[i+3][j-3];
                    if (temp > maxdl)
                        maxdl = temp;
            }
            //checking diagr
            if ( (i < 17) && (j < 17) )
            {
                temp = matrix[i][j]*matrix[i+1][j+1]*matrix[i+2][j+2]*matrix[i+3][j+3];
                    if (temp > maxdr)
                        maxdr = temp;
            }
        }
        
    }
    
    //checking maximum
    int maxima1 = max(maxdr, maxdl);
    int maxima2 = max(maxima1, maxr);
    
    printf("Maximum of four product is: %i \n", maxima2);
    
	return 0;
}

//creates my max function
int max(int x, int y)
{
    if(x >= y)
    {
        return x;
    }
    else if(y <= x)
    {
        return y;
    }
    else(x = y);
    {
        return y;
    }
}
