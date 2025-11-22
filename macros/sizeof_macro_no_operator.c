/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 
*   Description     : A program to define a macro SIZEOF(x), where x is a variable, without using sizeof operator
*   Input           : ./a.out 
*   Output          :   	SIZE OF DATATYPES USING MACRO
*                       Size of char                    	:1 byte
*                       Size of unsigned short          	:2 bytes
*                       Size of signed short            	:2 bytes
*                       Size of unsigned int            	:4 bytes
*                       Size of signed int              	:4 bytes
*                       Size of short int               	:2 bytes
*                       Size of long int                	:8 bytes
*                       Size of int                     	:4 bytes
*                       Size of float                   	:4 bytes
*                       Size of double                  	:8 bytes
*                       Size of unsigned long int       	:8 bytes
*                       Size of signed long int         	:8 bytes
*                       Size of unsigned long long      	:8 bytes
*                       Size of signed long long        	:8 bytes
*                       Size of long double             	:16 bytes
*
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

#define address(a,b)        ((char*)(&b + (char)1) - (char *)(&a))          //macro to replace the sizeof operator.
int main()
{
    char num;                                                               //input variable declaration.
    int num1;
    float num2;
    double num3;
    long int num4;
    long double num5;
    short int num6;
    unsigned short num7;
    signed short num8;
    unsigned long int num9;
    signed long int num10;
    unsigned long long num11;
    signed long long num14;
    unsigned int num12;
    signed int num13;

    printf("\tSIZE OF DATATYPES USING MACRO\n");
    printf("Size of char                    \t:%ld byte\n",address(num,num));          //macro call in the print statement.
    printf("Size of unsigned short          \t:%ld bytes\n",address(num7,num7));
    printf("Size of signed short            \t:%ld bytes\n",address(num8,num8));
    printf("Size of unsigned int            \t:%ld bytes\n",address(num12,num12));
    printf("Size of signed int              \t:%ld bytes\n",address(num13,num13));
    printf("Size of short int               \t:%ld bytes\n",address(num6,num6));
    printf("Size of long int                \t:%ld bytes\n",address(num4,num4));
    printf("Size of int                     \t:%ld bytes\n",address(num1,num1));
    printf("Size of float                   \t:%ld bytes\n",address(num2,num2));
    printf("Size of double                  \t:%ld bytes\n",address(num3,num3));
    printf("Size of unsigned long int       \t:%ld bytes\n",address(num9,num9));
    printf("Size of signed long int         \t:%ld bytes\n",address(num10,num10));
    printf("Size of unsigned long long      \t:%ld bytes\n",address(num11,num11));
    printf("Size of signed long long        \t:%ld bytes\n",address(num14,num14));
    printf("Size of long double             \t:%ld bytes\n",address(num5,num5));

    return 0;
}
/********************************************************END OF CODE********************************************************************/
