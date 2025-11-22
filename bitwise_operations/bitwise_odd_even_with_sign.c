/*******************************************************DOCUMENTATION*********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 07/09/2021 
*   Description     : A program to check a given number is even or odd and it’s sign using bitwise operators.
*   Input           : ./a.out 
*   Output          :	BITWISE ODD EVEN DETECTOR WITH IT'S SIGN
*                     Enter the value of 'N' : -29
*                     -29 is Negative ODD number
*                     Do you want to continue (y/Y) : y
*
*                     Enter the value of 'N' : 0
*                     0 is Neither ODD nor EVEN and no Signedness
*                     Do you want to continue (y/Y) : y
*
*                     Enter the value of 'N' : 49
*                     49 is POSITIVE ODD number
*                     Do you want to continue (y/Y) : y
*
*                     Enter the value of 'N' : -32
*                     -32 is Negative EVEN number
*                     Do you want to continue (y/Y) : n
*
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main() 
{
    int num;                                                        //declaration of input variables.
    char character;
    printf("\tBITWISE ODD EVEN DETECTOR WITH IT'S SIGN");
    do                                                              //loop to continue the process.
    {
        printf("\nEnter the value of 'N' : ");                      //input fetch.
        scanf("%d",&num);
        
        if ( num == 0 )
            printf("0 is Neither ODD nor EVEN and no Signedness");
        else if ( (((num >> 31) & 1) == 1) )                        //condition to check MSB bit, if MSB = 1 then num is negative.
        {
            if ( (num & 0x01) == 1 )                                //condition to check num is odd or even, if LSB = 1 ODD else EVEN
            printf("%d is Negative ODD number",num);
            else
            printf("%d is Negative EVEN number",num);
        }
        else
        {
            if ( (num & 0x01) == 1 )
            printf( "%d is POSITIVE ODD number",num );
            else
            printf( "%d is POSITIVE EVEN number",num );
        }

        printf("\nDo you want to continue (y/Y) : ");               //next cycle execution input fetch.
        getchar();
        scanf("%c",&character);

    }while ( character == 'y' || character == 'Y' );                //condition for execution of next cycle.

return 0;
}
/********************************************************END OF CODE********************************************************************/
