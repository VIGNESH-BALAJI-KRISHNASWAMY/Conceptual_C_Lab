/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 10/11/2021.
*   Description     : WAP to concatenate two files.
*   Input           :   ./a.out 
*	Output          :           PRINTING FROM STDIN BUFFER
*                       USAGE: <press Ctrl + d to stop> <press Enter to flush the buffer>
*                       wedjlcnc
*                       wedjlcnc
*                       kwdncqkc
*                       kwdncqkc
*   Input           :   ./a.out viki.txt
*   Output          :	        PRINTING CONTENTS OF FILE1 : viki.txt 
*                       Contents of FILE1 :< viki.txt > 
*                       123
*   Input           :   ./a.out viki.txt j.txt
*   Output          :	        PRINTING CONTENTS OF FILE1 : < viki.txt > AND FILE2 : < j.txt >
*                       Contents of FILE1 :< viki.txt >
*                       123
*                       Contents of FILE2 :< j.txt >
*                       123
*   Input           :   ./a.out viki.txt ba.txt j.txt
*   Output          :	COPYING CONTENTS OF FILE1 : < viki.txt >  AND FILE2 : < ba.txt > IN FILE3 : j.txt
*                       Copied contents of file < viki.txt > in file3 < j.txt >
*                       Copied contents of file < ba.txt > in file3 < j.txt >
*   Input           :   ./a.out gst.txt sgst.txt cgst.txt
*   Output          :	COPYING CONTENTS OF FILE1 : < gst.txt >  AND FILE2 : < sgst.txt > IN FILE3 : cgst.txt
*                       ERROR: Source file < gst.txt > missing
*                       ERROR: Source file < sgst.txt > missing
*
********************************************************START OF CODE********************************************************************/
#include <stdio.h>                                      //header files.
#include <stdlib.h>


void my_file_copy(char *,char *,int);                   //common file copy function declaration.

int main(int argc,char *argv[],char *envp[])            //main function with CLA's as parameters.
{
    char ch,*character;                                 //input variables and file pointer declaration.
    FILE *fptr;
    if(argc == 1)
    {
        printf("\n\tPRINTING FROM STDIN BUFFER\nUSAGE: <press Ctrl + d to stop> <press Enter to flush the buffer>\n");

            while( (ch = fgetc(stdin)) != EOF )         //printing the stdin buffer content into std buffer output.
            {
                fputc(ch,stdout);
            }
    }
    else if(argc == 2)                                  
    {
        printf("\n\tPRINTING CONTENTS OF FILE1 : %s ",argv[1]);
        
        printf("\nContents of FILE1 :< %s > \n",argv[1]);
        my_file_copy(argv[1],NULL,0);                       //function call to print file 1 content into stdout buffer.
    }
    else if(argc == 3)
    {
        printf("\n\tPRINTING CONTENTS OF FILE1 : < %s > AND FILE2 : < %s >\n",argv[1],argv[2]);
        
        printf("\nContents of FILE1 :< %s >\n",argv[1]);
        my_file_copy(argv[1],NULL,0);                      //function call to print file 1 content into stdout buffer.
        
        printf("\nContents of FILE2 :< %s >\n",argv[2]);
        my_file_copy(argv[2],NULL,0);                      //function call to print file 2 content into stdout buffer.
    }
    else if(argc == 4)
    {
        int filenum = 0;
        printf("\n\tCOPYING CONTENTS OF FILE1 : < %s >  AND FILE2 : < %s > IN FILE3 : %s\n",argv[1],argv[2],argv[3]);
        my_file_copy(argv[1],argv[3],filenum);             //function call to print file 1 content into file 3.
        my_file_copy(argv[2],argv[3],++filenum);           //function call to print file 2 content into file 3.
        
    }
}

void my_file_copy(char *ptr1,char *ptr2,int filenum)        //file copying function definition.
{
    char ch;
    FILE *fptr,*fptr1;
    fptr = fopen(ptr1,"r");                                 //opening file 1 in read mode.
    if(fptr == NULL)                                        //condition to detect the non existence of file.
    {
        printf("\nERROR: Source file < %s > missing\n",ptr1);
    }
    else
    {
        if ( ptr2 == NULL  )
        {
            if( ptr2 == NULL && fptr != NULL )
            {
                 while( (ch = fgetc(fptr)) )            
                {
                    if( feof(fptr) )
                        break;
                    fputc(ch,stdout);                           //copying content of given file into stdout buffer.
                }
                fclose(fptr);
            }
        }
        else
        {
            if ( filenum == 0 )
                fptr1 = fopen(ptr2,"w");                        //opening file 3 in write mode.
            else
                fptr1 = fopen(ptr2,"a");                        //opening file 3 in append mode for second time.

            if( fptr1 == NULL )
            {
                printf("\nERROR: Source file < %s > missing\n",ptr2);
            }
            else
            {
                while( (ch = fgetc(fptr)) )
                {
                    if( feof(fptr) )
                        break;
                    fputc(ch,fptr1);                            //copying content of file 1 and file 2 to file 3.
                }
                
                fclose(fptr);                                   //closing files.
                fclose(fptr1);
                    printf("\nCopied contents of file < %s > in file3 < %s >\n",ptr1,ptr2);
            }
        }
    }
}
/********************************************************END OF CODE********************************************************************/
