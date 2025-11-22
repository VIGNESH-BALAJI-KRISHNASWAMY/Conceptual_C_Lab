/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 
*   Description     :
*   Input           : 
*   Output          : 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int num,iter,count = 0;
    char character;

    printf("\tGIVEN INTEGER IS A POWER OF 2 OR NOT USING BITWISE OPERATOR");
do
{
    printf("\nEnter a Number: ");
    scanf("%d",&num);

    for ( iter = 1; iter <= 31; iter++ )//should we take (2^0) = 1 as a power of 2 or not! if it's a power of 2 then iter starts from 0
    {
        if ( ((num >> iter) & 1) == 1)
            count++;
    }
    if ( count == 1 )
        printf("%d is a power of 2",num);
    else
        printf("%d is not a power of 2",num);
    
    printf("\nDo you want to Continue (y/Y) : ");
    scanf(" %c",&character);
    count = 0;

}while ( character == 'y' || character == 'Y' );
    
return 0;

}
/********************************************************END OF CODE********************************************************************/
