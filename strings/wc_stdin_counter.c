/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 24/09/2021.
*   Description     : A program to count number of characters, words and lines, entered through stdin buffer.
*   Input           :  ./a.out 
*   Output          :              FUNCTION TO PERFORM WC COMMAND
*                       Write a message (After Completion press Ctrl + d to display length): 
*                       Hello                  my
*                                  friends
*
*                       Character count  :41
*                       Line count  	 :2
*                       Word count	     :3
*                       Do you want to continue (y/Y):y
*
*                       Write a message (After Completion press Ctrl + d to display length): 
*                       Hello                  my
*                                  friends
*                       Character count  :40
*                       Line count	 :1
*                       Word count	 :3
*                       Do you want to continue (y/Y):n
*                                      
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    char ch,previous,character;                             //input variable declaration and initialization.
    int word_count = 0,character_count = 0,line_count = 0;  
    printf("\tFUNCTION TO PERFORM WC COMMAND");
    
    do                                                      //loop to continue the process.
    {
        printf("\nWrite a message (After Completion press Ctrl + d to display length): \n");
        previous = getchar();                   //getting a character priorly to compare with next variable to detect blank spaces, ...
        character_count++;                       //...next words, and new line.
        word_count = 1;
        
        while((ch = getchar()) != EOF )         //loop to get the characters till reaching End of file.
        {
            character_count++;                  //incrementing character count for getting each character.
            
            if( ch == '\n' )                    //incrementing line count for each new line.
                line_count++;

            if(ch == ' ' || ch == '\t' || ch == '\n')  //comparing spaces,tabs and new lines of present and previous character to... 
            {                                                                   //...increment the word count
                word_count++;
                if(previous == ' ' || previous == '\t' || previous == '\n')  // if there is continuous space,tabs or new lines...
                    word_count--;                                              //...then decrement the previously incremented word count.
            }
            previous = ch;                      //assign current character to previous character for next iteration till EOF is achieved.
        }
        
        if ( previous == '\n' )     //condition to check for a new word after EOF is achieved in a new line.
        {
            word_count--;
        }
        
        printf("\nCharacter count  :%d\nLine count\t :%d\nWord count\t :%d\n",character_count,line_count,word_count);

        printf("Do you want to continue (y/Y):");          //input fetch for next cycle.
        scanf(" %c",&character);
        getchar();                     //getchar to prevent the incrementing of character value for next cycle during input fetch.
        word_count = 0;character_count = 0;line_count = 0; //reinitializing variables for next cycle.

    }while ( character == 'y' || character == 'Y' );  //condition for continuing next cycle. 
return 0;
}
/********************************************************END OF CODE********************************************************************/
