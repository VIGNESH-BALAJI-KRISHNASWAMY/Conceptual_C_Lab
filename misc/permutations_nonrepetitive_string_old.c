/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 10/10/2021.
*   Description     : A Program to create all possible patterns of given string.
*   Input           : ./a.out 
*   Output          :   	COMBINATIONS OF  NON REPEATATIVE PATTERN STRINGS 
*                       Enter a non repeatative string : ab
*                       ab
*                       ba
*                       Do you want to continue (y/Y):y
*
*                       Enter a non repeatative string : abc
*                       abc
*                       acb
*                       bac
*                       bca
*                       cba
*                       cab
*                       Do you want to continue (y/Y):n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int length(char *);                                                 //function declarations.
int check_distinct(char *);
void swap(char *,char *);
void pattern(char *,int,int);


int main()
{
    char string[100],character;                                     //input and output variable declaration and definition.
    int num,count = 0,ret,len;
    printf("\tCOMBINATIONS OF  NON REPEATATIVE PATTERN STRINGS ");
    do                                                              //loop to continue the process.
    {
        printf("\nEnter a non repeatative string : ");              //input fetch.
        scanf(" %[^\n]",string);
        ret = check_distinct(string);                               //distict characters check function call.
        len = length(string);
            if(ret == 1)
                printf("\nError : Enter distinct characters");
            else
                pattern(string, 0, len-1);
        printf("Do you want to continue (y/Y):");                   //input fetch for next cycle.
        scanf(" %c",&character);
    }while(character == 'y' || character == 'Y');                   //condition for next cycle continution.
}

void pattern( char *string,int initial,int final )       //function definition to generate the patterns.
{
    int iter;
    if ( initial == final  )
    {
        printf("%s\n",string);
    }
    else
    {
       for( iter = initial; iter <= final; iter++ )
       {
            swap( (string + initial),(string + iter) ); //swaping initial element with itself setting the first element to itself.
            pattern ( string, initial + 1, final );     //recursive call to swap the next element succeeding the fixed element.
            swap( (string + initial),(string + iter) ); //swapping to initial positions to make the string available as it was in...
       }                                                    //...previous function.
    }
}
               
int length(char *str)                                   //function to find the length of a given string.
{
    int len = 0;
    char temp;
    while(*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}

int check_distinct( char *string )                      //function to check given characters are distinct or not.
{
    int count = 0; 
    char *base_address,*iterative;
    base_address = string;
    iterative = string;
    ++iterative;
    while(*base_address != '\0')
    {
        while(*iterative != '\0')
        {
            if( *base_address == *iterative )
                return 1;
            iterative++;
            count++;
        }
       ++base_address;
        iterative = iterative - (char)count;
        count = 0;
        ++iterative;
    }
    return 0;
}


void swap( char *lit1, char *lit2 )                             //function to swap the literals in a string.
{
    char temp;
    temp = *lit1;
    *lit1 = *lit2;
    *lit2 = temp;
}
/********************************************************END OF CODE********************************************************************/
