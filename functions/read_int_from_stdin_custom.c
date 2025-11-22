/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 25/09/2021.
*   Description     : A Function to read_int to read an integer.
*   Input           : ./a.out 
*	Output          :       IMPLEMENTATION OF RETURN INT FUNCTION
*                       Enter a integer value : 123+
*                       The number is :  123
*
*                       Do you want to continue (y/Y): y
*                       Enter a integer value : +123
*                       The number is :  123
*
*                       Do you want to continue (y/Y): y
*                       Enter a integer value : -123
*                       The number is :  -123
*
*                       Do you want to continue (y/Y): y
*                       Enter a integer value : 1qwesdddqw
*                       The number is :  1
*
*                       Do you want to continue (y/Y): y
*                       Enter a integer value : mwdqmdkqm1
*                       The number is :  0
*
*                       Do you want to continue (y/Y): y
*                       Enter a integer value : 1qw23
*                       The number is :  1
*
*                       Do you want to continue (y/Y): y
*                       Enter a integer value : 123-
*                       The number is :  123
*
*                       Do you want to continue (y/Y): y 
*                       Enter a integer value : *123
*                       The number is :  0
*
*                       Do you want to continue (y/Y): n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int ret_int(int *);     //declaring return integer function. 

int main()
{
    int value,number;   //input variable declaration.
    char character;
    printf("\tIMPLEMENTATION OF RETURN INT FUNCTION\n");

    do                                                      //loop to continue the process.
    {
        printf("Enter a integer value : ");                 //input fetch.
 
        printf("The number is :  %d\n",ret_int(&number));   //ret_int function call with the address of the number as a actual argument.
                                                                    //...printing the returned integer value.
        
        printf("\nDo you want to continue (y/Y): ");        //input fetch for next cycle to continue.
        scanf(" %c",&character);
        getchar();                                          //To prevent the got y/Y to intrude into the next cycle of integer fetch.
    
    }while(character == 'y' || character == 'Y');           //condition for continution of next cycle.

return 0;
}

int ret_int(int *ch)                                        //return_int function definition.
{

    int sum = 0,current,negative = 0,error = 0,err_count = 0;   //local variables initialization and declaration.

    while((*ch = getchar()) != '\n')                        //get the character till a new line is reached.
    {
        if(*ch == 45 && sum == 0)            //condition to detect initial - sign, if true then negative flag is set. 
            negative = 1;                   

        else if ( (*ch >= 48 && *ch <= 57) && err_count == 0)  //condition to detect the characters 0 to 9 if error is not set then ...
        {                                                                       //...allows to proceed further.
            current = *ch - 48;             //ASCII value to original number conversion.
            sum = (sum * 10) + current;     //converting the single characters to 'clubbed' integer values.
        }

        else if ( *ch == 43 )           //condition to detect initial + sign and remove it.
            current = *ch;

        else if ( sum == 0 )            //condition to detect initial letter detection, if detected error flag is set.
            error = 1;
        else                            //condition to allow the initial numbers and remove further letters following the numbers
        {                                       //... by incrementing the err_count and not allowing to enter 'clubbing' process.
            err_count++;
        }
    }

    if ( error == 1 )           //if error return 0.
    {
        error = 0;
        return 0;
    }
    else if ( negative == 1 )   //if negative return -sum .
    {
        negative = 0;
        return (-sum);
    }
    else
        return sum;
}
/********************************************************END OF CODE********************************************************************/
