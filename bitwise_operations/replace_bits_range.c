/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 09/09/2021
*   Description     : A program to read int val, read 0 ≤ a ≤ b ≤ 31. read an int new n, put the (b-a+1) lsb’s of n into i[b:a] position.
*   Input           : ./a.out 
*   Output          :      	REPLACING NUMBER OF BITS IN DESIRED POSITION
*                    Enter the number from which replacing bits should be acquired : 120
*                    Enter the number in which bits to be replaced : 32
*                    Enter the minimum position of bit to be replaced: 3
*                    Enter the maximum position of bit to be replaced: 7
*                    Replace bits obtained from num 120  : 00000000000000000000000001111000
*                    Number to be Replaced 32 : 00000000000000000000000000100000
*                    New Replaced value is 192  : 00000000000000000000000011000000
*                    Do you want to continue (y/Y):y
*
*                    Enter the number from which replacing bits should be acquired : 121
*                    Enter the number in which bits to be replaced : 3
*                    Enter the minimum position of bit to be replaced: 2
*                    Enter the maximum position of bit to be replaced: 3
*                    Replace bits obtained from num 121  : 00000000000000000000000001111001
*                    Number to be Replaced 3 : 00000000000000000000000000000011
*                    New Replaced value is 7  : 00000000000000000000000000000111
*                    Do you want to continue (y/Y):n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int num,new_num,min_bit_pos,max_bit_pos,no_of_bits;     //declaration of input and output variables.
    int iter,output,mask,set,set_mask,clear_mask,shift;     
    char character;
    printf("\tREPLACING NUMBER OF BITS IN DESIRED POSITION");
    
    do                                                                                  //loop to continue the operation
    {
        printf("\nEnter the number from which replacing bits should be acquired : ");   //input fetch.
        scanf("%d",&num);
        printf("Enter the number in which bits to be replaced : ");
        scanf("%d",&new_num);
        printf("Enter the minimum position of bit to be replaced: ");
        scanf("%d",&min_bit_pos);
        printf("Enter the maximum position of bit to be replaced: ");
        scanf("%d",&max_bit_pos);

        if ( min_bit_pos < 0 || min_bit_pos > 31 || min_bit_pos > max_bit_pos )  //condition to avoid error in min and max bit positions.
            printf("Provide correct minimum position of bit  0 <= min_bit_pos <= max_bit_pos <= 31 ");

        else if ( max_bit_pos < 0 || max_bit_pos > 31 || max_bit_pos < min_bit_pos )
            printf("Provide correct maximum position of bit 0 <= min_bit_pos <= max_bit_pos <= 31 ");
        
        else if ( max_bit_pos >= min_bit_pos )
        {
            no_of_bits = max_bit_pos - min_bit_pos + 1;         //calculating the num of bits from given min and max bit positions.
            shift = max_bit_pos - no_of_bits + 1;               //finding the number of shifts to be performed.
            mask = (1 << no_of_bits) - 1;                       //finding the set mask.
            set_mask = mask & num;                              //masking the required bits from the given number.
            set = set_mask << shift;                            //shifting the masked bits to its required position.

            clear_mask = ~(mask << shift) & new_num;            //clearing the desired bits from the old number.
            output = clear_mask | set;                          //replacing the desired bits in old position.
            
            printf("Replace bits obtained from num %d  : ",num);
            for ( iter = 31; iter >= 0; iter-- )                    //loop to print the given number in binary form.
            {
                if ( ((num >> iter) & 1) == 1 )
                    printf("1");
                else
                    printf("0");
            }

            printf("\nNumber to be Replaced %d : ",new_num);
            for ( iter = 31; iter >= 0; iter-- )                    //loop to print the given new number in binary form.
            {
                if ( ((new_num >> iter) & 1) == 1 )
                    printf("1");
                else
                    printf("0");
            }
            
            printf("\nNew Replaced value is %d  : ",output);
            for ( iter = 31; iter >= 0; iter-- )                    //loop to print the output in binary form.
            {
                if ( ((output >> iter) & 1) == 1 )
                    printf("1");
                else
                    printf("0");
            }
        }
        printf("\nDo you want to continue (y/Y):");                 //input fetch for next cycle.
        getchar();
        scanf("%c",&character);
    }while ( character == 'y' || character == 'Y' );                //condition to execute next cycyle.

return 0;
}
/********************************************************END OF CODE********************************************************************/
