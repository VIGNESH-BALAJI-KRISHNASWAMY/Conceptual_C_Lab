/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 31/08/2021 
*   Description     : A program to print the power of N series.
*   Input           : 
*   Output          : 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int num,power,iter,num_power = 1;

    printf("\tPRNTING POWER OF N SERIES \nEnter a number for which it's power to be calculated : ");
    scanf("%d",&num);
    printf("\nEnter the maximum range of power series : ");
    scanf("%d",&power);

    for ( iter = 1; iter <= power; iter++ )
    {
        num_power = num * num_power;
        if ( num_power == 0 )
            break;
        printf("\n%d to the power of %d is :  %d ",num,iter,num_power);
    }

return 0;
}
/********************************************************END OF CODE********************************************************************/
