/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 13/09/2021 
*   Description     : A Program to find the median of two unsorted arrays.
*   Input           : ./a.out 
*   Output          :     FINDING MEDIAN OF TWO UNSORTED ARRAYS
*
*                     Enter the 'n'value of Array A : 6
*                     Enter the 6 elements one by one for Array A : 7 4 5 2 1 8
*                     After Sorting Array A :  1  2  4  5  7  8  
*                     The Median of Array1 : 4.5
*                     Enter the 'n'value of Array B : 5
*                     Enter the 5 elements one by one for Array B : 2 1 4 8 3
*                     After Sorting Array B :  1  2  3  4  8  
*                     The Median of Array2 : 3
*                     Median of Array A and Array B is : 3.75
*                     Do you want to continue (y/Y) : n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int iter,num1,num2,temp,dyn,position;                                   //declaration of input and output variables.
    float median1,median2;
    char character;

    printf("\tFINDING MEDIAN OF TWO UNSORTED ARRAYS\n");
    
    do                                                                      //loop to iterate next cycle.
    {
        printf("\nEnter the 'n'value of Array A : ");                       //input fetch for array A.
        scanf("%d",&num1);
        int array1[num1];                                                   //initialization of array A.
        printf("Enter the %d elements one by one for Array A : ",num1);     
        for ( iter = 0; iter < num1; iter++ )                               //loop to fetch array A elements.
        {
            scanf("%d",&array1[iter]);
        }

        printf("After Sorting Array A :  ");
        for ( iter = 0; iter < num1; iter++ )                               //loop to sort array A in ascending order.
        {
            for ( dyn = 0; dyn < num1 - iter - 1; dyn++ )
            {
                if ( array1[dyn] > array1[dyn + 1] )
                {
                    temp = array1[dyn];
                    array1[dyn] = array1[dyn + 1];
                    array1[dyn + 1] = temp;
                }
            }
        }
    
        for ( iter = 0; iter < num1; iter++ )                               //loop to display sorted elements of array A
        {
            printf("%d  ",array1[iter]);
        }

        position = (num1 / 2);                                              //calculating the position of the median.

        if ( num1 % 2 != 0 )                                                //condition to detect odd or even num1 and calculate median.
        {
            median1 = array1[position];
            printf("\nThe Median of Array1 : %g", median1);
        }
        else
        {
            median1 = (array1[position] + array1[position - 1]) / 2.0;
            printf("\nThe Median of Array1 : %g", median1);
        }

        printf("\nEnter the 'n'value of Array B : ");                        //input fetch for array B.
        scanf("%d",&num2);
        int array2[num2];                                                    //initialization of array B.
        printf("Enter the %d elements one by one for Array B : ",num2);      
        for ( iter = 0; iter < num2; iter++ )                                //loop to fetch array B elements.
        {
            scanf("%d",&array2[iter]);
        }

        printf("After Sorting Array B :  ");
        for ( iter = 0; iter < num2; iter++ )                                //loop to sort array B in ascending order.
        {
            for ( dyn = 0; dyn < num2 - iter - 1; dyn++ )
            {
                if ( array2[dyn] > array2[dyn + 1] )
                {
                    temp = array2[dyn];
                    array2[dyn] = array2[dyn + 1];
                    array2[dyn + 1] = temp;
                }
            }
        }
        for ( iter = 0; iter < num2; iter++ )                                //loop to display sorted elements of array A
        {
            printf("%d  ",array2[iter]);
        }    

        position = (num2 / 2);                                               //calculating the position of the median.

        if ( num2 % 2 != 0 )                                                 //condition to detect odd or even num1 and calculate median.
        {
            median2 = array2[position];
            printf("\nThe Median of Array2 : %g", median2);
        }
        else
        {
            median2 = (array2[position] + array2[position - 1]) / 2.0;
            printf("\nThe Median of Array1 : %g", median2);
        }

        printf("\nMedian of Array A and Array B is : %g",((median1 + median2)/2));  //calculating the median of array A and array B.
        
        printf("\nDo you want to continue (y/Y) : ");                       //input fetch for next cycle.
        scanf(" %c",&character);

    }while ( character == 'y' || character == 'Y' );                        //condition for continuous execution of next cycle.

return 0;
}
/********************************************************END OF CODE********************************************************************/
