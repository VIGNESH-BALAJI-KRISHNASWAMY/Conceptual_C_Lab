/*******************************************************DOCUMENTATION********************************************************************
*                                                                                                                                       *
*   Name            : K.Vignesh Balaji                                                                                                  *
*   Date            : 30/08/2021                                                                                                        *
*   Description     : A Program to check whether a given number is odd or even and its signedness.                                      *
*   Input           : ./a.out                                                                                                           *
*   Output          : FINDING GIVEN NUMBER 'n' IS ODD OR EVEN WITH IT'S SIGNEDNESS                                                      *
*                                                                                                                                       *
*   Enter the value of 'n' :-121                                                                                                        *
*   -121 is -ve ODD number                                                                                                              *
*   Do you want to continue(y/Y) or (n/N): y                                                                                            *
*                                                                                                                                       *
*   Enter the value of 'n' :122                                                                                                         *
*   122 is +ve EVEN number                                                                                                              *
*   Do you want to continue(y/Y) or (n/N): e                                                                                            *
*                                                                                                                                       *
*   Do you want to continue(y/Y) or (n/N): y                                                                                            *
*                                                                                                                                       *
*   Enter the value of 'n' :0                                                                                                           *
*   '0' is Neither ODD nor EVEN                                                                                                         *
*   Do you want to continue(y/Y) or (n/N): Y                                                                                            *
*                                                                                                                                       *
*   Enter the value of 'n' :30000000                                                                                                    *
*   Number out of range!                                                                                                                *
*   Do you want to continue(y/Y) or (n/N): N                                                                                            *
*                                                                                                                                       *
********************************************************START OF CODE********************************************************************/

#include <stdio.h>

int main()
{
    printf("\tFINDING GIVEN NUMBER 'n' IS ODD OR EVEN WITH IT'S SIGNEDNESS\n"); //Heading statement.
    
    int numb,iter,prod=1,neg_prod,rem;                                          //Integer and Character variable initialization.
    char next_cycle;
    
    for ( iter = 0; iter < 20; iter++ )                                         //Loop for setting Positive Range in terms of 2^iteration.
    {
        prod = prod * 2 ;
    }
    neg_prod = -1 * prod ;                                                      //Finding Negative Range from positive range.

    do                                                                          //Loop to check whether next cycle should run or not.
    {
        printf("\nEnter the value of 'n' :");
        scanf("%d", &numb);                                                     //Getting a number to check.
        rem = numb % 2;                                                         //Even condition check.
        
        if ( numb == 0 )
            printf("'%d' is Neither ODD nor EVEN",numb);
        
        else if ( numb < 0 && numb > neg_prod )                                 //condition for negative number within -ve range.
        {
            if ( rem == 0 )
                printf("%d is -ve EVEN number",numb);
            else
                printf("%d is -ve ODD number",numb);
        }
        
        else if ( numb > 0 && numb < prod )                                     //condition for positive number within +ve range.
        {
            if ( rem == 0 )
                printf("%d is +ve EVEN number",numb);
            else
                printf("%d is +ve ODD number",numb);
        }
        
        else
            printf(" Number is out of range!");                                 //Condition to indicate numbers which are out of range.
    
            do                                                                  //Loop to check & correct input for next cycle execution.
            {
                printf("\n Do you want to continue(y/Y) or (n/N): " );
                scanf(" %c",&next_cycle);
            }while ( next_cycle != 'Y' && next_cycle != 'N' && next_cycle != 'y' && next_cycle != 'n' );

    } while ( next_cycle == 'y' || next_cycle == 'Y' );                         //condition for next cycle execution.
return 0;
}


/***********************************************************END OF CODE******************************************************************/
