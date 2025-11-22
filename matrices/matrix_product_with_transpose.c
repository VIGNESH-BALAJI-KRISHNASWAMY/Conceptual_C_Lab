/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 
*   Description     : A Program to find the product of given matrix.
*   Input           : ./a.out 
*   Output          :   	PRODUCT OF A GIVEN MATRIX
*                       Enter the number of rows:4
*                       Enter the number of columns:2
*                       Enter values for 4 x 2 matrix:
*                       1	2
*                       1	2
*                       1	2
*                       1	2
*
*                       Given Matrix:
*                       1	2	
*                       1	2	
*                       1	2	
*                       1	2	
*                       Transpose of a given Matrix:
*                       1	1	1	1	
*                       2	2	2	2	
*                       Product of a two matrix:
*                       5	5	5	5	
*                       5	5	5	5	
*                       5	5	5	5	
*                       5	5	5	5	
*                       Do you want to continue(y/Y):y
*
*                       Enter the number of rows:3
*                       Enter the number of columns:3
*                       Enter values for 3 x 3 matrix:
*                       1 2 3
*                       1 2 3
*                       1 2 3
*
*                       Given Matrix:
*                       1	2	3	
*                       1	2	3	
*                       1	2	3	
*                       Transpose of a given Matrix:
*                       1	1	1	
*                       2	2	2	
*                       3	3	3	
*                       Product of a two matrix:
*                       14	14	14	
*                       14	14	14	
*                       14	14	14	
*                       Do you want to continue(y/Y):n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

void product(int,int,int (*)[],int (*)[],int (*)[]);            //declaration of product function to find the product of two matrices.

int main()
{
    int row,col,iter,jiter;                                     //input variables declarations.
    char character;

    printf("\tPRODUCT OF A GIVEN MATRIX");
    do                                                          //loop to continue the process.
    {
        printf("\nEnter the number of rows:");                  //input fetch for no.of rows and columns.
        scanf("%d",&row);
        if( row <= 0)
            printf("ERROR:Provide only positive values greater than 0");
        else
        {
            printf("Enter the number of columns:");
            scanf("%d",&col);
            printf("Enter values for %d x %d matrix:\n",row,col);
            if( col <= 0)
                printf("ERROR:Provide only positive values greater than 0");
            else
            {  
                int (*ptr)[col + 2];         //fixing the column size(second static) of pointer,transpose pointer,product pointer with...
                int (*tr_ptr)[col + 2];             //...extra size of +2 to prevent the memory leak and error in output.
                int (*pr_ptr)[row + 2];     //since product of non square matrices e.g 2x3 && 3x2 produce 2x2 matrix as output, use...
                                                    //...row size to fix the column size in resultant matrix.

                ptr = malloc(sizeof(*ptr) * (row + 2));         //Dynamic row size allocation(First Dynamic) for all three pointers. 
                tr_ptr = malloc(sizeof(*tr_ptr) * (row + 2));
                pr_ptr = malloc(sizeof(*pr_ptr) * (row + 2));

                for(iter = 0; iter < row; iter++)           //loop to scan the Row x Col matrix elements 
                {
                    for(jiter = 0; jiter < col; jiter++)
                    {
                        scanf("%d",&ptr[iter][jiter]);
                    }
                }

                printf("\nGiven Matrix:\n");                //loop to print the given matrix.
                for(iter = 0; iter < row; iter++)
                {
                    for(jiter = 0; jiter < col; jiter++)
                    {
                        printf("%d\t",ptr[iter][jiter]);
                    }
                    printf("\n");
                }

                printf("Transpose of a given Matrix:\n");   //loop to print the Transpose of the given matrix.
                for(iter = 0; iter < col; iter++)
                {
                    for(jiter = 0; jiter < row; jiter++)
                    {
                        tr_ptr[iter][jiter] = ptr[jiter][iter];   //storing the found transpose matrix elements in the dynamic memory...
                        printf("%d\t",tr_ptr[iter][jiter]);         //...pointed by tr_ptr.
                    }
                    printf("\n");
                }
        
                printf("Product of a two matrix:\n");
                product(row,col,ptr,tr_ptr,pr_ptr);    //function call to find the product of given matrix and transpose of given matrix

                for(iter = 0; iter < row; iter++)       //loop to print the Product of the matrices.
                {
                    for(jiter = 0; jiter < row; jiter++)
                    {
                        printf("%d\t",pr_ptr[iter][jiter]);
                    }
                    printf("\n");
                }
        
                printf("Do you want to continue(y/Y):");    //input fetch for next cycle.
                __fpurge(stdin);
                scanf(" %c",&character);

                free(ptr);                                  //deallocation of memory pointed by ptr,tr_ptr and pr_ptr.
                free(tr_ptr);
                free(pr_ptr);
            }
        }
    }while(character == 'y' || character == 'Y');
}


void product(int row,int col,int (*ptr)[col + 2],int (*tr_ptr)[col + 2],int(*pr_ptr)[row + 2]) //product function definition.
{

    int iter,jiter,col_temp,col_jump,row_jump,sum = 0,prod; //local variables declaration.
          
    for(iter = 0; iter < row; iter++)   //loop to traverse the row of given matrix.
    {
        col_temp = 0;                   //reinitializing for next cycle.
        col_jump = 0;
        row_jump = 0;
        while(col_temp < row)           //loop to traverse all columns of transpose matrix.
        {
          for(jiter = 0; jiter < col; jiter++) //loop to perform subsequent row jump and col jump in given matrix and transpose matrix.
          {
            prod =  ptr[iter][col_jump] * tr_ptr[jiter][row_jump];  //condition to perform 2D array multiplication between A and AT.
            sum += prod;
            col_jump++;
          }
            col_jump = 0;
            pr_ptr[iter][col_temp] = sum;   //storing the result in the product matrix pointed by pr_ptr.
            col_temp++;                     //Alterations for subsequent iterations.
            row_jump++;
            jiter= 0;
            sum = 0;
         }
     }
}       
/********************************************************END OF CODE********************************************************************/
