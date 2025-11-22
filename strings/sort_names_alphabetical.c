/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 14/10/2021.
*   Description     : Read n & n person names of maxlen 32. Sort and print the names.
*   Input           : ./a.out 
*   Output          :   	SORTING NAMES IN ALPHABETICAL ORDERS 
*                       Enter the number of names to be sorted: 3
*                       [0] -> rama
*                       [1] -> sita
*                       [2] -> lakshman
*                       After Sorting:
*
*                       [0] -> lakshman
*                       [1] -> rama
*                       [2] -> sita
*                       Do you want to continue (y/Y):y
*
*                       Enter the number of names to be sorted: 5
*                       [0] -> yudistra
*                       [1] -> bheema
*                       [2] -> arjun
*                       [3] -> nakul
*                       [4] -> sahadev
*                       After Sorting:
*
*                       [0] -> arjun
*                       [1] -> bheema
*                       [2] -> nakul
*                       [3] -> sahadev
*                       [4] -> yudistra
*                       Do you want to continue (y/Y):n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
#include <stdlib.h>

void swap(char (*)[32],int);                                    //swap fuction declaration with pointer to array as argument.

int main()
{
    printf("\tSORTING NAMES IN ALPHABETICAL ORDERS ");
    
    int num,row,i,iter,jiter;                               //input and output variables declaration.
    char temp,character;
    do
    {
        printf("\nEnter the number of names to be sorted: ");
        scanf("%d",&num);
        char (*name)[32];                                   //pointer to an array whose column size is 32(fixed)
    
        name = malloc(sizeof(*name) * num);                 //dynamic memory alloation for each row with column size fixed.

        for( row = 0; row < num; row++ )                    //loop to fetch the names.
        {
                printf("[%d] -> ",row);
                scanf(" %32[^\n]",name[row]);
        }
    
        swap(name,num);                                     //function call to swap the names as per alphabetical order.

        printf("After Sorting:\n");
        for( row = 0; row < num; row++ )                    //loop to printed sorted array.
        {
                printf("\n[%d] -> ",row);
                printf("%s",name[row]);
        }

        printf("\nDo you want to continue (y/Y):");         //input fetch for mext cycle.
        scanf(" %c",&character);

    }while( character == 'Y' || character == 'y' );         //condition for next cycle.

return 0;
}

void swap(char (*name)[32],int row)                             //swap function definition.
{
    int iter,jiter,pos = 0;
    char temp;

        for( iter = 0; iter < row; iter++ )                     //loop to swap based on first element in each string.
        {
            for ( jiter = iter + 1; jiter < row; jiter++ )
            {
                if (name[iter][0] > name[jiter][0])             //comparing and swapping 2D array of names.
                {
                    int sort = 31;                              //swapping each elements in an arrary i.e,32 characters in each row.
                    while( sort >= 0 )
                    {
                        temp = name[iter][sort];
                        name[iter][sort] = name[jiter][sort];
                        name[jiter][sort] = temp;
                        sort--;
                    }
                }
            }
        }
}
/********************************************************END OF CODE********************************************************************/

