/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 01/09/2021 
*   Description     : A Program to print the Decimal numbers from 0 to 127 in Octal, Hexadecimal and in ASCII representation.
*   Input           : ./a.out 
*   Output          :PRINTING ALL DECIMAL NUMBERS IN OCTAL,HEXADECIMAL AND ASCII REPRESENTATION
		                    Dec	    Oct	    Hex	    Ascii
		                    ----	----	----	------------------
                    		0	    0	    0	    Non Printable
	                 ------------------------------------------------- 
		                    1	    1	    1	    Non Printable
	                 ------------------------------------------------- 
		                    2	    2	    2	    Non Printable
	                 ------------------------------------------------- 
                     .
                     .
                     .                     
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int iteration;   //declaration of variable

    printf("PRINTING ALL DECIMAL NUMBERS IN OCTAL,HEXADECIMAL AND ASCII REPRESENTATION");   //printing the Headings.
    printf("\n\t\tDec\tOct\tHex\tAscii");
    printf("\n\t\t----\t----\t----\t------------------");
    for ( iteration = 0; iteration < 128; iteration++ )                     //loop to iterate between characters 0to 127
    {
       
        if ( iteration == 32 )                                        //condition to make displayable 31 ASCII character to be diplayed.
        
            printf("\n\t\t%d\t%o\t%X\tSPACE",iteration,iteration,iteration);

        else if ( iteration > 32 && iteration < 127  )                      //condition to display all displayable character
        
            printf("\n\t\t%d\t%o\t%X\t%c",iteration,iteration,iteration,iteration);
        
        else
            printf("\n\t\t%d\t%o\t%X\tNon Printable",iteration,iteration,iteration);//condition to display non-diaplayabe ASCII characters

        printf("\n\t ------------------------------------------------- "); //for readability.
    }
    printf("\n");
return 0;
}
/********************************************************END OF CODE********************************************************************/
