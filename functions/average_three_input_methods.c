/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 20/10/2021.
*   Description     : Average of n numbers by taking input in 3 different ways
*   Input           : export arr=1,2,3,4,5,6,7,8
*                     ./a.out 
*	Output          :    AVERAGE OF N NUMBERS BY TAKING INPUT IN 3 DIFFERENT WAYS
*                     Select the method to calculate average:
*                     1.Scan from keyboard.
*                     2.Proceed with environment variable arguments.
*                     3.Proceed with environment variable arguments.
*                     Enter your choice			:3
*                     The average of entered numbers		:4.5
*   Input           :./a.out 1 2 3 4
*   Output          :   	 AVERAGE OF N NUMBERS BY TAKING INPUT IN 3 DIFFERENT WAYS
*                       Select the method to calculate average:
*                       1.Scan from keyboard.
*                       2.Proceed with environment variable arguments.
*                       3.Proceed with environment variable arguments.
*                       Enter your choice			:2
*                       The average of entered numbers		:2.5
*                                                            
********************************************************START OF CODE********************************************************************/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

double average(double *,int);           //function declarations for atoi,average and strtok functions.                  
int atoi(const char *);
char *my_strtok( char *,char *);

int main(int argc,char *argv[],char *envp[])    //main function with argument counts,argument variables,environmental variables as arg's.
{
    printf("\t AVERAGE OF N NUMBERS BY TAKING INPUT IN 3 DIFFERENT WAYS");
    char character;
    int choice;

        printf("\nSelect the method to calculate average:\n1.Scan from keyboard.");             //input fetch for choice selection.
        printf("\n2.Proceed with environment variable arguments.");
        printf("\n3.Proceed with environment variable arguments.\nEnter your choice\t\t\t:");
        scanf("%d",&choice);

        switch(choice)                                      //switch case to select the method of finding average.
        {
            case 1:
                {
                    int size;
                    int iter = 0;
                    printf("Enter the total number of integers\t:");    //fetching the array size.
                    scanf("%d",&size);
                    double array[size],ret;                             //declaring array with size.
                    printf("Enter the elements\t\t\t\t:");
                    while(iter < size)                                  //loop to fetch the input array elements.
                    {
                        scanf("%le",&array[iter]);
                        iter++;
                    }
                    ret = average(array,size);                          //function call to find the average of given array elements.
                    printf("The average of entered numbers\t\t\t:%lg\n",ret);
                }
                break;
            case 2:
                {
                    int iter;
                    double ret,sum = 0,average;
                    for(iter = 1; iter < argc; iter++)                  //loop to find the sum of elements pointed by argument vector.
                    {
                        ret = atoi(argv[iter]);                     //function call to change the ascii characters of argv[i] to integer.
                        sum += ret;
                    }
                    average = sum/(argc - 1);                       //finding average.
                    printf("The average of entered numbers\t\t:%lg\n",average);
                }
                break;
            case 3:
                {
                    double ret,sum = 0,average,count = 0;
                    char *delimiter = ",[] ";                 //setting the delimiter.
                    char *ptr,*str;
                    ptr = getenv("arr");
                    str =  my_strtok(ptr,delimiter);       //function call and the return address is got into ret from function.
                    ret = atoi(ptr);                       //function call to convert string to integer.
                    count++;
                    while (str != NULL)                     //loop to print the sub strings, if present.
                    {
                        sum += ret;
                        str = my_strtok(NULL,delimiter);    //function call to print the subsequent strings.
                        if(str != NULL)
                            ret = atoi(str);                //subsequent function call to convert string to integer.
                        count++;
                    }
                    average = sum/(count - 1);              //finding average.
                    printf("The average of entered numbers\t\t:%lg\n",average);
                }
                break;
        }
return 0;
}

double average(double *pointer,int num)             //function to find an average of array pointed by pointer.
{
    int iter;
    double sum = 0,average;
    for(iter = 0; iter < num; iter++)               //loop to find sum.
    {
        sum += pointer[iter];
    }
    average = (double)sum/(double)num;              //finding average.
    return average;
}

int atoi(const char *string)                        //atoi function definition.
{
    int neg_flag = 0,sum = 0;
    if ( *string == '-' )                           //condition to detect negative number.
    {
        neg_flag--;
        *string++;
    }
    else if ( *string == '+')                       //condition to detect positive sign.
    {
        neg_flag = 0;
        *string++;
    }
    while(*string)                                  //condition to detect numbers
    {
        if( *string >= '0' && *string <= '9' )
        {
            sum = (sum * 10) + (*string - '0');
            *string++;
        }
        else
            break;
    }
    return neg_flag?sum * neg_flag:sum;             //returning positive or negative number.
}

char *my_strtok( char *string,char *delimiter)     //my_strtok function definition.
{
    static char *str;           //declaring str as static so that the position address is used for next printable string in current cycle
    static int s_pos;//0        //static integer to store the position of the string.      
    int d_pos = 0,initial = s_pos;

    if(string != NULL)                                    //condition to check initil string pos is '\0' or not
        str = string;

    while( *(str + (char)s_pos) != '\0' )                 //loop to iterate between the string positions.
    {
        d_pos = 0;                                        //variable to increment the delimiter position (initial d_pos= 0)
        while( *(delimiter + (char)d_pos) != '\0' )       //loop to iterate between the delimiter positions.
        {
            if( str[(char)s_pos] == delimiter[(char)d_pos] )    //condition to find a match between string and delimiter.
            {
               str[(char)s_pos] = '\0';                   //if found delete the string literal
               s_pos++;                                   //increment the string pos.
           
                if( str[initial] != '\0' )                //checking for the presence of valid string present previously. 
                {
                    return (&str[initial]);              //if present then return the address of previous valid string to be printed.
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
