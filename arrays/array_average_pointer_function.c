/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 
*   Description     : Array Average using pointer.
*   Input           : 
*   Output          : 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
double average_array(int *,int);
int main()
{
    int num,iter;
    float ret;
    printf("\tAVERAGE OF ARRAY ELEMENTS USING POINTER");
    printf("\nEnter the num of elements in the array : ");
    scanf("%d",&num);
    int array[num];
    printf("Enter the %d elements of the array: \n",num);
    for ( iter = 0; iter < num; iter++ )
    {
        scanf("%d",&array[iter]);
    }

    ret = average_array(array,num);
    printf("\nAverage of %d elements is : %g\n",num,ret);

return 0;
}

double average_array(int *array, int size)
{
    int iter,sum = 0;
    double avg;
    for ( iter = 0; iter < size; iter++ )
    {
        sum += *(array + iter);
    }
    avg = (float) sum / (float) size;
    return avg;
}
/********************************************************END OF CODE********************************************************************/
