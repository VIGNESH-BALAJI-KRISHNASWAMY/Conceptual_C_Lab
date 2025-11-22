/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 10/09/2021 
*   Description     : Finding the average of array elements.
*   Input           : 
*   Output          : 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int num,sum = 0,iter;
    float average;
    printf("\tFINDING AVERAGE OF ARRAY ELEMENTS");
    printf("\nEnter the number of elements 'n' to find the average :");
    scanf("%d",&num);
    int array[num];
    printf("Enter the %d numbers :\n",num);
    
    for ( iter = 0; iter < num; iter++ )
    {
        scanf("%d",&array[iter]);
        sum+=array[iter];
    }
    average = (float) sum / num;
    printf("The Sum and Average of %d numbers is %d and %g\n",num,sum,average);

return 0;
}
/********************************************************END OF CODE********************************************************************/
