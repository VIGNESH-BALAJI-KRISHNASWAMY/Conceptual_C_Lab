/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 14/10/2021.
*   Description     : Read n & n person names of maxlen 32. Sort and print the names.
*   Input           : ./a.out 
*   Output          :   	SORTING NAMES IN ALPHABETICAL ORDERS 
*                       Enter the number of names to be sorted: 5
*                       [0] -> Diwali
*                       [1] -> Dhandi march
*                       [2] -> Dusshera
*                       [3] -> Bihu
*                       [4] -> Pongal
*                       After Sorting:
*
*                       [0] -> Bihu
*                       [1] -> Dhandi march
*                       [2] -> Diwali
*                       [3] -> Dusshera
*                       [4] -> Pongal
*                       Do you want to continue (y/Y):y
*
*                       Enter the number of names to be sorted: 5
*                       [0] -> Lakshman
*                       [1] -> sita
*                       [2] -> Lanka
*                       [3] -> Raama
*                       [4] -> Raavana
*                       After Sorting:
*
*                       [0] -> Lakshman
*                       [1] -> Lanka
*                       [2] -> Raama
*                       [3] -> Raavana
*                       [4] -> sita
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
                else if (name[iter][0] <= name[jiter][0])      //condition for swappin same value of literal and ignoring small value..
                {                                                       //of literal in ascending order.
                    int change = 0;
                    while ( name[iter][change] == name[jiter][change]) //loop finds till which part the lliterals are same. 
                    {
                        change++;
                    }
                                                                      //swapping each elements in an arrary i.e,32 characters in each row.
                    if( name[iter][change] > name[jiter][change] )
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
}
/********************************************************END OF CODE********************************************************************/

