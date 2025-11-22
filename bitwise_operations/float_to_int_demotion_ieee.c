/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 10/11/2021.
*   Description     : A Program to demote the type of given float number to integer using bitwise operators and bitfields.
*   Input           : ./a.out 
*   Output          :   	TYPE DEMOTION FROM FLOAT TO INTEGER
*                       Enter any float numer : -0.76
*                       Demoted Value is :0.000000
*                       Do you want to continue (y/Y):y
*
*                       Enter any float numer : -1.5467
*                       Demoted Value is :-1.000000
*                       Do you want to continue (y/Y):y
*
*                       Enter any float numer : 23.789
*                       Demoted Value is :23.000000
*                       Do you want to continue (y/Y):y
*
*                       Enter any float numer : -16.78
*                       Demoted Value is :-16.000000
*                       Do you want to continue (y/Y):y
*
*                       Enter any float numer : 0.76
*                       Demoted Value is :0.000000
*                       Do you want to continue (y/Y):y      
*
*                       Enter any float numer : 1.321
*                       Demoted Value is :1.000000
*                       Do you want to continue (y/Y):n
*
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>                                                  //header file.

int main()
{
    char character;                                                 //input variables declaration.
    float fl_num,int_part;
    signed int bit_num,mask,iter,masked_mantissa;
    printf("\tTYPE DEMOTION FROM FLOAT TO INTEGER");
    
    do                                                              //loop to continue the process.
    {
        printf("\nEnter any float numer : ");                       //float number fetch.
        scanf("%f",&fl_num);

        union myfloat                                               //UDT to define the bitfields for float number.
        {
            float float_num;
            struct
            {
                unsigned  mantissa      :23;
                unsigned  exponent      :8;
                unsigned  sign          :1;
            }bits;                                                  //structure named bits to split the float bits as per IEE format.
        }fl = {fl_num};                                             //passing float value to the union.

        bit_num = fl.bits.exponent - 127;                           //no of bits to be extracted from mantissa.
        
        if(bit_num >= 0)
        {
            mask = ((1 << bit_num) - 1) << (22 - (bit_num - 1));    //creating mask bits for req. no.of bits to be extracted from Mantissa
            masked_mantissa = (mask & fl.bits.mantissa) >> (22 - (bit_num - 1));
            mask = (1 << bit_num);
            int_part = mask | masked_mantissa;          //combining masked mantissa with MSB 1.
        }
        else
        {
            int_part = 0;
        }
        if(fl.bits.sign == 1 && int_part != 0)          //condition to detect negative numbers.
        {
            int_part = int_part * (-1);
        }
        printf("Demoted Value is :%#f",int_part);//check for sign.using fl.bits.sign

        printf("\nDo you want to continue (y/Y):");     //input fetch for next cycle.
        scanf(" %c",&character);
    }while( character == 'y' || character == 'Y' );     //condition for next cycle.
}
/********************************************************END OF CODE********************************************************************/
