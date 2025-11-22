/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 13/09/2021 
*   Description     : A Program to implement a own c-type library.
*   Input           : ./a.out 
*   Output                   	IMPLEMENTING OWN C-TYPE LIBRARY 
*                    Enter a character :a
*                    1-isalnum
*                    2-isalpha
*                    3-isascii
*                    4-isxdigit
*                    Enter your choice : 1
*                    The Character 'a' is an Alpha Numeric Character
*                    Do you want to continue: y
*
*                    Enter a character :A
*                    1-isalnum
*                    2-isalpha
*                    3-isascii
*                    4-isxdigit
*                    Enter your choice : 4
*                    The Character 'A' is a Hexa Decimal Character
*                    Do you want to continue: y
*
*                    Enter a character :0
*                    1-isalnum
*                    2-isalpha
*                    3-isascii
*                    4-isxdigit
*                    Enter your choice : 1
*                    The Character '0' is an Alpha Numeric Character
*                    Do you want to continue: y
*
*                    Enter a character :.
*                    1-isalnum
*                    2-isalpha
*                    3-isascii
*                    4-isxdigit
*                    Enter your choice : 3
*                    The Character '.' is a ASCII Character
*                    Do you want to continue: n                   
* 
*                                                          
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
#include <ctype.h>

int is_alnum(int);          //function declaration
int is_alpha(int);
int is_ascii(int);
int is_xdigit(int);

int main()
{
    char check,character;   //declaration of input variables.
    int num;
    
    printf("\tIMPLEMENTING OWN C-TYPE LIBRARY ");
    
    do                      //loop to perform continuous operation.
    {
        printf("\nEnter a character :");        //input data fetch as char type.
        scanf(" %c",&character);
        printf("1-isalnum\n2-isalpha\n3-isascii\n4-isxdigit\nEnter your choice : ");//selecting any 1 operation to perform on the input.
        scanf("%d",&num);

        switch (num)        //switch case to run respective function.
        {
            case 1:
                    is_alnum(character)?printf("The Character '%c' is an Alpha Numeric Character",character):printf("The Character '%c' is  not an Alpha Numeric Character",character); //function call to check input is a alphanumeric character.
                break;
                
            case 2:
                    is_alpha(character)?printf("The Character '%c' is an Alphabet.",character):printf("The Character '%c' is not an Alphabet.",character); //function call to check input is a alphabet.
                break;
            case 3:
                    is_ascii(character)?printf("The Character '%c' is a ASCII Character",character):printf("The Character '%c' is a not a ASCII Character",character); //function call to check input is a ASCII character.
                break;
            case 4:
                    is_xdigit(character)?printf("The Character '%c' is a Hexa Decimal Character",character):printf("The Character '%c' is  not a Hexa Decimal Character",character); //function call to check input is a hexadecimal digit.
                break;
        }


        printf("\nDo you want to continue: ");      //input fetch for next cycle.
        scanf(" %c",&check);

    }while ( check == 'y' || check == 'Y' );        //condition to execute next cycle.

return 0;
}

int is_alnum( int character )           //called function for alphanumeric case with formal argument of int type.
{   
    return isalnum(character);          //return 1 if character is alphanumeric character else return 0.
}

int is_alpha( int character )           //called function for alphabet case with formal argument of int type.
{   
    return isalpha(character);          //return 1 if character is alphabet character else return 0.
}

int is_ascii( int character )           //called function for ASCII case with formal argument of int type.
{   
    return isascii(character);          //return 1 if character is ASCII character else return 0.
}

int is_xdigit( int character )          //called function for hexadecimal case with formal argument of int type.
{   
    return isxdigit(character);         //return 1 if character is hexadecimal character else return 0.
}
/********************************************************END OF CODE********************************************************************/
