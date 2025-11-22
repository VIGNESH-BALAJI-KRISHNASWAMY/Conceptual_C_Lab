/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 08/09/2021
*   Description     : A program to get_nbits,replace_nbits,get_nbits_from_pos,replace_nbits_from_pos,toggle_bits,and print the bits.
*   Input           : ./a.out 
*   Output          :      	IMPLEMENTING BITWISE FUNCTIONS
*                    SELECT FROM BELOW FUNCTIONS
*                    1.get_nbits
*                    2.replace_nbits
*                    3.get_nbits_from_pos
*                    4.replace_nbits_from_pos
*                    5.toggle_bits_from_pos
*                    6.print_bits
*                    Enter the respective number: 1
*                   	GETTING N BITS FROM INITIAL POSITION
*                    Enter the number: 15
*                    Enter the number of bits to get : 3
*                    Entered number is  15 :			00000000000000000000000000001111
*                    The number got from last 3 bits is  7 : 00000000000000000000000000000111
*                    Do you want to continue (y/Y): y
*
*                    SELECT FROM BELOW FUNCTIONS
*                    1.get_nbits
*                    2.replace_nbits
*                    3.get_nbits_from_pos
*                    4.replace_nbits_from_pos
*                    5.toggle_bits_from_pos
*                    6.print_bits
*                    Enter the respective number: 2
*                   	REPLACING N BITS FROM INITIAL POSITION
*                    Enter the number: 12
*                    Enter the number of bits to be replaced : 5
*                    Enter the new value from which number of bits to be selected : 17
*                    Given number 12 :					00000000000000000000000000001100
*                    Given new number 17 : 				00000000000000000000000000010001
*                    Output 17 : 						00000000000000000000000000010001
*                    Do you want to continue (y/Y): y
*
*                    SELECT FROM BELOW FUNCTIONS
*                    1.get_nbits
*                    2.replace_nbits
*                    3.get_nbits_from_pos
*                    4.replace_nbits_from_pos
*                    5.toggle_bits_from_pos
*                    6.print_bits
*                    Enter the respective number: 3
*                      	GET N BITS FROM POSITION
*                    Enter the number: 12
*                    Enter the number of bits to get : 4
*                    Enter the number position : 3
*                    Given number 12 : 		00000000000000000000000000001100
*                    output 12 : 			00000000000000000000000000001100
*                    Do you want to continue (y/Y): y
*
*                    SELECT FROM BELOW FUNCTIONS
*                    1.get_nbits
*                    2.replace_nbits
*                    3.get_nbits_from_pos
*                    4.replace_nbits_from_pos
*                    5.toggle_bits_from_pos
*                    6.print_bits
*                    Enter the respective number: 4
*                   	REPLACE N BITS FROM POSITION
*                    Enter the number: 12
*                    Enter the number of bits to replace : 1 
*                    Enter the number position : 4
*                    Enter the new value from which number of bits to be selected : 15
*                    Entered number is 12 :     	00000000000000000000000000001100
*                    Entered New number 15 : 		00000000000000000000000000001111
*                    output 28 :        			00000000000000000000000000011100
*                    Do you want to continue (y/Y): y
*
*                    SELECT FROM BELOW FUNCTIONS
*                    1.get_nbits
*                    2.replace_nbits
*                    3.get_nbits_from_pos
*                    4.replace_nbits_from_pos
*                    5.toggle_bits_from_pos
*                    6.print_bits
*                    Enter the respective number: 4
*                   	REPLACE N BITS FROM POSITION
*                    Enter the number: 322
*                    Enter the number of bits to replace : 21
*                    Enter the number position : 3
*                    Enter the new value from which number of bits to be selected : 1
*                    ERROR:Number position should be >= the number of bits to get!
*                    Do you want to continue (y/Y): y
*
*                    SELECT FROM BELOW FUNCTIONS
*                    1.get_nbits
*                    2.replace_nbits
*                    3.get_nbits_from_pos
*                    4.replace_nbits_from_pos
*                    5.toggle_bits_from_pos
*                    6.print_bits
*                    Enter the respective number: 5
*                   	TOGGLE BITS FROM POSITION
*                    Enter the number: 34
*                    Enter the number of bits to be toggled : 3
*                    Enter the number position : 5
*                    Given Number 34 : 		00000000000000000000000000100010
*                    output 26 : 			00000000000000000000000000011010
*                    Do you want to continue (y/Y): y
*
*                    SELECT FROM BELOW FUNCTIONS
*                    1.get_nbits
*                    2.replace_nbits
*                    3.get_nbits_from_pos
*                    4.replace_nbits_from_pos
*                    5.toggle_bits_from_pos
*                    6.print_bits
*                    Enter the respective number: 6
*                   	PRINTING THE GIVEN NUMBER OF BITS
*                    Enter the number: 19
*                    Enter the number of bits to be printed : 3
*                    Entered number 19 : 		00000000000000000000000000010011
*                    output 3 : 	    		011
*                    Do you want to continue (y/Y): n
* 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int num,choice,output,mask,new_val,iter;              //declaration of input and output variables
    char character;
    int cleared_val,modified_new_val,clear_mask;
    int set_mask_bits,clear_mask_bits,num_of_bits,num_position,shift,replace_bits,set_mask;
    
    printf("\tIMPLEMENTING BITWISE FUNCTIONS");
    do
    {
        printf("\nSELECT FROM BELOW FUNCTIONS\n1.get_nbits\n2.replace_nbits\n3.get_nbits_from_pos\n4.replace_nbits_from_pos\n5.toggle_bits_from_pos\n6.print_bits\nEnter the respective number: ");
        scanf("%d",&choice);                              //selecting particular type of operation to perform.

        switch ( choice )
        {
            case 1:
                printf("\tGETTING N BITS FROM INITIAL POSITION\nEnter the number: ");           //input fetch.
                scanf("%d",&num);
                printf("Enter the number of bits to get : ");
                scanf("%d",&num_of_bits);
                
                
                mask = (1 << num_of_bits) - 1;      //creating mask to get desired bits from the input.
                output = num & mask;                //setting the desired bits with the help of mask created.

              
                printf("Binary form of %d :\t\t\t",num); 
                for ( iter = 31; iter >= 0; iter-- )         //loop to print the binary form of input number
                {
                    if ( ((num >> iter) & 1) == 1 )         //condition to shift and print each bits from 31 to 0.
                        printf("1");
                    else
                        printf("0");
                }
                printf("\nThe number got from last %d bits is  %d : ",num_of_bits,output);
                for ( iter = 31; iter >= 0; iter-- )        //loop to print the binary form of output.
                {
                    if ( ((output >> iter) & 1) == 1 )
                        printf("1");
                    else
                        printf("0");
                }
                break;
            
            case 2:
                printf("\tREPLACING N BITS FROM INITIAL POSITION\nEnter the number: ");     //input fetch.
                scanf("%d",&num);
                printf("Enter the number of bits to be replaced : ");
                scanf("%d",&num_of_bits);
                printf("Enter the new value from which number of bits to be selected : ");
                scanf("%d",&new_val);
                
                mask = (1 << num_of_bits) - 1;              //mask to set the desired bits in the new value.
                clear_mask = ~(mask);                       //mask to clear the desired bits in the old value.
                cleared_val = num & clear_mask;             //clearing desired bits in old value
                modified_new_val = new_val & mask;          //setting the desired bits in new value.
                output = modified_new_val | cleared_val;    //replacing the old value with new value in desired bits.
                
                printf("Given number %d :\t\t\t\t\t",num);
                for ( iter = 31; iter >= 0; iter-- )        //loop to print the binary form of input number.
                {
                    if ( ((num >> iter) & 1) == 1 )
                        printf("1");
                    else
                        printf("0");
                }
                
                printf("\nGiven new number %d : \t\t\t\t\t",new_val); //loop to print the binary form of new number.
                for ( iter = 31; iter >= 0; iter-- )
                {
                    if ( ((new_val >> iter) & 1) == 1 )
                        printf("1");
                    else
                        printf("0");
                }
                
                printf("\nOutput %d : \t\t\t\t\t\t",output);    //loop to print the binary form of output.
                for ( iter = 31; iter >= 0; iter-- )
                {
                    if ( ((output >> iter) & 1) == 1 )
                        printf("1");
                    else
                        printf("0");
                }
                break;

            case 3:
                printf("\tGET N BITS FROM POSITION\nEnter the number: ");   //input fetch.
                scanf("%d",&num);
                printf("Enter the number of bits to get : ");
                scanf("%d",&num_of_bits);
                printf("Enter the number position : ");
                scanf("%d",&num_position);
                
                if ( (num_position + 1) < num_of_bits ) //condition to overcome insufficient bits in LSB side for operations.
                    printf("ERROR:Number position should be >= the number of bits to get!");
                else
                {
                    shift = num_position - num_of_bits + 1;        //calculating the number of shifts to perform toget desired bits.
                    clear_mask_bits = ~((1 << shift) - 1);         //finding no.of bits from LSB to be cleared.
                    set_mask_bits = (1 << (num_position + 1)) - 1; //finding no.of bits from given position to be set.
                    mask = set_mask_bits & clear_mask_bits;        //creating the desired mask.
                    output = (mask & num) >> shift;                //setting the desired number positions and shifting them to get them.

                    printf("Given number %d : \t\t",num);           //loop to print the binary form of input number.
                    for ( iter = 31; iter >= 0; iter-- )
                    {
                        if ( ((num >> iter) & 1) == 1 )
                            printf("1");
                        else
                            printf("0");
                    }

                    printf("\noutput %d : \t\t\t",output);
                    for ( iter = 31; iter >= 0; iter-- )            //loop to print the binary form of output.
                    {
                        if ( ((output >> iter) & 1) == 1 )
                            printf("1");
                        else
                            printf("0");
                    }
                }
                break;

            case 4:
                printf("\tREPLACE N BITS FROM POSITION\nEnter the number: ");                   //input fetch.
                scanf("%d",&num);
                printf("Enter the number of bits to replace : ");
                scanf("%d",&num_of_bits);
                printf("Enter the number position : ");
                scanf("%d",&num_position);
                printf("Enter the new value from which number of bits to be selected : ");
                scanf("%d",&new_val);

                if ( (num_position + 1) < num_of_bits )
                    printf("ERROR:Number position should be >= the number of bits to get!");//detct insufficient bits in LSB side for operation.
                else
                {
                    mask = (1 << num_of_bits) - 1;          //mask to set the desired bits in the new value.
                    set_mask = mask & new_val;              //cropping the desired bits using mask.
                    shift = num_position - num_of_bits + 1; //calculating the number of shifts to perform to get desired bit's position.
                    mask = ~(mask << shift);                //creating  mask to clear the old value from the given position.
                    clear_mask = num & mask;                //clearing the respective bits which is to be rewritten with new value.
                    replace_bits = set_mask << shift;       //value to be written in cleared position is shifted to reach the position.
                    output = clear_mask | replace_bits;     //new value of desired bits written in the respective position.

                    printf("Entered number is %d : \t\t",num);  //loop to print the binary form of input.
                    for ( iter = 31; iter >= 0; iter-- )
                    {
                        if ( ((num >> iter) & 1) == 1 )
                            printf("1");
                        else
                            printf("0");
                    }

                    printf("\nEntered New number %d : \t\t",new_val);
                    for ( iter = 31; iter >= 0; iter-- )                //loop to print the binary form of new number.
                    {
                        if ( ((new_val >> iter) & 1) == 1 )
                            printf("1");
                        else
                            printf("0");
                    }
                    
                    printf("\noutput %d : \t\t\t",output);
                    for ( iter = 31; iter >= 0; iter-- )                //loop to print the binary form of output.
                    {
                        if ( ((output >> iter) & 1) == 1 )
                            printf("1");
                        else
                            printf("0");
                    }
                }
                break;

            case 5:
                printf("\tTOGGLE BITS FROM POSITION\nEnter the number: ");    //input fetch.
                scanf("%d",&num);
                printf("Enter the number of bits to be toggled : ");
                scanf("%d",&num_of_bits);
                printf("Enter the number position : ");
                scanf("%d",&num_position);
                
                if ( (num_position + 1) < num_of_bits )
                    printf("ERROR:Number position should be >= the number of bits to get!");
                else
                {
                    mask = (1 << num_of_bits) - 1;          //mask to set the desired bits in the new value.
                    shift = num_position - num_of_bits + 1; //calculating the number of shifts to perform to get desired bit's position.
                    mask = mask << shift;                   //shifting the mask to the desired position.
                    output = num ^ mask;                    //bitwise xor operation to toggle the desired position bits.
                    
                    printf("Given Number %d : \t\t",num);   //loop to print the binary form of input number.
                    for ( iter = 31; iter >= 0; iter-- )
                    {
                        if ( ((num >> iter) & 1) == 1 )
                            printf("1");
                        else
                            printf("0");
                    }

                    printf("\noutput %d : \t\t\t",output);  //loop to print the binary form of output.
                    for ( iter = 31; iter >= 0; iter-- )
                    {
                        if ( ((output >> iter) & 1) == 1 )
                            printf("1");
                        else
                            printf("0");
                    }
                }
                break;
                
            case 6:
                printf("\tPRINTING THE GIVEN NUMBER OF BITS\nEnter the number: ");    //input fetch.
                scanf("%d",&num);
                printf("Enter the number of bits to be printed : ");
                scanf("%d",&num_of_bits);
                
                if ( num_of_bits > ((sizeof(int) * 8) - 1) )        //condition to avoid overflow of bits.
                    num_of_bits = (sizeof(int) * 8);
                
                mask = (1 << num_of_bits) - 1;                      //mask to crop desired number of bits.
                output = num & mask;                                //setting the desired number of bits.
                
                printf("Entered number %d : \t\t",num);             //loop to print the binary form of input number.
                for ( iter = 31; iter >= 0; iter-- )
                {
                    if ( ((num >> iter) & 1) == 1 )
                        printf("1");
                    else
                        printf("0");
                }

                printf("\noutput %d : \t\t\t",output);              //loop to print the binary form of output.
                for ( iter = 0; iter <= num_of_bits - 1; iter++ )
                {
                    if ( ((output >> (num_of_bits - 1) - iter) & 1) == 1 )
                        printf("1");
                    else
                        printf("0");
                }
                break;
        
        }
        printf("\nDo you want to continue (y/Y): ");        //input fetch for next cycle.
        getchar();
        scanf("%c",&character);
    }while( character == 'y' || character == 'Y' );         //condition to continue next cycle.

return 0;
}
/********************************************************END OF CODE********************************************************************/
