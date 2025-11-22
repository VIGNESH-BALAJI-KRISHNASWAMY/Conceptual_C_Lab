/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 11/10/2021.
*   Description     : Implement calc_mean for all data types.
*   Input           : ./a.out 
*   Output          :   	IMPLEMENTING MEAN CALCULATION FOR ALL DATA TYPES 
*                       Enter the number of elements : 2
*                       1. int
*                       2. short
*                       3. float
*                       4. double
*                       Enter the choice: 1
*                       Enter 2 numbers :
*                       a[0] -> 10
*                       a[1] -> 12
*                       The mean is: 11
*                       Do you want to continue (y/Y): y
*
*                       Enter the number of elements : 2
*                       1. int
*                       2. short
*                       3. float
*                       4. double
*                       Enter the choice: 3
*                       Enter 2 numbers :
*                       a[0] -> 1.1234567
*                       a[1] -> 2.2345678
*                       The mean is: 1.67901
*                       Do you want to continue (y/Y): n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

double calc_mean( void *,int,int );                                         //function definition.

int main()
{
    printf("\tIMPLEMENTING MEAN CALCULATION FOR ALL DATA TYPES ");         

    int num,choice;                                                         //input ,output and void pointer declarations.
    void *vptr = NULL;
    double ret;
    char character;
    do                                                                      //loop to continue the process.
    {
        printf("\nEnter the number of elements : ");                        //input fetch.
        scanf("%d",&num);

        printf("1. int\n2. short\n3. float\n4. double\nEnter the choice: ");
        scanf("%d",&choice);

        ret = calc_mean(vptr,num,choice);                                   //function call to calculate mean.
        printf("The mean is: %lg\n",ret);

        printf("Do you want to continue (y/Y): ");                          //input fetch for next cycle continution.
        __fpurge(stdin);                                                   //to prevent overflowed characters intrution in to next cycle.
        scanf(" %c",&character);
    }while( character == 'Y' || character == 'y');                          //condition forr next cycle.

  return 0;
}

double calc_mean( void *vptr, int num,int choice )                          //function definition for generic mean caculation.
{
    double sum = 0,mean;
    int iter;
    
    switch(choice)                                                          //switch case for different datatypes.
    {
        case 1:                                         //int
            vptr = malloc( sizeof(int) * num );         //dynamic memory allocation to void pointer using integer datatype size.
                if( vptr == NULL )
                {
                    printf("ERROR:Memory not allcated due to large size\n");
                    break;
                }
            printf("Enter %d numbers :\n",num);                                     
            for ( iter = 0; iter < num; iter++ )
            {
                printf("a[%d] -> ",iter);
                scanf("%d",(int*)vptr + iter);          //input fetch by typecasting void pointer to int datatype.
                sum = sum + *((int*)vptr + iter);
            }
            break;
        
        case 2:                                         //short.
            vptr = malloc( sizeof(short) * num );       
                if( vptr == NULL )
                {
                    printf("ERROR:Memory not allcated due to large size\n");
                    break;
                }
            printf("Enter %d numbers :\n",num);                                     
            for ( iter = 0; iter < num; iter++ )
            {
                printf("a[%d] -> ",iter);
                scanf("%hd",(short*)vptr + iter);       //input fetch by typecasting void pointer to short datatype.
                sum = sum + *((short*)vptr + iter);
            }
            break;
        
        case 3:                                         //float
            vptr = malloc( sizeof(float) * num );
                if( vptr == NULL )
                {
                    printf("ERROR:Memory not allcated due to large size\n");
                    break;
                }
            printf("Enter %d numbers :\n",num);                                     
            for ( iter = 0; iter < num; iter++ )
            {
                printf("a[%d] -> ",iter);
                scanf("%f",(float*)vptr + iter);        //input fetch by typecasting void pointer to float datatype.
                sum = sum + *((float*)vptr + iter);
            }
            break;
        
        case 4:                                         //double
            vptr = malloc( sizeof(double) * num );
                if( vptr == NULL )
                {
                    printf("ERROR:Memory not allcated due to large size\n");
                    break;
                }
            printf("Enter %d numbers :\n",num);                                     
            for ( iter = 0; iter < num; iter++ )
            {
                printf("a[%d] -> ",iter);
                scanf("%lf",(double*)vptr + iter);      //input fetch by typecasting void pointer to double datatype
                sum = sum + *((double*)vptr + iter);
            }
            break;
    }
    mean = sum/(double)num;                             //calculating the mean.
    free(vptr);                                         //deallocation of void pointer dynamic memory.
    return mean;                                        //returning the mean to main function.
}
/********************************************************END OF CODE********************************************************************/
