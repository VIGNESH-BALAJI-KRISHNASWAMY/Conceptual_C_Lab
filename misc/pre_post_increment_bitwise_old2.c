/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 17/09/2021.
*   Description     : A program to create a function to  pre and post increment and passing int pointer as their parameter.
*   Input           : ./a.out 
*                       	RETURNING PRE AND POST INCREMENTED VALUES ALONG WITH THE CURRENT VALUE
*                       Enter a number to be incremented: -1
*                       Enter the operation:
*                          	1.Pre-increment
*                       	2.Post-increment
*                       Enter Your choice: 1
*                       After Pre-increment the return value ret = 0 and the value of number num = 0
*                       Do you want to continue(y/Y) :y
*
*                       Enter a number to be incremented: 0
*                       Enter the operation:
*                        	1.Pre-increment
*                       	2.Post-increment
*                       Enter Your choice: 2
*                       After Post-increment the return value ret = 0 and the value of number num = 1
*                       Do you want to continue(y/Y) :y
*
*                       Enter a number to be incremented: -12
*                       Enter the operation:
*                       	1.Pre-increment
*                       	2.Post-increment
*                       Enter Your choice: 2
*                       After Post-increment the return value ret = -12 and the value of number num = -11
*                       Do you want to continue(y/Y) :n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int pre_inc(int *num);                  //function declaration for pre and post increment.
int post_inc(int *num);                 

int main()
{
    int choice,num,ret;                 //input variables declaration.
    char character;
    printf("\tRETURNING PRE AND POST INCREMENTED VALUES ALONG WITH THE CURRENT VALUE");

    do                                  //loop for continuing the process.
    {
        printf("\nEnter a number to be incremented: ");     //input fetch.
        scanf("%d",&num);
        printf("Enter the operation:\n\t1.Pre-increment\n\t2.Post-increment\nEnter Your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                ret = pre_inc(&num);                        //pre-increment function call.
                printf("After Pre-increment the return value ret = %d and the value of number num = %d",ret,num);
                break;
            case 2:
                ret = post_inc(&num);                       //post-increment function call.
                printf("After Post-increment the return value ret = %d and the value of number num = %d",ret,num);
                break;
        }

        printf("\nDo you want to continue(y/Y) :");         //input fetch for continuing the process.
        scanf(" %c",&character);

    }while ( character == 'y' || character == 'Y');         //condition for next cycle execution.

return 0;
}

int pre_inc(int *num)                                       //pre-increment function definition.
{
    int bit_pos = 0;
    
    if(*num == -1)                                        //condition to over come the -1 (all 11111's) in which 0 from lsb cant be found
    {
        *num = 0;
        return *num;
    }
    
    for (bit_pos = 0; bit_pos < 32; bit_pos++)            //loop to detect the first 0 in the 32 bits from 0 to 31.
    {
        if(((*num >> bit_pos) & 1) == 1);
        else
            break;
    }

    return *num ^= ((1 << bit_pos + 1) - 1);            //toggling the bits till 1st zero from lsb side to increment the number.
}

int post_inc(int *num)                                   //post-increment function definition.
{
    int bit_pos = 0,val = *num;
    
    if(val == -1)                                       //condition to over come the -1 (all 11111's) in which 0 from lsb cant be found.
    {
        *num = 0;
        return val;
    }

    while ((((*num >> bit_pos) & 1) == 1) &&  bit_pos < 32)
        bit_pos++;

    *num ^= ((1 << bit_pos + 1) - 1);
    return val;                                         //returning post increment value.
}
/********************************************************END OF CODE********************************************************************/
