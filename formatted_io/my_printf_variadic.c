/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 10/11/2021. 
*   Description     : WAP to implement my_printf() function.
*   Input           : ./a.out 
*   Output	        :        IMPLEMENTING MY_PRINTF FUNCTION
*                       Enter a number,char,string:
*                       12,e,erty
*                       output : 12 e erty
*                       Successfully printed characters using my_printf :
*                       18
*                       Do you want to continue(y/Y):
*                       y
*                       Enter a number,char,string:
*                       -1234,v,vast
*                       output : -1234 v vast
*                       Successfully printed characters using my_printf :
*                       21
*                       Do you want to continue(y/Y):
*                       n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>                                                      //header file declaration.
#include <stdarg.h>
#include <stdio_ext.h>

int my_printf(const char *format, ...);                                 //my_printf variadic function declaration.

static int count;
char *itoa(int num);                                                    //itoa function declaration.

int main()
{
    char character,*size;
    int success_print,num;

    puts("\tIMPLEMENTING MY_PRINTF FUNCTION");

    do                                                                  //loop to continue the process.
    {
        count = 0;                                                      
        int success_print;
        char *string,chara,*str;
        puts("Enter a number,char,string:");
        scanf("%d %*c %c %*c %s",&num,&chara,str);                      

        my_printf("output : %d %c %s",num,chara,str);                   //my_printf function call.

        size = itoa(count);                                             //itoa function call.
        puts("\nSuccessfully printed characters using my_printf :");
        while( *size != '\0')
        {
            putchar(*size);
            size++;
        }
        puts("\nDo you want to continue(y/Y):");                        //input fetch for next cycle.
        scanf(" %c",&character);
        puts(" ");

    }while( character == 'y' || character == 'Y' );                     //condition for execution of next cycle.
}


int my_printf(const char *format, ...)                                  //my_printf function definition.
{
    va_list ap;                                                         //creating argument pointer ap.
    int num;
    char s,*str;
    const char *iter;

    va_start(ap,format);                                                //ap points to format using va_start.
    {
        for( iter = format; *iter != '\0'; iter++ )
        {
            while(*iter != '%')                                         //condition for execution of characters/wordings.
            {
                putchar(*iter);
                iter++;
                count++;
            }

            if(*iter == '%')                                            //condition for printing formatted datatypes.
            {
                iter++;
                switch(*iter)
                {
                    case 'd':                                           //for integer.
                        num = va_arg(ap,int);
                        str = itoa(num);                                //converting int to string using itoa.
                        while( *str != '\0')                            //loop to print the characters.
                        {
                            putchar(*str);
                            str++;
                            count++;
                        }
                        break;
                    case 'c':                                           //for character.
                        s = va_arg(ap,int);
                        putchar(s);
                        count++;
                        break;
                    case 's':                                           //for string.
                        str = va_arg(ap,char *);
                        while( *str != '\0' )
                        {
                            putchar(*str);
                            str++;
                            count++;
                        }
                        break;
                }
            }
        }
    }
    va_end(ap);
}

char *itoa(int num)                       //function definition for itoa function.
{
  static char array[4];
  int iter;
  for(iter = 0; iter < 4;iter++)
  {
      array[iter] = 0;
  }

    int length = 0,temp = num,set = 0,count;        
    if(num < 0)                                     //condition to detect negative number.
    {
        num *= -1;
        temp = num;
        length++;
        set = 1;
    }
    while ( (num /= 10) != 0)                       //loop to find the number of digits in given number.
    {
        length++;
    }
    count = length + 1;                             
    array[ length + 1 ] = '\0';                    //making last literal in a string as null.
    while (length >= 0)
    {
        array[length] = (temp % 10) + '0';         //converting interger to string and storing in a array.
        temp /= 10;
        length--;
    }
    if (set == 1)                                  //condition to display initial - sign if num is negative. 
    {
        array[0] = '-';
        set = 0;
    }
    return array;                                   //returning base address of array.
}
/********************************************************END OF CODE********************************************************************/
