/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 10/11/2021.
*   Description     : A Program to implement my_scanf() function.
*   Input           : ./a.out 
*   Output          :   	 IMPLEMENTING MY_SCANF FUNCTION
*                       Enter a Integer number : 1
*                       You entered 1
*                       Enter a character : 1
*                       You entered 1
*                       Enter a string : sai sai
*                       You entered sai
*                       Enter a Float number : -12.234
*                       You entered -12.233999
*                       Enter a double number : -12.234
*                       You entered -12.234
*                       Do you want to continue (y/Y):y
*
*                       Enter a Integer number : 12
*                       You entered 12
*                       Enter a character : w
*                       You entered w
*                       Enter a string : wesr
*                       You entered wesr
*
*                       Enter a Float number : 12.2345
*                       You entered 12.234499
*                       Enter a double number : -123.456
*                       You entered -123.456
*                       Do you want to continue (y/Y):n
*                                     
********************************************************START OF CODE********************************************************************/

#include <stdio.h>                                              //Header files declaration.
#include <stdlib.h>
#include <stdio_ext.h>
#include <stdarg.h>

double my_atod(const char *string);
float my_atof(const char *string);                              //atoi,atof,atod function definition.
int my_atoi(const char *string);
void string_null(char *);

int my_scanf(const char *format, ...);                          //scanf function declaration as variadic function.
char *_char;                                                    //pointer variable declaration.
int *num;
float *f_num;
double *d_num;

int main()                                                      
{
    int val;
    char character;
    printf("\t IMPLEMENTING MY_SCANF FUNCTION");

    do                                                          //loop to continue the process.
    {
        printf("\nEnter a Integer number : ");
        my_scanf("%d",num);
        printf("You entered %d",*num);


        printf("\nEnter a character : ");
        my_scanf("%c",_char);
        printf("You entered %c",*_char);

        printf("\nEnter a string : ");
        my_scanf("%s",_char);
        printf("You entered %s",_char);

        printf("\nEnter a Float number : ");
        my_scanf("%f",f_num);
        printf("You entered %f",*f_num);
        
        printf("\nEnter a double number : ");
        my_scanf("%e",d_num);
        printf("You entered %lg",*d_num);
        
        printf("\nDo you want to continue (y/Y):");
        my_scanf("%c",_char);                                   //input fetch for continuing the process.
    }while( *_char == 'y' || *_char == 'Y');                    //condition for continuing the process.
}

int my_scanf(const char *format, ...)                           //my_scanf function definition.
{
    va_list ap;                                                 //argument pointer variable declaration.

    char arr[10000];                                            //array to fetch input as string.
    int *iptr;
    int number;
    float *fptr;
    float f_number;
    double *dptr,d_number;
    char *cptr,character;

    va_start(ap,format);                                        //pointer ap pointing to format.

    while(*format == '%')                                       //condition for next format detection.
    {
        format++;
        switch(*format)                                         //switch to identify the type of format.
        {
            case 'd':                                           //for integer.
                iptr = va_arg(ap,int *);
                fgets(arr,11,stdin);
                number = my_atoi(arr);                          //calling atoi function.
                num = &number;
                break;
            case 'c':                                           //for character.
                fgets(arr,3,stdin);
                _char = arr;
                break;
            case 's':                                           //for string.
                fgets(arr,100,stdin);
                _char = arr;
                string_null(_char);
                break;

            case 'f':                                           //for float.
                fptr = va_arg(ap,float *);
                fgets(arr,32,stdin);
                f_number = my_atof(arr);                        //calling atof function.
                f_num = &f_number;
                break;
            
            case 'e':                                           //for double.
                dptr = va_arg(ap,double *);
                fgets(arr,1023,stdin);
                d_number = my_atod(arr);
                d_num = &d_number;
                break;
        }
    }

}

void string_null(char *string)                      //string function to find the ending.
{
    while(*string != ' ' && *string != '\0')
    {
        string++;
        if(*string == ' ')
        {
            *string = '\0';
            break;
        }
    }
}


int my_atoi(const char *string)                        //atoi function definition.
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

float my_atof(const char *string)                   //function to convert string to float.
{
    float neg_flag = 0,sum = 0;
    float decimal = 1,real_part = 0;
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
    while(*string != '\n')                                  //condition to detect numbers
    {
        if(real_part == 1)
        {
            if( *string >= '0' && *string <= '9' )
            {
                decimal = decimal/10;
                sum = sum + (*string - '0') * decimal;
                *string++;
            }
            else
                break;
        }
        else if(real_part == 0)
        {
            if( *string == '.')
            {
                real_part = 1;
            }
            else if( *string >= '0' && *string <= '9' )
            {
                sum = (sum * 10) + (*string - '0');
            }
            else
                break;
            *string++;
        }
    }
    if ( sum == 0 )
        return 0;
    else
        return neg_flag?sum * neg_flag:sum;             //returning positive or negative number in float form.
}

double my_atod(const char *string)                      //function to convert string to double.
{
    double neg_flag = 0,sum = 0;
    double decimal = 1,real_part = 0;
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
    while(*string != '\n')
    {
        if(real_part == 1)
        {
            if( *string >= '0' && *string <= '9' )
            {
                decimal = decimal/10;
                sum = sum + (*string - '0') * decimal;          //condition to detect the decimal part.
                *string++;
            }
            else
                break;
        }
        else if(real_part == 0)
        {
            if( *string == '.')
            {
                real_part = 1;
            }
            else if( *string >= '0' && *string <= '9' )
            {
                sum = (sum * 10) + (*string - '0');
            }
            else
                break;
            *string++;
        }
    }
    if ( sum == 0 )
        return 0;
    else
        return neg_flag?sum * neg_flag:sum;             //returning positive or negative number in double format.
}
/********************************************************END OF CODE********************************************************************/
