/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 02/10/2021
*   Description     : A Function for pre and post increment and passing int pointer as their parameter WITHOUT USING +,-,++,-- EVEN ONCE.
*   Input           :  ./a.out 
*	Output          :       RETURNING PRE AND POST INCREMENTED VALUES ALONG WITH THE CURRENT VALUE
*                       Enter a number to be incremented: -1
*                       Enter the operation:
*                       	1.Pre-increment
*                       	2.Post-increment
*                       Enter Your choice: 1
*                       After Pre-increment ret = 0, num = 0
*                       Do you want to continue(y/Y) :y
*
*                       Enter a number to be incremented: 999
*                       Enter the operation:
*                       	1.Pre-increment
*                       	2.Post-increment
*                       Enter Your choice: 2
*                       After Post-increment ret = 999, num = 1000
*                       Do you want to continue(y/Y) :n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int bitwise_increment(int *num,int);    //function declaration for bitwise incrementation.

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
                printf("After Pre-increment ret = %d, num = %d",ret,num);
                break;
            case 2:
                ret = post_inc(&num);                       //post-increment function call.
                printf("After Post-increment ret = %d, num = %d",ret,num);
                break;
        }

        printf("\nDo you want to continue(y/Y) :");         //input fetch for continuing the process.
        scanf(" %c",&character);

    }while ( character == 'y' || character == 'Y');         //condition for next cycle execution.

return 0;
}

int pre_inc(int *numb)                              //pre_increment function definition.
{
    int pre_post_set = 1;                           //initializing pre_post_set to 1.
    return bitwise_increment(numb,pre_post_set);    //calling bitwise_increment function with pre incrementation key(pre_post_set = 1). 
}

int post_inc(int *numb)                             //post_increment function definition.
{
    int ret, pre_post_set = 0;                      //initializing pre_post_set to 0.
    return bitwise_increment(numb,pre_post_set);    //calling bitwise_increment function with post incrementation key(pre_post_set = 0). 
}

int bitwise_increment(int *numb, int pre_post)      //bitwise incrementation function definition.
{
    int ret = *numb,mask = 1,shift = 1,temp = 0;    //initializing  the processing variables.

    if ( (*numb & 1) == 1 )                         //checking LSB to decide even or odd number. If part runs if the number is odd. 
    {
        while ( ( *numb & mask ) != 0 )             //finding the first 0 from LSB using while loop.
            mask = mask << 1;                       //creating the mask by shifting left side till 1'st 0 is found from lsb.
        while( (mask ^ shift) != 0 )                //loop to find temp = (mask - 1)... i.e, if mask = 1000 then temp = 111.
        {
           temp = temp | 1;
           temp = temp << 1;
           shift = shift << 1;
        }
        temp = temp | 1;

        if(pre_post == 1)                           //if part runs for pre-increment 
            return *numb = *numb ^ temp;            //toggling the bits till first 0 from LSB
        else                                        //else part for post increment.
        {
            *numb = *numb ^ temp;
            return ret;
        }
    }
    else                                            //else part runs if the number is even.
    {
        if(pre_post == 1)                           //pre increment case.
            return *numb = *numb ^ mask;            //change the LSB to 1 to increment the even number.
        else
        {                                           //post increment case.
            *numb = *numb ^ mask;
            return ret;
        }
    }
}
/********************************************************END OF CODE********************************************************************/
