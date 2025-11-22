/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 01/09/2021 
*   Description     : A Program to Print sizes of all basic data types of C
*   Input           : ./a.out 
*   Output          :    SIZE OF BASIC DATATYPES OF C
*                        PROGRAM RUNNING IN 64-bit SYSTEM
*                     size of VOID                              : 1 byte
*                     size of SIGNED CHAR                       : 1 byte
*                     size of UNSIGNED CHAR                     : 1 byte
*                     size of SIGNED SHORT                      : 2 bytes
*                     size of UNSIGNED SHORT                    : 2 bytes
*                     size of SIGNED SHORT(default int)         : 2 bytes
*                     size of UNSIGNED SHORT(default int)       : 2 bytes
*                     size of SIGNED INT                        : 4 bytes
*                     size of UNSIGNED INT                      : 4 bytes
*                     size of SIGNED LONG INT                   : 8 bytes
*                     size of UNSIGNED LONG INT                 : 8 bytes
*                     size of SIGNED LONG(default int)          : 8 bytes
*                     size of UNSIGNED LONG(default int)        : 8 bytes
*                     size of SIGNED LONG LONG(default int)     : 8 bytes
*                     size of UNSIGNED LONG LONG(default int)   : 8 bytes
*                     size of FLOAT                             : 4 bytes
*                     size of DOUBLE                            : 8 bytes
*                     size of LONG DOUBLE                       : 16 bytes                                         
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    printf("\tSIZE OF BASIC DATATYPES OF C");
    if ( sizeof(long int) == 4 )                                
        printf("\n\tPROGRAM RUNNING IN 32-bit SYSTEM");         //just for displaying current working system is 32/64 bit.
    else
        printf("\n\tPROGRAM RUNNING IN 64-bit SYSTEM");

    printf("\nsize of VOID                              : %zu byte",sizeof(void));
    printf("\nsize of SIGNED CHAR                       : %zu byte",sizeof(signed char));
    printf("\nsize of UNSIGNED CHAR                     : %zu byte",sizeof(unsigned char));
    printf("\nsize of SIGNED SHORT                      : %zu bytes",sizeof(signed short));
    printf("\nsize of UNSIGNED SHORT                    : %zu bytes",sizeof(unsigned short));
    printf("\nsize of SIGNED SHORT(default int)         : %zu bytes",sizeof(signed short int));
    printf("\nsize of UNSIGNED SHORT(default int)       : %zu bytes",sizeof(unsigned short int));
    printf("\nsize of SIGNED INT                        : %zu bytes",sizeof(signed int));
    printf("\nsize of UNSIGNED INT                      : %zu bytes",sizeof(unsigned int));
    printf("\nsize of SIGNED LONG INT                   : %zu bytes",sizeof(signed long int));
    printf("\nsize of UNSIGNED LONG INT                 : %zu bytes",sizeof(unsigned long int ));
    printf("\nsize of SIGNED LONG(default int)          : %zu bytes",sizeof(signed long));
    printf("\nsize of UNSIGNED LONG(default int)        : %zu bytes",sizeof(unsigned long));
    printf("\nsize of SIGNED LONG LONG(default int)     : %zu bytes",sizeof(signed long long));
    printf("\nsize of UNSIGNED LONG LONG(default int)   : %zu bytes",sizeof(unsigned long long ));
    printf("\nsize of FLOAT                             : %zu bytes",sizeof(float));
    printf("\nsize of DOUBLE                            : %zu bytes",sizeof(double));
    printf("\nsize of LONG DOUBLE                       : %zu bytes",sizeof(long double));
    
    
    printf("\n");
    
    return 0;
}
/********************************************************END OF CODE********************************************************************/
