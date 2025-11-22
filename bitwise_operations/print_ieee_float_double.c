/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 24/10/2021.
*   Description     : Print bits of float & double
*   Input           : ./a.out 
*	Output          :    PRINT BITS OF FLOAT AND DOUBLE IN IEEE FORMAT
*                       Enter your choice: 
*                       1.float
*                       2.double
*                       Choice: 1
*                       Enter a float value : 2.3
*
*                       Sign	Exponent	    Mantissa
*                       _______________________________________________
*
*                       0   	10000000	    00100110011001100110011
*                       Do you want to continue(y/Y): y
*
*                       Enter your choice: 
*                       1.float
*                       2.double
*                       Choice: 2
*                       Enter a double value : -2.3
*
*                       Sign	Exponent	    Mantissa
*                       ____________________________________________________________________________
*
*                       1	    10000000000	    0010011001100110011001100110011001100110011001100110
*                       Do you want to continue(y/Y): n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
#include <stdio_ext.h>

int *ieee_bits(void *,int,int);                                         //ieee_format and binary form function declarations.
void binary(int,int,int);

int main()
{
    printf("\t PRINT BITS OF FLOAT AND DOUBLE IN IEEE FORMAT");
    char character;                                                     //input variable declarations.
    int choice;
    float flt_num;
    double dou_num;
    do                                                                  //loop to continue the process.
    {
        printf("\nEnter your choice: \n1.float\n2.double\nChoice: ");   //input fetch.
        scanf("%d",&choice);

        switch(choice)                                                  //switch case to select the format.(float/double)
        {
            case 1:
                {
                    int num = 46;                                       //for display purpose.
                    printf("Enter a float value : ");
                    scanf("%f",&flt_num);
                    printf("\nSign\tExponent\tMantissa\n");
                    while(num-- >= 0)
                        printf("_");
                    printf("\n\n");
                    ieee_bits(&flt_num,sizeof(float),choice);           //function call to find the IEEE format for given float number.
                }
                break;
            case 2:
                {
                    int num = 75;                                       //for display purpose.
                    printf("Enter a double value : ");
                    scanf("%lf",&dou_num);
                    printf("\nSign\tExponent\tMantissa\n");
                    while(num-- >= 0)
                        printf("_");
                    printf("\n\n");
                    ieee_bits(&dou_num,sizeof(double),choice);          //function call to find the IEEE format for given double number.
                }
                break;
            default:
                printf("ERROR!Enter a valid choice");                   //choice validation.
        }
        printf("\nDo you want to continue(y/Y): ");                     //input for next cycle continution.
        __fpurge(stdin);
        scanf(" %c",&character);
    }while(character == 'y' || character == 'Y');                       //condition for next continution.

return 0;
}

int *ieee_bits(void *ptr,int size,int choice)                           //IEEE bits function definition.
{
    int num,count = 0;                                                  //process variables declaration and definition. 
    static char *base_add;
    base_add = (char *)ptr;                            //storing base address of void pointer in a static variable for future reference.
    while(--size >= 0)                      //loop to traverse each byte in float[4 byte]/double[8 byte]. 
    {
       num = *(char *)(ptr + (char)size);   //NOTE : traversing the bits in a byte from last due to the Little Endianess of the system...
                                                //...if system is Big Endian then traverse from SIZE = 0 to 7.
       binary(num,count,choice);            //function call to print the binary form of above found each bytes of float/double.       
       count++;                             //count variable for finding the sign bit in float and double.
       ptr = base_add;                      //reinitializing the base address for next cycle.
    }
}

void binary(int num,int count,int choice)                   //binary function definition.
{
    char iter = 0;
    for ( iter = 7; iter >= 0; iter-- )                     //loop to print the 8 bits in each byte of float/double variable.
    {
        if ( ((num >> iter) & 1) == 1 )                     //condition to detect the 1's in the given 1 byte of a number(float/double)
        {
            printf("1");                                    //printing 1
            if(count == 0 && iter == 7)                     //sign bit separation
             printf("\t");
            else if(count == 1 && iter == 7 && choice == 1) //Mantissa bits separation for float data type.
             printf("\t");
            else if(count == 1 && iter == 4 && choice == 2) //Mantissa bits separation for double data type.
             printf("\t");
        }
        else
        {
            printf("0");                                    //printing 0
            if(count == 0 && iter == 7)                     //sign bit separation
             printf("\t");
            else if(count == 1 && iter == 7 && choice == 1) //Mantissa bits separation for float data type.
             printf("\t");
            else if(count == 1 && iter == 4 && choice == 2) //Mantissa bits separation for double data type.
             printf("\t");
        }
    }
}
/********************************************************END OF CODE********************************************************************/

