/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 
*   Description     :
*   Input           : ./a.out 
*	Output          :          2'S COMPLEMENT OF A NUMBER WITH IT'S SIGNED AND UNSIGNED FORM
*                     Enter the value of 'N' : 12
*
*                     BINARY FORM +12:	    	00000000000000000000000000001100
*                     2'S COMPLEMENT FORM -12:	11111111111111111111111111110100
*                     Do you want to continue (y/Y) : y  
*
*                     Enter the value of 'N' : -12
*
*                     BINARY FORM +-12: 		11111111111111111111111111110100
*                     2'S COMPLEMENT FORM --12:	00000000000000000000000000001100
*                     Do you want to continue (y/Y) : n
*                                                            
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int num,shift,shift_num,mask = 0,val,complement;                             //declaration & initialization.
    unsigned int output;
    char character;
    printf("\t2'S COMPLEMENT OF A NUMBER WITH IT'S SIGNED AND UNSIGNED FORM");
    do                                                                          //loop to continue the operation.
    {
        printf("\nEnter the value of 'N' : ");                                  //input fetch.
        scanf("%d",&num);

        printf("\nBINARY FORM +%d:\t\t",num);                                //loop to print the binary form of the given number.
        for ( shift = 31; shift >= 0; shift-- )
        {
            mask = 1 << shift;                                   //mask created each time to get each bits in respective position.
            output = num & mask;                                 //Each bit in the position 0 to 31 is separately obtained.
            if ( output >= 1)                                    //condition to detect 0 or 1.
                printf("1");
            else
                printf("0");
        }
        
        printf("\n2'S COMPLEMENT FORM -%d:\t",num);
        num = ~num + 1;                                          //finding 2's complement of given number.
       complement = num;
        for ( shift = 31; shift >= 0; shift-- )                  //loop to print the 2's complement of a given number.
        {
            mask = 1 << shift;
            output = complement & mask;
            if ( output > 0)
                printf("1");
            else
                printf("0");
        }

        printf("\nDo you want to continue (y/Y) : ");           //input fetch for next cycle.
        getchar();
        scanf("%c",&character);

    } while ( character == 'y' || character == 'Y' );           //condition for execution of next cycle.

return 0;
}
/********************************************************END OF CODE********************************************************************/
