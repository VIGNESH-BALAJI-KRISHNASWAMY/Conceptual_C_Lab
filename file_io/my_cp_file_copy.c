/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 10/11/2021.
*   Description     : Implement a my_cp() function.
*   Input           :   ./a.out 
*   Output          :       IMPLEMENTING A MY_COPY() FUNCTION
*
*                        ERROR!Filenames not passed.
*                        
*   Input           :   ./a.out a.txt b.txt
*   Output          :       IMPLEMENTING A MY_COPY() FUNCTION
*
*                        a.txt:ERROR!Source File does not exists.
*                        
*   Input           :   ./a.out viki.txt
*   Output          :       IMPLEMENTING A MY_COPY() FUNCTION
*
*                        Destination file missing.
*
*   Input           :   ./a.out viki.txt ba.txt
*   Output          :       IMPLEMENTING A MY_COPY() FUNCTION
*
*                        Data copied successfully
* 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>                                                        //header file inclusion.

int main(int argc,char *argv[])                                           //passing CLA's as parameters to main function.
{

    char ch;
    printf("\tIMPLEMENTING A MY_COPY() FUNCTION\n");

    FILE *fptr,*f_cpy;                                                    //file pointer declaration.

    if( argc == 1 )                                                       //condition to detect no files passed through Command line.
    {
        printf("\nERROR!Filenames not passed.\nUSAGE: ./a.out<SPACE>existing source file<SPACE>existing or non-existing destination file >");
    }
    else if( argc == 2)                                                   //condition to point out missing destination file.
    {
        printf("\nDestination file missing.\nUSAGE: ./a.out<SPACE>present source file<SPACE>existing or absent destination file >");
    }
    else
    {
        fptr = fopen(argv[1],"r");                                        //opening source file in read mode.
        
        if( fptr == NULL )                                                //detecting non-existence of ource file.
        {
            printf("\n%s:ERROR!Source File does not exists.\nUSAGE: ./a.out<SPACE>EXISTING source file<SPACE>existing or non-existing destination file >",argv[1]);
        }
        else if(ferror(fptr))                                             //detecting error in reading file.
        {
            fprintf(stderr, "Error in reading from file\n");
        }
        else
        {
            
            f_cpy = fopen(argv[2],"w");                                   //opening destination file in write mode.
            
            while ( ch = fgetc(fptr) )                                    //data copying from source to destination.
            {
                if ( feof(fptr) )
                    break;
                fputc(ch,f_cpy);
            }
            fclose(fptr);                                                 //closing both files.
            fclose(f_cpy);
            printf("\nData copied successfully\n");
        }
    }
return 0;
}
/********************************************************END OF CODE********************************************************************/
