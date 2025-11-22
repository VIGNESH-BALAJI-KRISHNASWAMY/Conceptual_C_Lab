/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            :  
*   Description     : A Program to generate fibbonacci numbers <= 'n' using recursions without using static keyword and global variables.
*   Input           : ./a.out 
*	Output          :       FIBBONACCI SERIES TILL A GIVEN NUMBER
*                       Enter a number till which Fibbonacci series should be found: -1
*                       The Fibbonacci series till the given number -1 is : 0,1,-1
*                       Do you want to continue (y/Y): y
*
*                       Enter a number till which Fibbonacci series should be found: 2
*                       The Fibbonacci series till the given number 2 is : 0,1,1,2
*                       Do you want to continue (y/Y): y
*
*                       Enter a number till which Fibbonacci series should be found: 0
*                       The 1st element in Fibbonacci series is 0
*                       Do you want to continue (y/Y): n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int pos_fibbo(int,int,int,int);                 //positive and negative fibbonacci series function declaration.
int neg_fibbo(int,int,int,int);

int main()
{
        char character;                        //input variables initialization and declaration.
        int numb,current = 1 ,previous = 0,next = 0,iter,prod = 1;
        printf("\tFIBBONACCI SERIES TILL A GIVEN NUMBER");
        for ( iter = 0; iter < 20; iter++ )    //loop to set range.
        {
            prod *= 2;
        }
    do                                         //loop to continue next cycle.
    {   
        printf("\nEnter a number till which Fibbonacci series should be found: ");  //input fetch.
        scanf("%d",&numb);
        
        if ( numb >= prod || numb <= -prod )                                        //error detection.
            printf("ERROR:Number out of Range!");
        else if ( numb == 0 )
            printf("The 1st element in Fibbonacci series is 0");
        else if( numb > 0 && numb < prod)
        {
            printf("The Fibbonacci series till the given number %d is : ",numb);
            pos_fibbo(numb,current,previous,next);                                  //positive F.S function call.
        }
        else if(numb < 0 && numb > -prod)
        {
            printf("The Fibbonacci series till the given number %d is : ",numb);
            neg_fibbo(numb,current,previous,next);                                  //negative F.S function call.
        } 
        printf("\nDo you want to continue (y/Y): ");                                //input fetch for continuing next cycle.
        scanf(" %c",&character);

    }while( character == 'y' || character == 'Y' );                             //condition for next cycle execution.
return 0;
}

int pos_fibbo ( int num,int current,int previous,int next )     //postive F.S function definition.           
{
        printf("%d",previous);
        next = current + previous;                              //logic to perform PFS.
        previous = current;
        current = next;
        if ( previous <= num )                                  //base condition for recursion.
        {
            printf(",");
            pos_fibbo(num,current,previous,next);               //Recursive function call.
        }
}

int neg_fibbo ( int num,int current,int previous,int next )     //negative F.S function definition.
{
        printf("%d",previous);
        next = previous - current;                              //logic to perform NFS.
        previous = current;
        current = next;

        if ( next < 0 && previous <= -num )                     //base condition for recursion.
        {
                printf(",");
                neg_fibbo(num,current,previous,next);           //recursive function call to Negative FS function.
        }
        else if ( next > 0 && previous >= num )                 //base condition for recursion.
        {
                printf(",");
                neg_fibbo(num,current,previous,next);           //recursive function call to Negative FS function.
        }
}
/********************************************************END OF CODE********************************************************************/
