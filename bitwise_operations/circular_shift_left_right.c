/*******************************************************DOCUMENTATION*********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 15/09/2021 
*   Description     : A program to perform circular right and left shift of given positive and negative number.
*   Input           : ./a.out 
*	Output          :       CIRCULAR RIGHT AND LEFT SHIFT OF GIVEN +ve or -ve NUMBER
*
*                       Enter a number : 12
*                       Enter the number of shifts : 3
*                       1.Circular right shift
*                       2.Circular left shift
*                       Select the operation to perform: 1
*                       Before Circular Right shift by '3' bit(s): 00000000000000000000000000001100
*                       After Circular Right shift by '3' bit(s) : 10000000000000000000000000000001
*                       Do you want to continue(y/Y) : y
*
*                       Enter a number : -12
*                       Enter the number of shifts : 3
*                       1.Circular right shift
*                       2.Circular left shift
*                       Select the operation to perform: 1
*                       Before Circular Right shift by '3' bit(s): 11111111111111111111111111110100
*                       After Circular Right shift by '3' bit(s) : 10011111111111111111111111111110
*                       Do you want to continue(y/Y) : y
*
*                       Enter a number : 12
*                       Enter the number of shifts : 3
*                       1.Circular right shift
*                       2.Circular left shift
*                       Select the operation to perform: 2
*                       Before Circular Left shift by '3' bit(s): 00000000000000000000000000001100
*                       After Circular Left shift by '3' bit(s) : 00000000000000000000000001100000
*                       Do you want to continue(y/Y) : y
*
*                       Enter a number : -12
*                       Enter the number of shifts : 3
*                       1.Circular right shift
*                       2.Circular left shift
*                       Select the operation to perform: 2
*                       Before Circular Left shift by '3' bit(s): 11111111111111111111111111110100
*                       After Circular Left shift by '3' bit(s) : 11111111111111111111111110100111
*                       Do you want to continue(y/Y) : n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

void circular_right(unsigned int,int);                   //function declared to perform circular right shift.
void circular_left(signed int,int);                      //function declared to perform circular left shift.
void disp_binary_format(int);                           //function declared to display binary format of a given number.

int main()
{
    printf("\tCIRCULAR RIGHT AND LEFT SHIFT OF GIVEN +ve or -ve NUMBER\n");
    
    int num,shift,choice;                               //input variables declaraction. 
    char character;

    do                                                  //loop to continue next cycle.
    {
        printf("\nEnter a number : ");                  //input fetch for number,type of shift and number of shifts.
        scanf("%d",&num);
        printf("Enter the number of shifts : ");
        scanf("%d",&shift);
        printf("1.Circular right shift\n2.Circular left shift\nSelect the operation to perform: ");
        scanf("%d",&choice);

        switch (choice)                                 //switch case to select the type of shift.
        {
            case 1:
                printf("Before Circular Right shift by '%d' bit(s): ",shift);
                disp_binary_format(num);                //function call to display binary form of number 'num'passed as actual argument.
                printf("\nAfter Circular Right shift by '%d' bit(s) : ",shift);
                circular_right(num,shift);            //function call to perform circular right shift with two actual arg's num and shift.
               break;
            
            case 2:
                printf("Before Circular Left shift by '%d' bit(s): ",shift);
                disp_binary_format(num);
                printf("\nAfter Circular Left shift by '%d' bit(s) : ",shift);
                circular_left(num,shift);
               break;
        }

        printf("\nDo you want to continue(y/Y) : ");    // input fetch for next cycle.
        scanf(" %c",&character);

    }while(character == 'y' || character == 'Y');       //condition to perform next cycle.

return 0;
}

void circular_right(unsigned int num,int shift)
{
    int mask,get_mask,shift_mask,modified_num,output;

    mask = (1 << shift) - 1;                            //mask is created to get the req bits from LSB which is to be moved to MSB.
    get_mask = mask & num;                              //getting the LSB bits.
    shift_mask = get_mask << (31 - shift + 1);          //shifting the LSB bits to the reguired position from LSB.
    modified_num = num >> shift;                        //num should be unsigned so that right shifting it doesnot cause consecutive 1's.
    output = shift_mask | modified_num;                 //performing or operation of above 2 steps to get required cir.riht.shifted o/p.
    
    disp_binary_format(output);                         //calling display function to display the output.
}

void circular_left(signed int num,int shift)
{
    int mask,shift_mask,modified_num,output;      //local variable delration.
    unsigned get_mask;                            //get_mask is made unsigned so that right shifting it does'nt produce concecutive 1's 
    
    mask = ~((1 << 31 - shift + 1) - 1);            //mask is created to get the req bits from MSB which is to be moved to LSB.
    get_mask = (mask & num);                        //getting the MSB bits.
    shift_mask = get_mask >> (31 - shift + 1);      //shifting the MSB bits to the reguired position from LSB.
    modified_num = num << shift;                    //num can be signed as left shifting has no effect on consecutive 1's.
    output = shift_mask | modified_num;             //performing or operation of above 2 steps to get required cir.left.shifted o/p.

    disp_binary_format(output);
}

void disp_binary_format(int num)                //defining the display binary format function.
{
    int iter,op_bit,shift,mask;                 //declaring the local variables
 
    for( iter = 31; iter >= 0; iter-- )         //loop to display the 32 bit format of the integer.
    {
      op_bit = (num >> iter) & 1;
      (op_bit > 0)?printf("1"):printf("0");     //condition to detect 0's and 1's
    }
}
/********************************************************END OF CODE********************************************************************/
