/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 
*   Description     :
*   Input           : 
*   Output          : 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int fact(int);
int length(char *);
int check_distinct(char *);
void pattern(char *);


int main()
{
    char string[100];
    int num,length,count = 0,ret;
    printf("\tCOMBINATIONS OF  NON REPEATATIVE PATTERN STRINGS ");
    printf("\nEnter a non repeatative string : ");
    scanf(" %[^\n]",string);
    ret = check_distinct(string);
        if(ret == 1)
        {
            printf("\nError : Enter distinct characters");
        }
        else
        {
            pattern(string);
        }
}

void pattern(char *string)
{
    static char *point;
    char *ptr,*rev,*base_address;
    ptr = string;rev=string;
    base_address = string;
    int len,no_comb,count = 1;
    char temp;
    point = string;
   len = length(string);
   no_comb = fact(len);
    
   while( no_comb-- != 0 )
   {

       while ( *ptr != '\0' )
       {
           //rev++;
           while ( *rev != '\0')
           {
               temp = *rev;
               *rev = *(rev + (char)count);
               *(rev + (char) count) = temp;
               printf("%s\n",ptr);
               //rev = base_address;
               count++;
           }
           count++;
           //ptr = base_address;
           //printf("%s",rev);
           rev = base_address;
           rev++;
           //ptr++;
           ptr = base_address;
           //count = 0;
           //ptr++;
       }
       ptr = base_address;
       //count--;
   }
               
int length(char *str)
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

int fact(int num)
{
    int prod = 1;
    while(num != 0)
    {
       prod = prod * num;
       num--;
    }
    return prod;
}

int check_distinct( char *string )
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
/********************************************************END OF CODE********************************************************************/
