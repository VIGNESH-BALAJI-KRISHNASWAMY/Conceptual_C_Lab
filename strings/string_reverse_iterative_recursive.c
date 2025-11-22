/*******************************************************DOCUMENTATION*********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 06/10/2021.
*   Description     : ass40.strrev
*   Input           :  ./a.out 
*   Output          :   	IMPLEMENTATION OF STRING REVERSE BY ITERATIVE AND RECURSIVE METHOD
*                       1.Iterative method
*                       2.Recursive method
*                       Enter your choice : 1
*                       Enter a string : jdfcdwjnj
*                       After Reversing : jnjwdcfdj 
*                       Do you want to continue (y/Y):y
*
*                       1.Iterative method
*                       2.Recursive method
*                       Enter your choice : 2
*                       Enter a string : emertxe
*                       After Reversing : extreme 
*                       Do you want to continue (y/Y):n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

void iterative(char *);                                                 //function definition.
void recursive(int,int,char*);
int length(char*);

int main()
{
    int choice;                                                         //input vaiable declaration.
    char character;
    printf("\tIMPLEMENTATION OF STRING REVERSE BY ITERATIVE AND RECURSIVE METHOD");
    do                                                                  //loop to continue the processs.
    {
        char string[100];                                               //creating empty array.
        char *ret;                                                      //pointer variable.
        int len;
        printf("\n1.Iterative method\n2.Recursive method\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)                                                  //switch case to select the choice.
        {
            case 1:
                printf("Enter a string : ");                            //input string fetch.
                scanf(" %[^\n]",string);
                iterative(string);                                      //function call.
                printf("After Reversing : %s ",string);
                break;
            case 2:
                printf("Enter a string : ");
                scanf(" %[^\n]",string);
                len = length(string);                                   //function call to find the length of given string.
                recursive(0,len,string);                                //function call.
                printf("After Reversing : %s ",string);
                break;
            default:
                printf("SELECT SUITABLE CHOICE");
        }
        printf("\nDo you want to continue (y/Y):");                     //input fetch for next cycle.
        scanf(" %c",&character);
    }while(character == 'y'|| character == 'Y');                        //condition for next cycle execution.
}

void iterative(char *string)                                            //iterative function definition.
{
    int len,iter,temp;
    char *initial,*final;                                               //declaring pointer variables.
    len = length(string);                                               //function call to find the length of given string.
    initial = string;                                                   //assigning base address to initial pointer.
    final = string + len;                                               //assigning final addesss to final pointer.

    for(iter = len; iter > (len/2); iter--)         //loop to swap the final and initial positions of the string for half of the length.
    {
        temp = *initial;
        *initial = *final;
        *final = temp;

        initial++;                                  //incrementing the base address.
        final--;                                    //decrementing the final address.
    }
}

int length(char *str)                               //length function definition.
{
    int len = 0;
    char temp;
    while(*str != '\0')                             //loop to find the length of the string.
    {
        len++;
        str++;
    }
    return len - 1;                                 //eliminating the null character.
}

void recursive(int initial,int final,char *string ) //recrsive function definition.
{
    char temp;
    temp = *(string + initial);                     //swapping the initial and the final address of a string using temp variable.
    *(string + initial) = *(string + final);
    *(string + final) = temp;
    initial++;                                      //incrementing the initial position.
    final--;                                        //decrementing the final position.
        
    if(initial <= final)
        recursive(initial,final,string);            //recursive function call.
    else
        return;
}
/********************************************************END OF CODE********************************************************************/
