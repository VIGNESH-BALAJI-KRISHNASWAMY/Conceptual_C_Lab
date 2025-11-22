/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 18/10/2021.
*   Description     : WAP to generate a n*n magic square (n is odd +ve no.)
*   Input           : ./a.out 
*	Output          :        IMPLEMENTING MAGIC SQUARE
*                       Enter a number(odd square matrix) : 3
*                       	8 	1 	6 
*                       	3 	5 	7 
*                       	4 	9 	2 
*
*                       Do you want to continue (y/Y):y
*
*                       Enter a number(odd square matrix) : 5
*                       	17 	24 	1 	8 	15 
*                       	23 	5 	7 	14 	16 
*                       	4 	6 	13 	20 	22 
*                       	10 	12 	19 	21 	3 
*                       	11 	18 	25 	2 	9 
*
*                       Do you want to continue (y/Y):n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
#include <stdlib.h>

int magic_square(int,int (*)[]); //function definition with pointer to an array as argument.

int main()
{
    char character;                                             //input and output variable declaration.
    int num,iter,jiter;
    printf("\t IMPLEMENTING MAGIC SQUARE");
    
    do                                                          //loop to continue process.
    {
        printf("\nEnter a number(odd square matrix) : ");       //input fetch.
        scanf("%d",&num);

        if( num <= 0 || num % 2 == 0 )                          //input evaluation.
            printf("\nERROR:Provide only odd Positive numbers");
        else
        {
            int (*matrix)[num];                                 //col size fixed based on input.
            matrix = calloc(num * num,sizeof(int));             //dynamically allocating memory for each element and initializing the...
            if(matrix == NULL)                                      //...memory position to 0 using calloc.
            {
                printf("\nERROR:Memory not allocated due to large size!");
            }
            if(matrix != NULL)
            {
                magic_square(num,matrix);                       //function call to magic square function.
                for(iter = 1; iter <= num; iter++)              //loop to print the 2D-array.
                {
                    for(jiter = 1; jiter <= num; jiter++)
                    {
                        printf("\t%d",matrix[iter][jiter]);
                    }
                    printf("\n");
                }
            }
            free(matrix);                                       //deallocation of memory allocated.
        }
        printf("\nDo you want to continue (y/Y):");             //input fetch for next cycle.
        scanf(" %c",&character);
    }while(character == 'Y' || character == 'y');               //condition for next cycle.
return 0;
}


int magic_square(int num,int (*matrix)[num])                     //magic square function definition.
{
    int row,col,iter,jiter;
    int tot = num * num;
    row = 1;                                                    //initializing row = 1 and col = 2 for any odd ordered matrix.
    col = (num + 1)/2;
    for (iter = 1; iter <= tot; iter++)                         //loop to increment the matrix elements.
    {
       
        matrix[row][col] = iter;                                //assigning the matrix current element to the designated position.
        row = row - 1;                                          //making top rigtht move.
        col = col + 1;

        if(row < 1  && col > num)                               //condition to check whether the current position exists.
        {
            row = row + 2;                                      //if not exists then change the position.
            col = col - 1;
        }
        else if( row < 1 )
            row = num;
        else if( col > num)
            col = 1;
        else if( matrix[row][col] != 0 )                        //condition to check the position is free i,e '0' or filled.
        {
           row = row + 2;                                       //if occupied make a down 2 and left 1 shift.
           col = col - 1;
        }

    }
}
/********************************************************END OF CODE********************************************************************/
