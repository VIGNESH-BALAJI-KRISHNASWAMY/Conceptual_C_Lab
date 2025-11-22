/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 
*   Description     : WAP to generate a n*n magic square (n is odd +ve no.)
*   Input           : 
*   Output          : 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
#include <stdlib.h>

int magic_square(int,int (*)[]);

int main()
{
    char character;
    int num,iter,jiter;
    printf("\t IMPLEMENTING MAGIC SQUARE");
    
    do
    {
        printf("\nEnter a number(odd square matrix) : ");
        scanf("%d",&num);

        if( num <= 0 || num % 2 == 0 )
            printf("\nERROR:Provide only odd Positive numbers");
        else
        {
            int (*matrix)[num];//col size fixed based on input.
            matrix = calloc(sizeof(*matrix),sizeof(int));//1st argument decides the size of array of pointer(fixed col),2nd=row size
            if(matrix == NULL)
            {
                printf("\nERROR:Memory not allocated due to large size!");
            }
            if(matrix != NULL)
            {
                magic_square(num,matrix);
                for(iter = 1; iter <= num; iter++)
                {
                    for(jiter = 1; jiter <= num; jiter++)
                    {
                        printf("%d ",matrix[iter][jiter]);
                    }
                    printf("\n");
                }
            }
            free(matrix);
        }
        printf("\nDo you want to continue (y/Y):");
        scanf(" %c",&character);
    }while(character == 'Y' || character == 'y');
return 0;
}


int magic_square(int num,int (*array)[num])
{
    int row,col,iter,jiter;
    int tot = num * num;
    row = 1;
    col = (num + 1)/2;
    for (iter = 1; iter <= tot; iter++)
    {
       
        array[row][col] = iter;
        row = row - 1;
        col = col + 1;

        if(row < 1  && col > num)
        {
            row = row + 2;
            col = col - 1;//col - num;
        }
        else if( row < 1 )
            row = num;
        else if( col > num)
            col = 1;
        else if( array[row][col] != 0 )
        {
           row = row + 2;
           col = col - 1;
        }

    }
}
/********************************************************END OF CODE********************************************************************/
