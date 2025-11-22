/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 08/10/2021. 
*   Description     : A Program to check processor endianess.
*   Input           : ./a.out 
*   Output          :              ENDIANESS OF THE PROCESSOR
*                       Enter any number : -1
*                       Entered Number is 	            			:0xffffffff
*                       Data stored in Lowest Memory Address 		:0xff
*                       Least Significant Bit in given number 		:0xff
*                       Little Endian System
*                       Do you want to continue (y/Y):y
*
*                       Enter any number : 123456
*                       Entered Number is            				:0x123456
*                       Data stored in Lowest Memory Address 		:0x56
*                       Least Significant Bit in given number 		:0x56
*                       Little Endian System
*                       Do you want to continue (y/Y):n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int endianess(char *, unsigned int);                    //endianess function definition.

int main()
{
    unsigned int num,lsb;                               //input and output variable declaration.
    int ret;
    char *num_address,character;                        //pointer variable to store address of number.
    
    printf("\tENDIANESS OF THE PROCESSOR");
    
    do                                                  //loop to continue the next iteration.
    {
        printf("\nEnter any number : ");                //input fetch.
        scanf("%x",&num);
        printf("Entered Number is \t\t\t\t:%#x",num);
        lsb = num % 256;                                //finding the lower byte by performing modulo operation by 0xFF(0...255).
        
        num_address = (char *)&num;                   //storing the least significant memory address in the num_address pointer variable.
        ret = endianess(num_address,lsb);             //endianess function call.
    
        if ( ret == 1 )
            printf("\nLittle Endian System");
        else
            printf("\nBig Endian System");
        
        printf("\nDo you want to continue (y/Y):");     //input fetch for next cycle.
        scanf(" %c",&character);

    }while ( character == 'Y' || character == 'y' );    //condition for next cycle execution.

return 0;
}

int endianess(char *address,unsigned int lsb)                   //endianess function definition.
{
    unsigned char *base_address;                                //assigning the base address to the pointer variable base_address,
    base_address = (unsigned char *)address;
    printf("\nData stored in Lowest Memory Address \t\t:%#x",*base_address);
    printf("\nLeast Significant Bit in given number \t\t:%#x",lsb);
    if (*base_address == lsb)                                   //condition to detect Little or Big endian processor.
        return 1;
    else
        return 0;
}

/********************************************************END OF CODE********************************************************************/

