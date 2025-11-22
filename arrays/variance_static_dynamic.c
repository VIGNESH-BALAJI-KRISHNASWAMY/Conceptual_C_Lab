/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 13/10/2021. 
*   Description     : Variance calculation with static arrays & with dynamic arrays.
*   Input           : ./a.out 
*   Output          :   	 VARIANCE CALCULATION USING STATIC AND DYNAMIC MEMORY ALLOCATION
*                       Enter the number of elements : 3
*                       1. Static allocation
*                       2. Dynamic allocation
*                       Enter your choice : 1
*                       Enter the 3 elements: 
*                       [0] -> 1
*                       [1] -> 2
*                       [2] -> 3
*                       The Variance of entered numbers is : 0.666667
*                       Do you want to continue (y/Y): y
*
*                       Enter the number of elements : 3
*                       1. Static allocation
*                       2. Dynamic allocation
*                       Enter your choice : 2
*                       Memory allocatedEnter the 3 elements: 
*                       [0] -> 111
*                       [1] -> 232
*                       [2] -> 432
*                       The Variance of entered numbers is : 17404.7
*                       Do you want to continue (y/Y): n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

double variance(int *,int );                                //variance function declaration.

int main()
{
    char character;                                         //input,output and pointer variable declaration and definition.
    int num,choice;
    double var;
    int *ptr = NULL;
    printf("\t VARIANCE CALCULATION USING STATIC AND DYNAMIC MEMORY ALLOCATION");
    
    do                                                      //loop to continue the process.
    {
        printf("\nEnter the number of elements : ");        //input fetch.
        scanf("%d",&num);

        printf("1. Static allocation\n2. Dynamic allocation\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)                                      //switch case for static and dynamic memory allocation.
        {
            case 1:
                {
                    int array[num];                         //static array declaration.
                    ptr = array;                            //base address of array is assigned to pointer.
                    printf("Enter the %d elements: \n",num);
                    var = variance(ptr,num);                //variance function call.
                    printf("The Variance of entered numbers is : %lg",var);
                }
                break;

            case 2:
                {
                    ptr = malloc( sizeof(int) * num );      //dynamic memory allocation 
                        if( ptr == NULL )                   //error detection condition.
                        {
                            printf("ERROR!Memory not allocated due to exceeding memory range");
                            break;
                        }
                        else
                            printf("Memory allocated");

                    printf("Enter the %d elements: \n",num);
                    var = variance(ptr,num);                //variance function call with dynamic memory.
                    free(ptr);                              //deallocation of dynamic memory allocated.
                    ptr = NULL;
                    printf("The Variance of entered numbers is : %lg",var);
                }

        }

        printf("\nDo you want to continue (y/Y): ");        //input fetch for next cycle.
        __fpurge(stdin);                                    //prevention of intrution of overflowed elements in to next variable.
        scanf(" %c",&character);
    }while( character == 'Y' || character == 'y' );

}

double variance(int *ptr,int num)                           //variance function definition.
{

    double mean,sum = 0,temp;
    double var;
    int iter;

            for( iter = 0; iter < num; iter++ )             //loop to find the sum of array elements.
            {
                printf("[%d] -> ",iter);
                scanf("%d",&ptr[iter]);
                sum += ptr[iter];
            }
            mean = sum / num;                               
            sum = 0;
            for( iter = 0; iter < num; iter++ )
            {
                temp = ptr[iter];
                ptr[iter] = temp - mean;
                temp = ptr[iter];
                ptr[iter] = temp * temp;
            }
            while( --iter >= 0)                             //loop to find sum of squares of individual mean.
            {
                sum += ptr[iter];
            }
            var = sum / num;

    return (var);                                           //returning variance.                                
}
/********************************************************END OF CODE********************************************************************/
