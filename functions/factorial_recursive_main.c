/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 22/09/2021.
*   Description     : Program to find factorial for given number using recursion and without using any other function than main function
*   Input           : ./a.out 
*   Output          :
*                       Enter a number 'N' : -1
*                       ERROR:INVALID INPUT!
*                       Do you want to continue (y/Y): y
*
*                       Enter a number 'N' : 0
*                       Factorial of 0 is: 1
*                       Do you want to continue (y/Y): y
*
*                       Enter a number 'N' : 5
*                       Factorial of 5 is: 120
*                       Do you want to continue (y/Y): y
*
*                       Enter a number 'N' : 100
*                       Factorial of 100 is: 9.33262e+157
*                       Do you want to continue (y/Y): n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main(int num)                               //main function with explicit int declaration.
{
 
    static long double prod = 1;                //input and output variables delaration and initialization.
    static int flag = 0,disp_num,error = 0;
    char character;
        
    if ( flag == 0 )                            //flag to fetch next input.
    {
        printf("\nEnter a number 'N' : " );     //input fetch.
        scanf("%d",&num);
            if ( num < 0 )                      //input validation.
                error = 1;
            else if ( num == 0 )                //0! detection.
            {
                num = 1;
                disp_num = 0;
                flag = 1;
                return main(num);               //calling main funcion.
            }
            else
                disp_num = num;
         flag = 1;                              //flag == 1 cannot fetch the input in next call. 
    }
    
    if ( error == 0 )                           //negative input detection.
    {
        prod *= num;                            //logic to find factorial of n!= n(n-1)
        --num;
        
        if( num != 0)
            return main(num);                   //calling main untill n != 0 

        printf("Factorial of %d is: %Lg",disp_num,prod);
    }

    else
    {
        printf("ERROR:INVALID INPUT!");
        error = 0;
    }
    
    printf("\nDo you want to continue (y/Y): "); //continue prompt.
    scanf(" %c",&character);
    
    if(character == 'y' || character == 'Y')  
    {
        flag = 0;                                //flag == 0 allows the input fetch in next cycle of main call.
        prod = 1;
        main(num);                              //main call for next new value to find n!.
    }

return 0;
}
/********************************************************END OF CODE********************************************************************/
