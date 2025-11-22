/**************************************************************************************************************************************

Name            :
Date            :
Description     : Two power respective for the given number of iteration.
Input           :
Output          :

 ***************************************************************************************************************************************/
#include<stdio.h>

int main ()
{
    int num,iter,prod=1;
    printf("\t2's POWER \nEnter the maximun number till which 2's power should be found: ");
    scanf("%d",&num);
    for(iter=0; iter < num; iter++)
    {
        prod=prod*2;
        printf("%d\n",prod);
    }

}
