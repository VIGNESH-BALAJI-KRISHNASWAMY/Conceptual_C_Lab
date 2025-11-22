/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 27/09/2021.
*   Description     : Read n & n floats in a float array ’store’. Print the values in sorted order without modifying or copying ’store’.
*   Input           : ./a.out 
*	Output          :        SORTING GIVEN ARRAY WITHOUT COPYING OR MODIFYING ARRAY ELEMENTS
*                       Enter the number of array elements : 3
*                       [0] = 8
*                       [1] = 5
*                       [2] = -4
*                       After Sorting:
*                       -4 5 8 
*                       Do you want to continue (y/Y) : y
*
*                       Enter the number of array elements : 5
*                       [0] = 8
*                       [1] = -5
*                       [2] = -1.67
*                       [3] = 3.54
*                       [4] = 2.78
*                       After Sorting:
*                       -5 -1.67 2.78 3.54 8 
*                       Do you want to continue (y/Y) : n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
int sort_array(float *,int,float,float);                            //Declaring sort_array function.

int main()
{
    int num,iter;                                                   //declaring input variables.
    char character;
    printf("\tSORTING GIVEN ARRAY WITHOUT COPYING OR MODIFYING ARRAY ELEMENTS");
    
    do                                                              //Loop to continue the process.
    {
        printf("\nEnter the number of array elements : ");          //fetching array size.
        scanf("%d",&num);
    
        float store[num],small_num,large_num;
        for ( iter = 0; iter < num; iter++ )                        //loop to fetch the array elements.
        {
            printf("[%d] = ",iter);
            scanf("%f",&store[iter]);
        }
    
        small_num = store[0];
        large_num = store[0];
        for ( iter = 0; iter < num; iter++ )                        //loop to identify the smallest and largest array element.
        {
            if(small_num > store[iter])
                small_num = store[iter];
            if(large_num < store[iter])
                large_num = store[iter];
        }
    
        printf("After Sorting:\n");
        sort_array(store,num,small_num,large_num);                  //Sorting function call.

        printf("Do you want to continue (y/Y) : ");
        scanf(" %c",&character);
    
    }while( character == 'y' || character == 'Y');                  //exit condition.
}

int sort_array ( float *array,int size,float small_num,float large_num )   //function definition.
{
  float first = small_num,temp;
  int iter,dyn;
  printf("%g ",first);                            //printing the smallest array element initially.
  
  while(first != large_num)                       //loop runs until smallest num != largest num
  {
    for( iter = 0; iter < size; iter++ )          //loop to find the number just after the smallest number in the array 
    {
          if( (first < *(array + iter)) && (first != *(array + iter)) )
          {
              temp = *(array + iter);     //temp is the next number present after the first smallest number in the array.
              break;                   //break after finding the number next to smallest number.
          }
    }
    
    for( iter = 0; iter < size; iter++ ) //loop to swap the previously found temp, with a number smaller than it and greater than the smallest element of array. 
    {
          if( (*(array + iter) < temp) &&  (first < *(array + iter)) )
              temp = *(array + iter);
    }
    
    printf("%g ",temp);       //printing the "next smaller number" after the first(smallest) variable.
    first = temp;            //changing the "next smaller number"from the smallest number to the "smallest number" to process next cycle.
  }
  printf("\n");
}
/********************************************************END OF CODE********************************************************************/
