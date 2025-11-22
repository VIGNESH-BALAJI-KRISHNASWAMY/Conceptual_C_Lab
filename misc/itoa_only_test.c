/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 
*   Description     : Implement getword, atoi, itoa functions
*   Input           : 
*   Output          : 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int itoa(int,char*);
int main()
{
    int choice,ret,number,stop;
    char *str;
    char word[50],string[100];

    printf("\tIMPLEMENTING GETWORD, ATOI, ITOA, FUNCTIONS ");
    printf("\n1. getword\n2. atoi\n3. itoa\nEnter your choice : ");
    scanf("%d",&choice);

    switch (choice)
    {
            
        case 3:
            printf("\tIMPLEMENTING ITOA FUNCTION");
            printf("\nEnter a Number :");
            scanf("%d",&number);
            ret = itoa(number,string);
            printf("Integer to String is '%.*s' \n",ret,string);
            break;
    }
return 0;
}

int itoa(int num,char *array)
{

    int length = 0,temp = num,set = 0;
    if(num < 0)
    {
        num *= -1;
        temp = num;
        length++;
        set = 1;
    }
    while ( (num /= 10) != 0)
    {
        length++;
    }

    array[ length + 1 ] = '\0';
    while (length >= 0)
    {
        array[length] = (temp % 10) + '0';
        temp /= 10;
        length--;
    }
    if (set == 1)
    {
        array[0] = '-';
        set = 0;
    }
    return length;
}
/********************************************************END OF CODE********************************************************************/
