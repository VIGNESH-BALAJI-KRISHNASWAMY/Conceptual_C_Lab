/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 06/10/2021.
*   Description     : An alternative version of squeeze(s1, s2) that deletes each character in s1 that matches any character in the string s2.
*   Input           : ./a.out 
*	output          :   ALTERNATIVE VERSION OF SQUEEZE 
*                       Enter String S1     : Dennis Ritche
*                       Enter String S2     : LiNux
*                       After Squeeze S1    : Denns Rtche
*                       Do you want to continue (y/Y) : y
*
*                       Enter String S1     : Dennis Ritche
*                       Enter String S2     : Linux
*                       After Squeeze S1    : Des Rtche
*                       Do you want to continue (y/Y) : n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

void squeeze( char *,char * );                          //squeeze function declaration.

int main()
{
    char character;                                     //input variable declaration.
    printf("\tALTERNATIVE VERSION OF SQUEEZE ");
    do                                                  //loop to continue the process.
    {
        char str1[100],str2[100];                       //input fetch for string 1 and string 2.
        printf("\nEnter String S1 \t: ");
        scanf(" %[^\n]",str1);
        printf("Enter String S2 \t: ");
        scanf(" %[^\n]",str2);
        squeeze(str1,str2);                             //squeeze function call.
        printf("After Squeeze S1 \t: %s",str1);

        printf("\nDo you want to continue (y/Y) : ");   //input fetch for next cycle.
        scanf(" %c",&character);
    
    }while(character == 'y' || character == 'Y');       //condition for next cycle execution.
}


void squeeze(char *str1,char *str2)                     //squeeze fuction definition.
{
    int count = 0;
    char *base_add_s1;                                  //pointer to store base address of string 1.
    base_add_s1 = str1;

            while(*str2 != '\0')                        //selecting the initial variable from string 2 using loop.
            {
                while(*str1 != '\0')                    //loop to compare each literal from string 1.
                {
                    if( *str1 == *str2 )                //condition to detect the two strings are equal.
                    {
                        while(*str1 != '\0')            //loop to remove the matched literal and shift the position of succedding...
                        {                                       //... literals to its preceeding positions.
                            *str1 = *(str1 + 1);
                            str1++;
                            count++;
                        }
                        str1 = base_add_s1;             //setting str1 to its base address for next iteration.
                    }
                    else
                        str1++;                         //if no match then increment the address of string 1.
                }
                str1 = base_add_s1;                     //setting str1 to its base address for next iteration.
                str2++;                                 //incrementing the base address of str 2 to continue the process.
            }
}
/********************************************************END OF CODE********************************************************************/
