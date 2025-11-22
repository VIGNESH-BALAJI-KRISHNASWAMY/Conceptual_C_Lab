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
    printf("\tARRAY ROTATION");
    int num,iter,temp,dyn;
    char character;
    printf("\nEnter the number of elements 'n'in an array :");
    scanf("%d",&num);
    int array[num];
    printf("Enter %d numbers :\n",num);

    for ( iter = 0; iter < num; iter++ )
    {   
        scanf("%d",&array[iter]);
    }   

    do{
           temp = array[0];
            for ( iter = 0; iter < num - 1; iter++ )
            {
                array[iter] = array[iter + 1];
            }
                array[num - 1] = temp;
                printf("\nAfter Rotating: \n");
                for ( iter = 0; iter < num; iter++ )
                {   
                    printf("%d\n",array[iter]);
                }
                printf("\nDo you want to continue (y/Y):");
                getchar();
                scanf("%c",&character);
    }while( character == 'y' || character == 'Y' );
 return 0;
}
/********************************************************END OF CODE********************************************************************/
