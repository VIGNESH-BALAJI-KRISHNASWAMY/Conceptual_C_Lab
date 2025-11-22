/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 
*   Description     :
*   Input           : 
*   Output          : 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int num,mask,up_nibble,low_nibble,up_mask;
    printf("\tSWAPPING THE NIBBLE for 8 bits");
    
    
        printf("\nEnter the number : ");
        scanf("%x",&num);
        
        mask = (1 << 5) - 1;
        low_nibble=num & mask;
        up_nibble = (num >> 4) & mask;
        printf("%x",low_nibble);
        printf("%x\n",up_nibble);

        return 0;
}
/********************************************************END OF CODE********************************************************************/
