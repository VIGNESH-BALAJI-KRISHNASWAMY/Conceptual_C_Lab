/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 10/10/2021. 
*   Description     : Implement getword, atoi, itoa functions
*   Input           : ./a.out 
*   Output          :          	IMPLEMENTING GETWORD, ATOI, ITOA, FUNCTIONS 
*                       1. getword
*                       2. atoi
*                       3. itoa
*                       Enter your choice : 1
*                       	IMPLEMENTING GETWORD FUNCTION
*                       Enter a word :emertxe embedded course
*                       You entered 'emertxe' and the length is '7' 
*
*                       Do you want to continue (y/Y): y
*
*                       1. getword
*                       2. atoi
*                       3. itoa
*                       Enter your choice : 2
*                       	IMPLEMENTING ATOI FUNCTION
*                       Enter a Numeric String :-012aqw
*                       String to Integer is '-12' 
*
*                       Do you want to continue (y/Y): y
*
*                       1. getword
*                       2. atoi
*                       3. itoa
*                       Enter your choice : 3
*                       	IMPLEMENTING ITOA FUNCTION
*                       Enter a Number :1236tvwdcb
*                       Integer to String is '1236' 
*
*                       Do you want to continue (y/Y): y
*
*                       1. getword
*                       2. atoi
*                       3. itoa
*                       Enter your choice : 3     
*                       	IMPLEMENTING ITOA FUNCTION
*                       Enter a Number :fkvnkwfmw
*                       Integer to String is '0' 
*
*                       Do you want to continue (y/Y): n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
#include <stdio_ext.h>

int getword(char *);        //function declarations.
int atoi(const char *);
int itoa(int,char*);

int main()
{
    int choice,ret,number;                  //input,output variables and pointer variable declaration.
    char *str;
    char word[50],string[100],character;
    printf("\tIMPLEMENTING GETWORD, ATOI, ITOA, FUNCTIONS ");

    do                                      //loop to continue the process.
    {
        printf("\n1. getword\n2. atoi\n3. itoa\nEnter your choice : ");
        scanf("%d",&choice);
        
        switch (choice)                     //switch case to select the appropriate function.
        {
            case 1:
                printf("\tIMPLEMENTING GETWORD FUNCTION");
                printf("\nEnter a word :");
                scanf(" %[^\n]",word);
                ret = getword(word);        //function call to getword function.
                printf("You entered '%.*s' and the length is '%d' \n",ret,word,ret);
                break;

            case 2:
                printf("\tIMPLEMENTING ATOI FUNCTION");
                printf("\nEnter a Numeric String :");
                scanf(" %[^\n]",string);
                number = atoi(string);     //function call to atoi function.
                printf("String to Integer is '%d' \n",number);
                break;

            case 3:
                printf("\tIMPLEMENTING ITOA FUNCTION");
                printf("\nEnter a Number :");
                int integer = scanf("%d",&number);
                ret = itoa(number,string);  //function call to itoa function.

                if ( integer == 0  )        //condition to erase previous string if current condition is not called due to error input.
                {
                    while( ret-- != 0 )
                    {
                        *(string + (char)ret) = '\0';
                    }
                    *string = '0';
                }
                printf("Integer to String is '%.*s' \n",ret,string);
                break;
            
           default:
                printf("\nINFO:Invalid Choice!");
                __fpurge(stdin);            //to prevent the overflowed characters intrutuion into next variables.
        }

        printf("\nDo you want to continue (y/Y): ");    //input fetch for next cycle.
        __fpurge(stdin);
        scanf(" %c",&character);
    }while( character == 'Y' || character == 'y' );     //condition for execution of next cycle.

return 0;
}

int getword(char *word)
{
    int count = 0;
    while(*word != '\0')
    {
        if ( *word == ' ')                  //condition to detect the characters in a first word.
            break;
        count++;
        word++;                             //incrementing the address of variable word.
    }
    return count;                           //returning the length of the first word.
}

int atoi(const char *string)                        //atoi function definition.
{
    int neg_flag = 0,sum = 0;
    if ( *string == '-' )                           //condition to detect negative number.
    {
        neg_flag--;
        *string++;
    }
    else if ( *string == '+')                       //condition to detect positive sign.
    {
        neg_flag = 0;
        *string++;
    }
    while(*string)                                  //condition to detect numbers
    {
        if( *string >= '0' && *string <= '9' )
        {
            sum = (sum * 10) + (*string - '0');
            *string++;
        }
        else
            break;
    }
    return neg_flag?sum * neg_flag:sum;             //returning positive or negative number.
}


int itoa(int num,char *array)                       //function definition for itoa function.
{

    int length = 0,temp = num,set = 0,count;        
    if(num < 0)                                     //condition to detect negative number.
    {
        num *= -1;
        temp = num;
        length++;
        set = 1;
    }
    while ( (num /= 10) != 0)                       //loop to find the number of digits in given number.
    {
        length++;
    }
    count = length + 1;                             
    array[ length + 1 ] = '\0';                    //making last literal in a string as null.
    while (length >= 0)
    {
        array[length] = (temp % 10) + '0';         //converting interger to string and storing in a array.
        temp /= 10;
        length--;
    }
    if (set == 1)                                  //condition to display initial - sign if num is negative. 
    {
        array[0] = '-';
        set = 0;
    }
    return count;                                  //returning length of number to main to erase the current string in future if needed.
}
/********************************************************END OF CODE********************************************************************/
