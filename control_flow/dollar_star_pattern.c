/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 02/08/2021
*   Description     : A program to print $*$ pattern
*   Input           : 
*   Output          : 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int total_num,star_num,partial_num,iteration;
    
    printf("\tPRINTING THE DOLLAR STAR PATTERN ($$$***$$$)\nEnter the Total number of characters to be printed : ");
    scanf("%d",&total_num);

    printf("\nEnter the number of stars to be printed at the middle : ");
    scanf("%d",&star_num);

    if ( (total_num % 2) == 0 || (star_num % 2) == 0 )
        printf("\n ERROR:Please provide only ODD values for both of the above inputs!");
    
    else if ( star_num > total_num )
        printf("\nERROR:Total number of characters exceeded by the star characters!");
    
    else
    {
        partial_num = (total_num - star_num) / 2 ;

        for ( iteration = 1; iteration <= partial_num; iteration++ )
        {
            printf("$");
            
            if ( iteration == partial_num )
            {
                iteration = 1;
                for ( iteration = 1; iteration <= star_num; iteration++ )
                {
                    printf("*");
                    
                    if ( iteration == star_num )
                    {
                        iteration = 1;
                        for ( iteration = 1; iteration <= partial_num; iteration++ )
                        {
                            printf("$");
                            
                            if ( iteration == partial_num )
                               goto exit_lp2; //break;
                        }
                exit_lp2 : printf("\n");break;

                    }

                }
            }

         }
    }
    
    return 0;
}















/********************************************************END OF CODE********************************************************************/

