/*******************************************************DOCUMENTATION*********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 10/09/2021 
*   Description     : A Program  to print all primes smaller than or equal to given number n  using Sieve of Eratosthenes method.
*   Input           : ./a.out 
*   Output          :   PRINTING ALL PRIME NUMBERS SMALLER THAN OR EQUAL TO A GIVEN NUMBER 'n'
*
*                     Enter a number till which prime number is to be printed : 10
*                     Before Execution SOE: 2,3,4,5,6,7,8,9,10.
*                     The prime numbers present within 10 are: 2,3,5,7,.
*                     Do you want to continue (y/Y) : y
*
*                     Enter a number till which prime number is to be printed : 20
*                     Before Execution SOE: 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20.
*                     The prime numbers present within 20 are: 2,3,5,7,11,13,17,19,.
*                                                              
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int num,iter,dyn,prod = 1,half,res,count = 0;   //initialization and declaration of input and output variables.
    char character;

    printf("\tPRINTING ALL PRIME NUMBERS SMALLER THAN OR EQUAL TO A GIVEN NUMBER 'n' \n");
    
    for ( iter = 1; iter <= 20; iter++ )                        //loop to set the range for input.
    {
        prod = prod * 2;
    }
    
    do                                                          //loop to perform the next cycle.
    {
        printf("\nEnter a number till which prime number is to be printed : ");       //input fetch.
        scanf("%d",&num);
        
        if ( num > prod || num <= 0)                                                //condition to detect error input.
        printf("ERROR:Number 'n' out of range! RANGE : 0 < 'n' <= 2^20");
        else if ( num == 1 )
            printf("INFO:1 is neither prime nor composite!");
        else
        {
            int array[num];                                                         //array declaration with size.
            
            printf("Before Execution SOE: ");
            for ( iter = 0; iter <= num - 2; iter++ )            //Loop to store the array with values from 2 to given number 'num'.
            {
                array[iter] =  iter + 2;
                ( iter < num - 2 )?printf("%d,",array[iter]):printf("%d.",array[iter]); //condition for presentation 
            }
            
            half = num / 2 ;   //Reducing the size of iteration to half, as per the requirement of method of SOE.
            for ( iter = 0; iter < half; iter++ )
            {
                    if ( array[iter] != 0 )                      //condition to avoid modulo by 0 error.
                    {
                        for ( dyn = iter + 1; dyn < num; dyn++ ) //loop to set composite number to 0.
                        {
                            if ( array [dyn] != 0 )              //condition to avoid checking the present 0 elements.
                            {
                                res = array[dyn] % array[iter];
                                if ( res == 0 )                     //condition to detect composite number.
                                    array[dyn] = 0;                 //setting composite number to 0.
                            }
                        }
                    }             
            }

            printf("\nThe prime numbers present within %d are: ",num);
            for ( iter = 0; iter <= num - 2; iter++ )           //loop to display the prime number within the given number.
            {
              if ( array[iter] != 0 )
                 (iter < num - 2)?printf("%d,",array[iter]):printf("%d.",array[iter]); //presentation for . and ,
              else if ( iter == num - 2 )
                  printf(".");
            }
        }
            
        printf("\nDo you want to continue (y/Y) : ");           //input fetch for next cycle.
        getchar();
        scanf("%c",&character);

    } while ( character == 'y' || character == 'Y');             //condition for next cycle to run.

    return 0;
}
/********************************************************END OF CODE*********************************************************************/
