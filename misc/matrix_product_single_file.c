/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 
*   Description     : A Program to find the product of given matrix.
*   Input           : 
*   Output          : 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main()
{
    int row,col,iter,jiter,col_temp,col_jump,row_jump,sum = 0,prod;
    char character;

    printf("\tPRODUCT OF A GIVEN MATRIX");
    do
    {
        printf("\nEnter the number of rows:");
        scanf("%d",&row);
        printf("Enter the number of columns:");
        scanf("%d",&col);
        printf("Enter values for %d x %d matrix:\n",row,col);

        int (*ptr)[col + 2];
        int (*tr_ptr)[col + 2];
        int (*pr_ptr)[row + 2];
        ptr = malloc(sizeof(*ptr) * (row + 2));
        tr_ptr = malloc(sizeof(*tr_ptr) * (row + 2));
        pr_ptr = malloc(sizeof(*pr_ptr) * (row + 2));

        for(iter = 0; iter < row; iter++)
        {
            for(jiter = 0; jiter < col; jiter++)
            {
                scanf("%d",&ptr[iter][jiter]);
            }
        }

        printf("\nGiven Matrix:\n");
        for(iter = 0; iter < row; iter++)
        {
            for(jiter = 0; jiter < col; jiter++)
            {
                printf("%d\t",ptr[iter][jiter]);
            }
            printf("\n");
        }

        printf("Transpose of a given Matrix:\n");
        for(iter = 0; iter < col; iter++)
        {
            for(jiter = 0; jiter < row; jiter++)
            {
                tr_ptr[iter][jiter] = ptr[jiter][iter];
                printf("%d\t",tr_ptr[iter][jiter]);
            }
            printf("\n");
        }
        
        printf("Product of a two matrix:\n");
            for(iter = 0; iter < row; iter++)
            {
                col_temp = 0;
                col_jump = 0;
                row_jump = 0;
                while(col_temp < row)
                {
                    for(jiter = 0; jiter < col; jiter++)
                    {
                        prod =  ptr[iter][col_jump] * tr_ptr[jiter][row_jump];
                        sum += prod;
                        col_jump++;
                    }
                    col_jump = 0;
                    pr_ptr[iter][col_temp] = sum;
                    printf("%d\t",pr_ptr[iter][col_temp]);
                    col_temp++;
                    row_jump++;
                    jiter= 0;
                    sum = 0;
                }
                printf("\n");
            }
        
        printf("Do you want to continue(y/Y):");
        __fpurge(stdin);
        scanf(" %c",&character);
        free(ptr);
        free(tr_ptr);
        free(pr_ptr);
    }while(character == 'y' || character == 'Y');
}
/********************************************************END OF CODE********************************************************************/
