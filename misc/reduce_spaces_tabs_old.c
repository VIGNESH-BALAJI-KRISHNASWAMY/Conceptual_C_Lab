/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 28/09/2021.
*   Description     : A Program to replace each string of one or more blanks by a single blank.
*   Input           :  ./a.out 
*	Output          :       STRING WITH REDUCED SPACE INBETWEEN THEM
*                       Enter the string with more spaces in between two words 
*                       Distance                    		to				success
*                       Distance to success
*                       Do you want to continue (y/Y): y
*
*                       Enter the string with more spaces in between two words 
*                       			pencils       are   		sharp knives
*                       pencils are sharp knives
*                       Do you want to continue (y/Y): n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
void space_tab();       //space_tab function declaration.

int main()
{
    char character;     //input variable declaration.
    printf("\tSTRING WITH REDUCED SPACE INBETWEEN THEM");
    do                  //loop to continuing the process.
    {
        printf("\nEnter the string with more spaces in between two words \n");
        space_tab();    //function call.

        printf("Do you want to continue (y/Y): ");  //input fetch for next cycle.
        scanf(" %c",&character);
        getchar();                                  //getchar to prevent the intrution of character variable's input into next cycle.
    }while ( character == 'y' || character == 'Y' );//condition for continution of next cycle.
return 0;
}

void space_tab()                                    //space_tab function definition.
{
    char ch,previous = ' ';                         //input variable declaration and definition.
    int set = 0;
    while ( (ch = getchar()) != '\n')               //loop to get characters till a new line by entering ENTER.
    {
        set = 0;                                    //character display key is set to default during start of each cycle.
        
        if (ch  == ' ')                             //condition to detect the present space.
           set = (previous == ' ')?1:0;             //character display key is set to 1, if previous character is space.
        else if ( ch == '\t')                       //condition to detect TAB space.
        {
           ch = ' ';                                //convert TAB space to space. 
           set = (previous == ' ')?1:0;             //character display key is set to 1, if previous character is space
        }
        
        if(set == 0)                                //display the character if set key is 0.
            putchar(ch);

        previous = ch;                              //change the current character to previous character to be used for next cycle.
    }
    printf("\n");
}
/********************************************************END OF CODE********************************************************************/
