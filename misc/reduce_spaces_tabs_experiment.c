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
void space_tab();
int main()
{
    //char previous;
    printf("During Fetching \n");
    space_tab();
return 0;
}

void space_tab()
{
    char ch,previous = ' ';
    int set = 0;
    while ( (ch = getchar()) != '\n')
    {
        set = 0; 
        if ((ch  == ' ') || (ch == '\t'))
        {
            if ( (previous == ' ') || (previous == '\t'))
                set = 1;
            else
                set = 0;
        }
        if(set == 0)
        {
            printf("%c",ch);
            //putchar(ch);
        }
        previous = ch;

    }
    printf("\n");
}
/********************************************************END OF CODE********************************************************************/
