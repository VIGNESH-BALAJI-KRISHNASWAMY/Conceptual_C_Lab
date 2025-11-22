/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 16/10/2021.
*   Description     : string token function implementation.
*   Input           : ./a.out 
*   Output          :   	IMPLEMENTATION OF STRING TOKEN FUNCTION
*                       Enter String 1 : Banglore;'/]chennai_______kolkatta;;Delhi;-:Mumbai
*                       Enter String 2 : ;'/_]}-:
*                       Tokens:
*                       Banglore
*                       chennai
*                       kolkatta
*                       Delhi
*                       Mumbai
*                       Do you want to continue (y/Y):y
*
*                       Enter String 1 : today is dussehra 
*                       Enter String 2 : is 
*                       Tokens:
*                       today
*                       du
*                       ehra
*                       Do you want to continue (y/Y):n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

char *my_strtok(char *,char*,int);                          //my_strtok function declaration.

int main()
{
    char character;                                         //input variable declaration and initialization.
    int new = 0;
    printf("\tIMPLEMENTATION OF STRING TOKEN FUNCTION");
    
    do                                                      //loop to continue the process.
    {
        char string1[100],string2[100];
        char *ret;
        printf("\nEnter String 1 : ");                      //string and delimiter fetch.
        scanf(" %[^\n]",string1);
        printf("Enter String 2 : ");
        scanf(" %[^\n]",string2);
        
       ret =  my_strtok(string1,string2,new);               //function call and the return address is got into ret from function.

       printf("Tokens:\n");
        while (ret != NULL)                                 //loop to print the sub strings, if present.
        {
            new = 0;                                        //stop the new cycle.
            printf("%s\n",ret);
            ret = my_strtok(NULL,string2,new);              //function call to print the subsequent strings.
        }

        printf("Do you want to continue (y/Y):");           //input fetch for next cycle.
        scanf(" %c",&character);                            
        new = 1;                                            //starting the next new cycle.

    }while(character == 'y' || character == 'Y');
return 0;
}

char *my_strtok( char *string,char *delimiter ,int new)     //my_strtok function definition.
{
    static char *str;           //declaring str as static so that the position address is used for next printable string in current cycle
    static int s_pos;//0        //static integer to store the position of the string.      
    int d_pos = 0,initial = s_pos;

    if( new == 1 )              //checking next new cycle
    {
        s_pos = 0;              //setting string position to initial new string.
        initial = s_pos;
        new = 0;                //stoppin the new cycle till the current cycle is executed.
    }

    if(string != NULL)          //condition to check initil string pos is '\0' or not
        str = string;

    while( *(str + s_pos) != '\0' )                 //loop to iterate between the string positions.
    {
        d_pos = 0;                                  //variable to increment the delimiter position (initial d_pos= 0)
        while( *(delimiter + d_pos) != '\0' )       //loop to iterate between the delimiter positions.
        {
            if( str[s_pos] == delimiter[d_pos] )    //condition to find a match between string and delimiter.
            {
               str[s_pos] = '\0';                   //if found delete the string literal
               s_pos++;                             //increment the string pos.
           
                if( str[initial] != '\0' )          //checking for the presence of valid string present previously. 
                {
                    return (&str[initial]);         //if present then return the address of previous valid string to be printed.
                }
                else
                {
                    initial = s_pos;       //updating the initial to next position to be printed/checked for valid literal in next cycle.
                    s_pos--;               //resetting string position to previous pos. 
                    break;
                }
            }
            d_pos++;                       //incrementing delimiter position for next cycle.
        }
        s_pos++;                           //incrementing string position for next cycle.
    }
    str[s_pos] = '\0';                     //setting last string position to null to prevent the error due to continuous tracing. 
    if( str[initial] != '\0')              //checking for the presence of valid string present previously.
        return &str[initial];
    else
        return NULL;
}
/********************************************************END OF CODE********************************************************************/
