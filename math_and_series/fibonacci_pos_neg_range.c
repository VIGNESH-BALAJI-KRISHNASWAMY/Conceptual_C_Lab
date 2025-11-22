/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 01/09/2021 
*   Description     : A Program  to generate both positive and negative fibbonacci numbers till <= given number 'n' 
*   Input           : ./a.out 
*   Output          :	        FIBONACCI SEQUENCE TILL GIVEN NUMBER
*                        Enter the number till which FIBONACCI sequence to be printed : -1
*                        The Negative Fibonacci series till -1 is : 0,1,-1.
*                        Do you want to continue : y
*
*                        Enter the number till which FIBONACCI sequence to be printed : -2
*                        The Negative Fibonacci series till -2 is : 0,1,-1,2.
*                        Do you want to continue : y    
*
*                        Enter the number till which FIBONACCI sequence to be printed : 2
*                        The Positve Fibonacci series till 2 is : 0,1,1,2.
*                        Do you want to continue : y   
*
*                        Enter the number till which FIBONACCI sequence to be printed : 1
*                        The Positve Fibonacci series till 1 is : 0,1,1.
*                        Do you want to continue : y
*
*                        Enter the number till which FIBONACCI sequence to be printed : 20000000
*                        Error : Number out of range, please enter the value -2^20 < 'N' < 2^20
*                        Do you want to continue : y
*
*                        Enter the number till which FIBONACCI sequence to be printed : 0
*                        The Fibonacci series till 0 is : 0
*                        Do you want to continue : n
*
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int prod = 1,max_range,min_range,power;             //initialization and declaration for range setting
    int num,iter,current,previous,next,stop;            //declaration of input variables
    char character;

    printf("\tFIBONACCI SEQUENCE TILL GIVEN NUMBER");
    
    for ( power = 0; power < 20; power++ )              //loop to produce 2's power i.e. maximum range.
    {
        prod = prod * 2 ;
    }
    max_range = prod;
    min_range = -1 * prod;                              //minimum range.
    
    do                                                  //loop to perform continuous operation.
    {
        printf("\nEnter the number till which FIBONACCI sequence to be printed : ");            //input fetching
        scanf("%d",&num);
        previous = 1;//initialization(will be effective only in 0th iteration, in next variable in both +ve and -ve FS)
        current = 0;//initialization(will be effective only in 0th iteration, in previous variable in both +ve and -ve FS)

        if ( num > max_range || num < min_range )                                               //input validation
            printf("Error : Number out of range, please enter the value -2^20 < 'N' < 2^20");
        else if ( num == 0 )
            printf("The Fibonacci series till 0 is : 0");
        else
        {
            if ( num > 0 )                                                  //condition to perform +ve Fibonacci series execution.
            {
                printf("The Positve Fibonacci series till %d is : ",num);
                for ( iter = 0; num >= current ; iter++ )                  //loop to perform +ve FS
                {
                    next = previous + current;
                    previous = current;
                    current = next;
                    printf("%d",previous);                  //data to be printed in each iteration of +FS.
                    if ( current > num )                   //condition for presentation of comma(,) and stop(.)
                        printf(".");
                    else
                        printf(",");
                }
            }

            else if ( num < 0 )                                                             //condition to perform -ve FS execution.
            {
                printf("The Negative Fibonacci series till %d is : ",num);
                stop = num;                                 //condition to generate "min" and "max" for range for -ve FS
                num = -1 * num;
                for ( iter = 0; ;iter++)          //loop to iterate whose conditional statements are set implicitly by cond 1 and cond 2.
                {
                    next = previous - current;
                    previous = current;
                    current = next;
                        if ( previous < 0 )
                        {
                            if ( previous < stop )//condition 1 to break the loop.If the number to be printed is less than negative "min".
                            {
                                printf(".");
                                break;
                            }
                            else
                                printf(",");
                        }
                        else if ( previous > 0 )
                        {
                            if ( previous > num ) //condition 2 to break the loop.If the number to be printed is greater than +ve "max".
                            {
                                printf(".");
                                break;
                            }
                            else
                                printf(",");
                        }
                    printf("%d",previous);  //data to be printed in each iteration.
                }
       
            }
        }

     printf("\nDo you want to continue : ");    //condition for continuous execution
     getchar();
     scanf("%c",&character);

    }while (character == 'y' || character == 'Y');  //loop for continuous execution.

        return 0;
}
/********************************************************END OF CODE********************************************************************/
