/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 31/08/2021 
*   Description     : A program to check whether given number is palindrome or not.
*   Input           : 
*   Output          : 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main ()
{
    int num,rev = 0,temp,store,stop;
    
    printf("\tCHECKING FOR PALINDROME NUMBER \nEnter a number to find whether it is a Palindrome or not : ");
    scanf("%d",&num);
    store = num;
    
    do
    {
        if ( num < 9 )
        {
            stop = 1;
            temp = num;
            rev = ( rev * 10 ) + temp;
            printf("\nThe Reversed number is : %d ",rev);
                
                if ( store == rev )
                    printf("\nGiven number %d is a Palindrome Number",store);
                else
                    printf("\nGiven number %d is a NOT a Palindrome Number",store);
        }

        else if ( num > 9 )
        {
            temp = num % 10;
            num = num / 10 ;
            rev = ( rev * 10 ) + temp;
        }
        
    }while ( stop != 1 );

    printf("\n");
    
    return 0;
}
/********************************************************END OF CODE********************************************************************/
