/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 31/08/2021 
*   Description     : PATTERNS
*   Input           : ./a.out
*   Output          : Enter the number of lines to display the patterns: 4
    1 
    1 2 
    1 2 3 
    1 2 3 4 

    1 
    2 3 
    4 5 6 
    7 8 9 10 

    * * * * 
      * * * 
        * * 
          * 

    * * * * 
      * * * 
        * * 
          * 

       * 
      * * 
     * * * 
    * * * * 

        *
       * *
      * * *
     * * * *
      * * *
       * *
        *
 
*
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int num,row,column,inc = 0,space,rev_space;
    printf("Enter the number of lines to display the patterns: ");
    scanf("%d",&num);

    for ( row = 1; row <= num; row++ )                                  //Pattern 1
    {
        for ( column = 1; column <= row; column++ )
        {
            printf("%d ",column);
        }
        printf("\n");
    }
        printf("\n");                                                   //End of pattern 1

    for ( row = 1; row <= num; row++ )                                  //pattern 2
    {
        for ( column = 1; column <= row; column++ )
        {
            ++inc;
            printf("%d ",inc);
        }
        printf("\n");
    }
        
        printf("\n");                                                   //End of pattern 2

    for ( row = 1; row <= num; row++ )                                  //pattern 3
    {
        for ( column = 1; column <= num; column++ )
        {
            if ( column >= row  )
            printf("* ");
            else
            printf("  ");
        }
        printf("\n");                                                   //End of pattern 3
    }
printf("\n");

    for ( row = 1; row <= num; row++ )                                  //pattern 4
    {
        for ( space = 1; space < row ; space++ )
        {
            printf("  ");
        }
        for ( column = row; column <= num; column++ )
        {
            printf("* ");
        }
        printf("\n");
    }                                                                     //End of pattern 4

printf("\n");

    for ( row = 1; row <= num; row++ )                                    //Pattern 5
    {
        for ( space = 1; space <= num - row; space++ )
        {
            printf(" ");
        }
        for ( column = 1; column <= row; column++ )
        {
            printf("* ");
        }
        printf("\n");
    }                                                                      //End of Pattern 5
   
printf("\n");

    for ( row = 1; row <= num; row++ )                                      //pattern 6
    {
        for ( space = 1; space <= num - row; space++ )
        {
            printf(" ");
        }
        for ( column = 1; column <= row; column++ )
        {
            printf(" *");
        }
        printf("\n");
    }
        if ( row >= num )
        {
            --num;
            rev_space = num; //initializing a static independant variable to be used in the forthcoming loops to print the mirror image of top.
            for ( row = num; row >= 1; row-- )
            {
                for ( space = 1; space > row - rev_space; space-- )
                {
                    printf(" ");
                }
                for ( column = 1; column <= row; column++ )
                {
                    printf(" *");
                }
                printf("\n");
                num--;
                
            }
        }                                                                     //End of pattern 6

    return 0;
}
/********************************************************END OF CODE********************************************************************/
