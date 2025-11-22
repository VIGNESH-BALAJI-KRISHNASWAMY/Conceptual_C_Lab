/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 01/11/2021.
*   Description     : A program to define a macro swap (t, x, y) that interchanges two arguments of type t.
*   Input           : ./a.out 
*   Output          :   	MACRO TO SWAP TWO ARGUMENTS 
*                       1. Int
*                       2. char
*                       3. short
*                       4. float
*                       5. double
*                       6. string
*                       Enter your choice :1
*
*                       Enter the num1  :21
*
*                       Enter the num2  :34
*
*                       After Swapping :
*                       num1 : 34
*                       num2 : 21
*                       Do you want to continue(y/Y):y
*
*                       1. Int
*                       2. char
*                       3. short
*                       4. float
*                       5. double
*                       6. string
*                       Enter your choice :2
*
*                       Enter the char1  :v
*
*                       Enter the char2  :b
*
*                       After Swapping :
*                       char1 : b
*                       char2 : v
*                       Do you want to continue(y/Y):y
*
*                       1. Int
*                       2. char
*                       3. short
*                       4. float
*                       5. double
*                       6. string
*                       Enter your choice :3
*
*                       Enter the shortnum1  :123
*
*                       Enter the shortnum2  :321
*
*                       After Swapping :
*                       num1 : 321
*                       num2 : 123
*                       Do you want to continue(y/Y):y
*
*                       1. Int
*                       2. char
*                       3. short
*                       4. float
*                       5. double
*                       6. string
*                       Enter your choice :4
*
*                       Enter the float_num1  :12.23
*
*                       Enter the float_num2  :3.21
*
*                       After Swapping :
*                       num1 : 3.21
*                       num2 : 12.23
*                       Do you want to continue(y/Y):y
*
*                       1. Int
*                       2. char
*                       3. short
*                       4. float
*                       5. double
*                       6. string
*                       Enter your choice :5
*
*                       Enter the double_num1  :2.3456
*
*                       Enter the double_num2  :4.543112
*
*                       After Swapping :
*                       num1 : 4.54311
*                       num2 : 2.3456
*                       Do you want to continue(y/Y):y
*
*                       1. Int
*                       2. char
*                       3. short
*                       4. float
*                       5. double
*                       6. string
*                       Enter your choice :6
*
*                       Enter the string1  :Emertxe
*
*                       Enter the string2  :Bangalore
*
*                       After Swapping :
*                       string1 : Bangalore
*                       string2 : Emertxe
*                       Do you want to continue(y/Y):n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

#define SWAP(type,x,y)  {type temp; temp = x; x = y; y = temp;}        //macro definition for SWAP.

int main()
{
    int choice,count = 0;                                              //input variables declaration and definition.
    int num1,num2;
    short int snum1,snum2;
    char char1,char2,*str1,*str2,arr1[100],arr2[100];
    float f_num1,f_num2;
    double d_num1,d_num2;
    char character;

    printf("\tMACRO TO SWAP TWO ARGUMENTS ");
    do                                                                 //loop to continue the process.
    {
        printf("\n1. Int\n2. char\n3. short\n4. float\n5. double\n6. string\nEnter your choice :");
        scanf("%d",&choice);

        switch(choice)                                                  //switch case to select which type to swap.
        {
            case 1:                                                     //case 1 for integer swap.
                printf("\nEnter the num1  :");
                scanf("%d",&num1);
                printf("\nEnter the num2  :");
                scanf("%d",&num2);
                SWAP(int,num1,num2);                                    //macro call.
                printf("\nAfter Swapping :\nnum1 : %d\nnum2 : %d",num1,num2);
                break;
           case 2:
                printf("\nEnter the char1  :");                         //case 2 for characters.
                scanf(" %c",&char1);
                printf("\nEnter the char2  :");
                scanf(" %c",&char2);
                SWAP(char,char1,char2);                                 //macro call for swap.
                printf("\nAfter Swapping :\nchar1 : %c\nchar2 : %c",char1,char2);
                break;
            case 3:
                printf("\nEnter the shortnum1  :");                     // case 3 for short datatype.
                scanf("%hd",&snum1);
                printf("\nEnter the shortnum2  :");
                scanf("%hd",&snum2);
                SWAP(short int,snum1,snum2);
                printf("\nAfter Swapping :\nnum1 : %hd\nnum2 : %hd",snum1,snum2);
                break;
            case 4:
                printf("\nEnter the float_num1  :");                    //case 4 for float datatpe.
                scanf("%f",&f_num1);
                printf("\nEnter the float_num2  :");
                scanf("%f",&f_num2);
                SWAP(float,f_num1,f_num2);                              //macro call.
                printf("\nAfter Swapping :\nnum1 : %lg\nnum2 : %lg",f_num1,f_num2);
                break;
            case 5:
                printf("\nEnter the double_num1  :");                   //case 5 for double datatype.
                scanf("%le",&d_num1);
                printf("\nEnter the double_num2  :");
                scanf("%le",&d_num2);
                SWAP(double,d_num1,d_num2);
                printf("\nAfter Swapping :\nnum1 : %lg\nnum2 : %lg",d_num1,d_num2);
                break;
            case 6:
                printf("\nEnter the string1  :");                       //case 6 for string datatype.
                scanf(" %[^\n]",arr1);
                printf("\nEnter the string2  :");
                scanf(" %[^\n]",arr2);
                str1 = arr1;str2 = arr2;
                while(*str1 != '\0' || *str2 != '\0')                   //loop to check for the presence of null in the string.
                {
                    SWAP(char,*str1,*str2);                             //macro call for each string literal.
                        str1++;                                         //moving to next string position.
                        str2++;
                        count++;
                }
                str1 -= (char)count; str2 -= (char)count;               //bringing back the pointer to original position.
                printf("\nAfter Swapping :\nstring1 : %s\nstring2 : %s",arr1,arr2);
                count = 0;
                break;
        }

        printf("\nDo you want to continue(y/Y):");                      //input fetch for next cycle.
        scanf(" %c",&character);
    }while(character == 'y' || character == 'Y');                       //condition for next cycle execution.
}
/********************************************************END OF CODE********************************************************************/

