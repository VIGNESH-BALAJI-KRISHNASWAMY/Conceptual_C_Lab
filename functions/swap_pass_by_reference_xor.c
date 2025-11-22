/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 15/09/2021. 
*   Description     : A Program to swap two variables by using pass by reference method.
*   Input           : ./a.out 
*   Output          :           SWAPPING VALUES USING PASS BY REFERENCE METHOD
*                       Enter a number 'num1': 23
*                       Enter a number 'num2': 32
*                       After Swapping Values : 
*                       num1 = 32 
*                       num2 = 23
*                       Do you want to continue: y
*
*                       Enter a number 'num1': -39
*                       Enter a number 'num2': 93
*                       After Swapping Values :
*                       num1 = 93
*                       num2 = -39
*                       Do you want to continue: n
*                                      
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
void swap(int *num1, int *num2);                                  //Swap function declaration.

int main()
{
        int num1,num2;                                            //input variables declaration.
        char character;
        printf("\tSWAPPING VALUES USING PASS BY REFERENCE METHOD");
    do                                                            //Continue loop.
    { 
        printf("\nEnter a number 'num1': ");                      //input fetch.
        scanf("%d",&num1);
        printf("Enter a number 'num2': ");
        scanf("%d",&num2);
        swap(&num1,&num2);                                        //function call.
        printf("After Swapping Values : \nnum1 = %d \nnum2 = %d",num1,num2);
    
        printf("\nDo you want to continue: ");                    //input fetch for while loop.
        scanf(" %c",&character);
    
    }while (character == 'y' || character == 'Y' );

return 0;
}

void swap(int *num1,int *num2)                                    //swap function definition
{
    *num1 = *num1 ^ *num2;     //num1 (-/+) num2 using ex-or operation.(num1 = num1 + num2)
    *num2 = *num1 ^ *num2;     //(num2 = num1 - num2) (+/-) decided by the carry or borrow bits which here are not considered.
    *num1 = *num1 ^ *num2;     //(num1 = num1 - num2) ex-or provide same output even in addition and subtraction.
}
/********************************************************END OF CODE********************************************************************/
