/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 18/10/2021.
*   Description     : A Program to implement fragments using Array of Pointers (First Static Second Dynamic).
*   Input           : ./a.out 
*	Output          :       IMPLEMENTING FRAGMENTS USING ARRAY OF POINTERS
*                       Enter the number of rows: 5
*                       Enter no of columns in row[0]: 1
*                       Enter no of columns in row[1]: 3
*                       Enter no of columns in row[2]: 4
*                       Enter no of columns in row[3]: 5
*                       Enter no of columns in row[4]: 2
*                       Enter 1 values of row[0]: 8
*                       Enter 3 values of row[1]: 2 3 4
*                       Enter 4 values of row[2]: 0 0 0 0
*                       Enter 5 values of row[3]: 1 2 3 4 5
*                       Enter 2 values of row[4]: 0 0
*                       Before Sorting output is:
*                        8  8 
*                        2  3  4  3 
*                        0  0  0  0  0 
*                        1  2  3  4  5  3 
*                        0  0  0 
*                       After Sorting output is:
*                        0  0  0  0  0 
*                        0  0  0 
*                        1  2  3  4  5  3 
*                        2  3  4  3 
*                        8  8 
*                       Do you want to continue(y/Y):n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main()
{
    printf("\tIMPLEMENTING FRAGMENTS USING ARRAY OF POINTERS");
    int iter,jiter,row,col,rough;                                //input variables declaration.
    char character;

    do                                                           //loop to continue the process.
    {
        printf("\nEnter the number of rows: ");                  //fetching no.of row from user.
        scanf("%d",&row);
        rough = row;
        double *matrix[row];                                     //(First Static) array of pointer to point the base address of each row. 
        int col_size[row],range,new1,new2;                       //input variables and rough array declaration. 
        float sum = 0;
        double *temp;                                            //temprary pointer.

        for(iter = 0; iter < row; iter++)                        //loop to fetch the size of col for each row.(Second Dynamic)
        {
            printf("Enter no of columns in row[%d]: ",iter);
            scanf("%d",&col);
            col_size[iter] = col;                                //storing the information of col_size in rough array for future purpose
            matrix[iter] = malloc((col + 1) * sizeof(double)); //dynamic memory allocation to form columns of different size in each row.
        }

        for(iter = 0; iter < row; iter++)                               //loop to traverse each row.
        {
            printf("Enter %d values of row[%d]: ",col_size[iter],iter); 
                for(jiter = 0; jiter < col_size[iter]; jiter++)         //loop to fetch the Column elements of each row.
                {
                    scanf("%le",&matrix[iter][jiter]);
                    sum += matrix[iter][jiter];                    //finding sum of elements in each row.
                }
            matrix[iter][jiter] = sum/col_size[iter];              //finding average of each row and store it in last col in each row.
            sum = 0;                                               //reinitializing for next cycle.
        }
        printf("Before Sorting output is:\n");                     //loop to print the matrix before sorting based on average of each row.
        for(iter = 0; iter < row; iter++)
        {
            for(jiter = 0; jiter <= col_size[iter]; jiter++)
            {
                printf(" %lg ",matrix[iter][jiter]);
            }
            printf("\n");
        }


        for(iter = 0; iter < row; iter++ )          //loop to sort the array based on average of each row.
        {
                for(jiter = iter+1; jiter < row; jiter++ )
                {
                    if ( matrix[iter][col_size[iter]] > matrix[jiter][col_size[jiter]] )//condition to compare average of each row.
                    {
                            temp = matrix[jiter];                       //swapping the base address i.e row base address
                            matrix[jiter] = matrix[iter];
                            matrix[iter] = temp;
                            new1 = col_size[jiter];            //swapping the column size of the respective swapped base address of rows.
                            col_size[jiter] = col_size[iter];
                            col_size[iter] = new1;
                    }
                }
        }

        printf("After Sorting output is:\n");                   //loop to print the sorted array.
        for(iter = 0; iter < row; iter++)
        {
            for(jiter = 0; jiter <= col_size[iter]; jiter++)
            {
                printf(" %lg ",matrix[iter][jiter]);
            }
            printf("\n");
        }
        
        for(iter = 0; iter < row; iter++)                       //loop to deallocate the memory of array of pointers.
        {
            free(matrix[iter]);
        }

        printf("Do you want to continue(y/Y):");                //input fetch for next cycle.
        __fpurge(stdin);
        scanf(" %c",&character);
    }while(character == 'Y' || character == 'y' );              //condition for next cycle execution.
return 0;
}
/********************************************************END OF CODE********************************************************************/
