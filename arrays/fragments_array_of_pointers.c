/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 18/10/2021.
*   Description     :
*   Input           : 
*   Output          : 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\tIMPLEMENTING FRAGMENTS USING ARRAY OF POINTERS");
    int iter,jiter,row,col,rough;
    printf("\nEnter the number of rows: ");
    scanf("%d",&row);
    rough = row;
    double *matrix[row];
    int col_size[row],range;
    float sum = 0;
    double *temp;
    int new1,new2;

    for(iter = 0; iter < row; iter++)
    {
        printf("Enter no of columns in row[%d]: ",iter);
        scanf("%d",&col);
        col_size[iter] = col;
        matrix[iter] = malloc((col + 1) * sizeof(double));
    }

    for(iter = 0; iter < row; iter++)
    {
            printf("Enter %d values of row[%d]: ",col_size[iter],iter);
            for(jiter = 0; jiter < col_size[iter]; jiter++)
            {
                scanf("%le",&matrix[iter][jiter]);
                sum += matrix[iter][jiter];
            }
            matrix[iter][jiter] = sum/col_size[iter];
            sum = 0;
    }
    printf("Before Sorting output is:\n");
    for(iter = 0; iter < row; iter++)
    {
        for(jiter = 0; jiter <= col_size[iter]; jiter++)
        {
            printf(" %lg ",matrix[iter][jiter]);
        }
        printf("\n");
    }


    for(iter = 0; iter < row; iter++ )
    {
        jiter = 0;
            for(jiter = 0; jiter < row; jiter++ )
            {
                //printf("arr: %f",matrix[jiter + 1][col_size[jiter + 1]]);
                if ( matrix[iter][col_size[iter]] > matrix[jiter][col_size[jiter]] )//cal average
                {
                    //if( col_size[jiter] > col_size[iter])
                   new1 = col_size[iter];
                   new2 = col_size[jiter];
                       matrix[iter] = realloc(matrix[iter],10);

                    //else if( col_size[iter] > col_size[jiter] )
                       matrix[jiter] = realloc(matrix[jiter],10);

                       // range = (col_size[jiter] > col_size[iter]) ? col_size[jiter] : col_size[iter];
                        //while(range >= 0)
                       // {
                            temp = matrix[jiter];
                            matrix[jiter] = matrix[iter];
                            matrix[iter] = temp;
                            
                       // }
                }
            }
  
    }

    printf("After Sorting output is:\n");
    for(iter = 0; iter < row; iter++)
    {
        for(jiter = 0; jiter <= col_size[iter]; jiter++)
        {
            printf(" %lg ",matrix[iter][jiter]);
        }
        printf("\n");
    }
    //free(matrix);
return 0;
}
/********************************************************END OF CODE********************************************************************/
/*
for ( iter = 0; iter < num1; iter++ )                               //loop to sort array A in ascending order.
 44         {
 45             for ( dyn = 0; dyn < num1 - iter - 1; dyn++ )
 46             {
 47                 if ( array1[dyn] > array1[dyn + 1] )
 48                 {
 49                     temp = array1[dyn];
 50                     array1[dyn] = array1[dyn + 1];
 51                     array1[dyn + 1] = temp;
 52                 }
 53             }
 54         }
 55
*/
