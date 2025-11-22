/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 01/09/2021 
*   Description     : A Program to check whether a given number is perfect or not.
*   Input           : ./a.out 
*   Output          :              	GIVEN NUMBER IS PERFECT OR NOT
*                      Enter a Number to check whether it is perfect or not : -6
*                      ERROR:Please provide only positive numbers!
*                      Do you want to continue : y
*
*                      Enter a Number to check whether it is perfect or not : 0
*                      DEFAULT:'0' is not a perfect number!
*                      Do you want to continue : y
*
*                      Enter a Number to check whether it is perfect or not : 6
*                      6 is a PERFECT number
*                      Do you want to continue : y
*
*                      Enter a Number to check whether it is perfect or not : 8128
*                      8128 is a PERFECT number
*                      Do you want to continue : y
*
*                      Enter a Number to check whether it is perfect or not : 26
*                      26 is a NOT A PERFECT number
*                      Do you want to continue : n
*                                                            
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int num, divisor, sum_of_divisors = 0;          //initialization and declaration of input variables.
    int prod = 1, power, max_range;                 //initialization and declaration of variables for range calculation
    char character;

    for ( power = 0; power < 20; power++ )          //loop to calculate max range i.e.2^20                              
    {
        prod = prod * 2 ;
    }
    max_range = prod;

    printf("\tGIVEN NUMBER IS PERFECT OR NOT");

  do                                                //loop to continue the operation
  {
        printf("\nEnter a Number to check whether it is perfect or not : ");        //input fetching.
        scanf("%d",&num);

        if (num == 0)                                                               //input validation.
            printf("DEFAULT:'0' is not a perfect number!");

        else if ( num > max_range )
            printf("ERROR:Number out of range!");

        else if ( num < 0 )
            printf("ERROR:Please provide only positive numbers!");

        else
        {
            for ( divisor = 1; divisor <= num; divisor++ )                          //loop to find the given number's divisors
            {
                if ( (num % divisor) == 0 )
                    sum_of_divisors = sum_of_divisors + divisor;                    //addition of existing divisors of given number.
            }

            if ( (sum_of_divisors / 2) == num )                                     //condition for a perfect number.
                printf("%d is a PERFECT number",num);
            else
                printf("%d is a NOT A PERFECT number",num);
        }

        printf("\nDo you want to continue : ");                                     //input fetch to continue operation
        getchar();
        scanf("%c",&character);

        sum_of_divisors = 0;                                          //reinitializing for next cycle, though the cycle  exists or not.
        divisor = 1;

  } while (character == 'y' || character == 'Y');

    return 0;
}
/********************************************************END OF CODE********************************************************************/
