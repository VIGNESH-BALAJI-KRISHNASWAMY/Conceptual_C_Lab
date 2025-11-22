/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 02/09/2021 
*   Description     : A Program to generate Arithmetic Progression, Geometric Progression, Harmonic Progression.
*   Input           : ./a.out 
*   Output          :	      FINDING AP,GP & HP
*                        Enter the First number 'A' : 0
*                        Enter the common Difference/Ratio 'R' : 2
*                        Enter the number of terms 'N' : 10
*                        AP = 0,2,4,6,8,10,12,14,16,18.
*                        GP = Since starting number is 0 GP doesnot exists
*                        HP = since starting number is 0,HP sequence cannot start with infinity 
*                        Do you want to continue (y/Y): y
*
*                        Enter the First number 'A' : 2
*                        Enter the common Difference/Ratio 'R' : 3
*                        Enter the number of terms 'N' : 5
*                        AP = 2,5,8,11,14.
*                        GP = 2,6,18,54,162.
*                        HP = 0.500000,0.200000,0.125000,0.090909,0.071429.
*                        Do you want to continue (y/Y): y
*
*                        Enter the First number 'A' : 2000
*                        Enter the common Difference/Ratio 'R' : 2
*                        Enter the number of terms 'N' : 10
*                        Invalid Input(s):Number(s) out of Range! provide number(s) within 2^10
*                        Do you want to continue (y/Y): y
*
*                        Enter the First number 'A' : -22
*                        Enter the common Difference/Ratio 'R' : 2
*                        Enter the number of terms 'N' : 1
*                        Invaild Input(s) : Please enter only positve values
*                        Do you want to continue (y/Y): n
*
*
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int first_num,comm_dor,num_of_terms,iter;   //initialization and declaration of input variables
    char character;
    int AP = 0,GP;                              //initialization and declaration of output variables
    float HP;
    int prod = 1,power,max_range;               //initialization and declaration of variables to set range

    for ( power = 0; power < 10; power++ )      //loop to set max range i.e. 2^10 
    {
        prod = prod * 2 ;
    }
    max_range = prod;
 
    printf("\tFINDING AP,GP & HP\n");
    
    do                                                      //loop to continue the operation
    {
        printf("Enter the First number 'A' : ");            //input fetch
        scanf("%d",&first_num);
    
        printf("Enter the common Difference/Ratio 'R' : ");
        scanf("%d",&comm_dor);

        printf("Enter the number of terms 'N' : ");
        scanf("%d",&num_of_terms);

        if ( first_num < 0 || comm_dor < 0 || num_of_terms < 0 )                //input evaluation
            printf("Invaild Input(s) : Please enter only positve values");
       
        else if ( first_num > max_range || comm_dor > max_range || num_of_terms > max_range )
            printf("Invalid Input(s):Number(s) out of Range! provide number(s) within 2^10");

        else if ( comm_dor == 0 || num_of_terms == 0 )
            printf("Invalid Input: Common difference / Ratio and number of terms 'N' cannot be 0");
        
        else
        { 
            printf("AP = ");                                        //loop to perform AP
            for ( iter = 1; iter <= num_of_terms; iter++ )
            {
                if ( iter == 1 )                                    //condition to diaplay first element in the series.
                    AP = first_num;                      
                else
                    AP = AP + comm_dor;                             //modifying the series based on common ratio.
                    if ( iter == num_of_terms )                     //condition for presentation. (, and .)
                        printf("%d.",AP);                            
                    else
                        printf("%d,",AP);
            }

            printf("\nGP = ");
            for ( iter = 1; iter <= num_of_terms; iter++ )          //loop to perform GP
            {
                if ( iter == 1 )                                    //condition to display first element in the series.
                {
                    GP = first_num;
                    if( GP == 0 )                                   //condition to stop execution from the value of starting number.
                    {
                        printf("Since starting number is 0 GP doesnot exists");
                        break;
                    }
                }
                else
                    GP = GP * comm_dor;                             //modifying series based on Common ratio
                    
                if ( iter == num_of_terms )                         //condition for presentation.
                        printf("%d.",GP);
                else
                        printf("%d,",GP);
            }
        
            printf("\nHP = ");                                      //start of HP 
            for ( iter = 1; iter <= num_of_terms; iter++ )
            {
                if ( iter == 1 )                                    //displaying first number in HP sequence
                {
                    AP = first_num;
                    if( AP == 0 )                                   //condition to stop HP Sequence execution.
                    {
                        printf("since starting number is 0,HP sequence cannot start with infinity ");
                        break;
                    }
                }
                else
                    AP = AP + comm_dor;

                    HP = (float)1/(float)AP;        //explicit type casing to convert integer data type of 1 and AP to float
                    if ( iter == num_of_terms )     //condition for displaying the elements in the sequence with readability.
                        printf("%f.",HP);
                    else
                        printf("%f,",HP);
            }
        }
     printf("\nDo you want to continue (y/Y): "); //input fetch to execut the operation further.
     getchar();
     scanf("%c",&character);
     printf("\n");

    } while (character == 'y' || character == 'Y'); //condition for continuing operation.
    
    return 0;
}
/********************************************************END OF CODE********************************************************************/
