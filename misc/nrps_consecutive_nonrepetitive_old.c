/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Description     : A Program to take n and k (1 <= k <= 10) as inputs. Generate consecutive NRPS of length n using k distinct character (1 <= k <= 9).
*   Date            : 06/10/2021.
*   Input           :./a.out 
*   Output          :   	CONSECUTIVE NON REPEATATIVE PATTERN STRINGS 
*                       Enter the number of distinct characters (C) : 3
*                       Enter the length of the string (N) : 4  
*                       Enter the 3 distinct characters : aac
*
*                       Error : Enter distinct characters
*                       Do you want to continue (y/Y): y
*
*                       Enter the number of distinct characters (C) : 3
*                       Enter the length of the string (N) : 5
*                       Enter the 3 distinct characters : abc
*                       Possible NRPS is abcab
*                       Do you want to continue (y/Y): y
*
*                       Enter the number of distinct characters (C) : 4
*                       Enter the length of the string (N) : 31
*                       Enter the 4 distinct characters : abcd
*                       Possible NRPS is abcdbacdcbaddbcaabcdbacdcbadabc
*                       Do you want to continue (y/Y): y
*
*                       Enter the number of distinct characters (C) : 4
*                       Enter the length of the string (N) : 3
*                       Enter the 4 distinct characters : acdb
*                       Possible NRPS is acd
*                       Do you want to continue (y/Y): n
* 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int check_distinct(char *);                                         //function declaration.
void pattern(char*,int,int,int);
void swap(char*,char*);

int main()
{
    int num,length,count = 0,ret,rem,no_time,iter;                      //input and output variables declaration.
    char character;
    printf("\tCONSECUTIVE NON REPEATATIVE PATTERN STRINGS ");
    
   do                                                                   //loop to continue the process.
   { 
        printf("\nEnter the number of distinct characters (C) : ");     //input fetch.
        scanf("%d",&num);
    
        if ( num > 10 || num <= 1 )                                     //input validation.
            printf("ERROR:Out of Range. correct range: 1 < C <= 10");
        else
        {
            printf("Enter the length of the string (N) : ");
            scanf("%d",&length);
            
            char dist_char[num],NRPS[length];                           //array initialized for given size. 
            printf("Enter the %d distinct characters : ",num);
            for(count = 0; count < num; count++)                        //loop to fetch input.
            {
                scanf(" %c",&dist_char[count]);
            }
            dist_char[count] = '\0';                                    //setting the last element of array with null character.
 
            ret = check_distinct(dist_char);                            //function call to check distinct characters.
            if(ret == 1)                                                
            {
                printf("\nError : Enter distinct characters");
            }
            else
            {
                printf("Possible NRPS is ");
                rem = length % num;
                no_time = length / num;
                pattern(dist_char,num-1,no_time,rem);                   //function call to find the NRPS.

            }
        }
        printf("\nDo you want to continue (y/Y): ");                    //input fetch for next cycle.
        scanf(" %c",&character);
    }while ( character == 'y' || character == 'Y' );
}

void pattern( char *string,int final,int no_time,int rem )              //function definition for finding NRPS.
{
    int iter = 0,pos = 0;
    char *base_address = string;
    while( no_time-- != 0 )                                             //loop to find the quotient iteration patterns.
    {
        if(iter > final)
        {
            iter = 0;
        }
        swap( string, string + iter );                                  //function call to swap required positions.
        printf("%s",string);
        swap( string, string + iter );                         //function call to rearrange the prior swapped positions for next cycle.
        iter++;
        string = base_address;
    }
    while( rem != 0 )                                                   //loop to find the remainder iteration pattern.
    {
        printf("%c",*(string + (char)pos));
        pos++;
        rem--;
        string = base_address;
    }
}

void swap( char *literal1, char *literal2 )                     //function definition for swapping the respective elements in a string.
{
    char temp;
    temp = *literal1;
    *literal1 = *literal2;
    *literal2 = temp;
}


int check_distinct( char *string )                              //function definition to check given characters  are distinct or not.
{
    int count = 0; 
    char *base_address,*iterative;
    base_address = string;
    iterative = string;
    ++iterative;
    while(*base_address != '\0')                                //loop to compare each element with the string's position.
    {
        while(*iterative != '\0')
        {
            if( *base_address == *iterative )
                return 1;
            iterative++;
            count++;
        }
       ++base_address;
        iterative = iterative - (char)count;
        count = 0;
        ++iterative;
    }
    return 0;
}
/********************************************************END OF CODE********************************************************************/
