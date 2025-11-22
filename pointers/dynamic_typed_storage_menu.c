/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 10/10/2021.
*   Description     : A Program to provide a menu to manipulate or display the value of variable of type t (input) & indexed at i (i/p)
*   Input           :   ./a.out 
*   Output          :       DYNAMIC MANIPULATION AND DISPLAYING VALUE OF A VARIABLE 
*                       Menu:
*                       1. Add element
*                       2. Remove element
*                       3. Display element
*                       4. Exit from the program
*
*                       Choice ---> 1
*
*                       Enter the type you have to insert:
*                       1.int
*                       2.char
*                       3.short
*                       4.float
*                       5.double
*
*                       Choice --->1
*
*                       Enter the int : 21
*
*                       Menu:
*                       1. Add element
*                       2. Remove element
*                       3. Display element
*                       4. Exit from the program
*
*                       Choice ---> 1
*
*                       Enter the type you have to insert:
*                       1.int
*                       2.char
*                       3.short
*                       4.float
*                       5.double
*
*                       Choice --->2
*
*                       Enter the char : e
*
*                       Menu:
*                       1. Add element
*                       2. Remove element
*                       3. Display element
*                       4. Exit from the program
*
*                       Choice ---> 2
*
*                       [0] ->  21 	(int)
*                       [1] ->  e 	(char)
*                       Enter the index value to be deleted :0
*                       Index 0 successfully deleted.
*
*                       Menu:
*                       1. Add element
*                       2. Remove element
*                       3. Display element
*                       4. Exit from the program
*
*                       Choice ---> 1
*
*                       Enter the type you have to insert:
*                       1.int
*                       2.char
*                       3.short
*                       4.float
*                       5.double
*
*                       Choice --->2
*
*                       Enter the char : d
*
*                       Menu:
*                       1. Add element
*                       2. Remove element
*                       3. Display element
*                       4. Exit from the program
*
*                       Choice ---> 3
*                       ___________________________________
*
*                       [0] ->  e 	(char)
*                       [1] ->  d 	(char)
*                       ___________________________________
*                       Menu:
*                       1. Add element
*                       2. Remove element
*                       3. Display element
*                       4. Exit from the program
*
*                       Choice ---> 4
*                       Exiting Program!
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>                                                  //header file declarations.                                     
#include <stdlib.h>
#include <stdio_ext.h>

void lining(int,char *);                                            //function declaration.
void select_menu(void *,int *,char **);
void insert_element(void *,int,int,char *,int *,char **);
void display_element(void *,int *,char **);
int remove_element(void *,int *,char *,char **,int);
void swap_arr_pos(int *,char **,int, int);

static int count,remove_count;                             //conditional variable to count the inserting and removing a data.
static int exit_fun;                                       //conditional variable to exit the program.
static int enter,rem_enter_0,rem_enter_1,pos;              //conditional variable to select the position of char in display function
static int mem_set,mem_reset,set,master_set;               //condtional varibles to select b/w int,float and double.

int main()
{
    printf("\tDYNAMIC MANIPULATION AND DISPLAYING VALUE OF A VARIABLE ");
    static void *vptr;
    vptr = (char *) calloc(8,1);                                    //assigning 1 byte of memory to the void pointer vptr only one time.
    int array[5];                                                   //array to hold the orderwise current element positions.
    char *str_arr[5];                                               //array to hold the orderwise current names of datatypes.
    
    do                                                              //loop to continue the process.
    {
        printf("\nMenu:");
        printf("\n1. Add element\n2. Remove element\n3. Display element\n4. Exit from the program\n");
        select_menu(vptr,array,str_arr);                            //function call to select menu.
    }while(exit_fun == 0);                                          //condition for next cycle execution.
}

void select_menu(void *vptr,int *array,char **str_arr)              //select menu function definition.
{
    int choice;
    printf("\nChoice ---> ");
    __fpurge(stdin);
    scanf("%d",&choice);

    switch(choice)                                                  //switch case to select the operation to perform.
    {
        char *string;
        case 1:                                                     //case to Insert element. 
            {
                int choice;
                printf("\nEnter the type you have to insert:\n1.int\n2.char\n3.short\n4.float\n5.double\n");
                printf("\nChoice --->");
                scanf("%d",&choice);

                switch(choice)                                      //switch case to select the particular datatype.
                {
                    case 1:
                        string = "int";
                        if(mem_reset == 0)
                        {
                            mem_set = 1;
                            set = 1;
                            insert_element(vptr,sizeof(int),0,string,array,str_arr);    //calling inserting function.
                        }
                        else
                            printf("\nThe position for %s is not free.\nRemove the content stored.\n",string);
                        break;
                    case 2:
                        string = "char";
                        set = 1;
                        insert_element(vptr,sizeof(char),6,string,array,str_arr);
                        break;
                    case 3:
                        string = "short";
                        set = 1;
                        insert_element(vptr,sizeof(short),4,string,array,str_arr);
                        break;
                    case 4:
                        string = "float";
                        set = 1;
                        if(mem_set == 0)
                        {
                            mem_reset = 1;
                            insert_element(vptr,sizeof(float),0,string,array,str_arr);
                        }
                        else
                            printf("\nThe position for %s is not free.\nRemove the content stored.\n",string);
                        break;
                    case 5:
                        string = "double";
                        if(remove_count >= 0)
                            set = 0;
                        if(set == 0)
                        {
                            insert_element(vptr,sizeof(double),0,string,array,str_arr);
                            master_set = 1;
                        }
                        else
                            printf("\nThe position for %s is not free.\nRemove the content stored.\n",string);
                        break;
                }
            }
            break;
        case 2:                                                                 //case to remove a particular element.
            {
                int ret;
                display_element(vptr,array,str_arr);                            //dispay function call.
                if(count == 0 && ret >= 0)
                {
                    printf("\nNo elements present to remove!\n");
                }
                else 
                {
                    printf("\nEnter the index value to be deleted :");
                    scanf("%d",&pos);
                    if(pos > count - 1)
                        printf("Invalid Index Value!\n");
                    else
                    {
                        ret = remove_element(vptr,array,string,str_arr,pos);    //remove_element function call.
                        if(ret < 0 && count > 0)
                            printf("Index %d successfully deleted.\n",pos);
                        else if(ret <= 0 && count == 0)
                            printf("Index %d successfully deleted.\n",pos);
                    }
                }
            }
            break;
        case 3:                                                                 //case to display the present elements.
            lining(35,"up");                                                    //lining function call, for display purpose 
            if(count == 0)
                printf("\nStorage is free!\n");
            display_element(vptr,array,str_arr);                                //display_element function call.
            lining(35,"down");
            break;
        case 4:                                                                 //case to exit the program.
            exit_fun = 1;
            free(vptr);                                                         //freeing the void pointer.
            printf("Exiting Program!\n");
            break;
    }
}

void insert_element(void *vptr,int size,int position,char *string,int *array,char **str_arr)        //insert element function.
{
    int iter;
    static char *base_address;
    base_address = (char*)vptr;                                                                     //storing base address of vptr.

    if(string == "char")             //condition to increment the char position if already a char is stored.
    {
       if ( ((*((char *)vptr + (char)position) != 0)) && position == 6 )
       {
           position++;
           rem_enter_1 = 1;
       }
    }
    if( *((char *)vptr + (char)position) == 0 &&  *((short *)vptr + (char)position) == 0 && master_set == 0) //condition to check emptiness. 
    {
        printf("\nEnter the %s : ",string);                 //input fetch for int,char,float and double.
        if(string == "char")
        {
            if(scanf(" %c",((char *)vptr + position)) == 1)
            {
                array[count] = position;                        //storing the current position in the array.
                str_arr[count] = string;                        //storing the current name of datatype int the current positon.
                count++;                                        //incrementing insert count.
                remove_count--;                                 //decrementing the remove count.
                rem_enter_0 = 1;
            }
            else
                printf("\nWarning:Invalid Character type!");
        }
        else if(string == "int")                            //if integer.
        {
            if(scanf("%d",(int *)vptr) == 1)
            {    
                array[count] = position;
                str_arr[count] = string;
                count++;
                remove_count--;
            }
            else
                printf("\nWarning:Invalid Integer type!");
        }
        else if(string == "float")                          //if float.
        {
            if(scanf("%f",((float *)vptr + (char)position)) == 1)
            {
                array[count] = position;
                str_arr[count] = string;
                count++;
                remove_count--;
            }
            else
                printf("\nWarning:Invalid Float type!");
        }
        else if(string == "short")                          //if short.
        {
            if(scanf("%hd",((short *)vptr + (char)position)) == 1)
            {
                array[count] = position;
                str_arr[count] = string;
                count++;
                remove_count--;
            }
            else
                printf("\nWarning:Invalid Short type!");
        }
        else if(string == "double")                         //if double.
        {
            if(scanf("%le",((double *)vptr + (char)position)) == 1)
            {
                array[count] = position;
                str_arr[count] = string;
                count++;
                remove_count--;
            }
            else
                printf("\nWarning:Invalid Double type!");
        }
        vptr = (char*)base_address;                         //assigning the base address to vptr.
    }
    else
    {
        printf("The position for %s is not free.\nRemove the content stored.\n",string);
    }
}

void display_element(void *vptr,int *array,char **str_arr)      //display element function definition.
{
    static char *base_address;
    int disp_count = 0;
    int iter = 0;
    base_address = (char *)vptr;
    enter = 0;

    for(iter = 0; iter < count; iter++)                         //loop to traverse between the 8 bits of vptr.
    {
        if ( str_arr[iter] == "int" && *((int *)vptr + (char)0) != 0  && mem_set == 1)  //condition to display about particular position in a byte.
        {
            printf("\n[%d] -> % d \t(int)",disp_count,*((int*)vptr + 0));
            disp_count++;
        }

        else if ( str_arr[iter] == "float" && *((float *)vptr + (char)0) != 0 && mem_reset == 1 )
        {
            printf("\n[%d] -> % f \t(float)",disp_count,*((float*)vptr + (char)0));
            disp_count++;
            vptr = base_address;
        }

        else if ( str_arr[iter] == "short" && *((short *)vptr + (char)4) != 0  )
        {
            printf("\n[%d] -> % hd \t(short)",disp_count,*((short*)vptr + (char)4));
            disp_count++;
            vptr = base_address;
        }

        else if ( str_arr[iter] == "char" && enter == 0 && rem_enter_0 == 1 && array[iter] != 7 && *((char *)vptr + (char)6) != '\0')
        {
            printf("\n[%d] ->  %c \t(char)",disp_count,*((char*)vptr + (char)6));
            disp_count++;
            vptr = base_address;
            enter = 1;
        }
    
        else if ( str_arr[iter] == "char" && *((char *)vptr + (char)7) != '\0' && rem_enter_1 == 1)
        {
            printf("\n[%d] ->  %c \t(char)",disp_count,*((char*)vptr + (char)7));
            disp_count++;
            vptr = base_address;
        }
        
        else if ( str_arr[iter] == "double" && *((double *)vptr + (char)0) != '\0')
        {
            printf("\n[%d] -> %lg \t(double)",disp_count,*((double*)vptr + (char)0));
            disp_count++;
            vptr = base_address;
        }
    }
}



int remove_element(void *vptr,int *array,char *string,char **str_arr,int pos)           //remove function definition.
{
    if(remove_count > 0)            //condition to detect that there is no element to remove further.
    {
        remove_count = 0;
        count = 0;
    }

    static char *base_add;
    base_add = (char *)vptr;

    if( count >= 0  )
    {
        vptr = base_add;
        switch(array[pos])        //removing the particular position using the indexing of array position and name stored at the array index.
        {
            case 0:
                if(str_arr[pos] == "int")
                {
                   *((int*)vptr + 0) = '\0';                        //removing the integer.
                   array[pos] = 0;
                   (int *)vptr + (char)(array[(char)pos + (char)1]);
                   mem_set = 0;
                   mem_reset = 0;
                   swap_arr_pos(array,str_arr,pos,count);           //swap function call to change the previous array index names and positions. 
                   count--;                                         //decrementing the inserting count.
                   remove_count++;                                  //incrementing the removing count.
                   return remove_count;
                }
                if(str_arr[pos] == "float")                         //removing the float.
                {
                    *(float*)vptr = '\0';
                    array[pos] = 0;
                    (float *)vptr + (char)(array[(char)pos + (char)1]);
                    mem_reset = 0;
                    mem_set = 0;
                     swap_arr_pos(array,str_arr,pos,count);
                     count--;
                     remove_count++;
                     return remove_count;
                }
                if(str_arr[pos] == "double")                        //removing the double.
                {
                    *(double*)vptr = '\0';
                    array[pos] = 0;
                    master_set = 0;
                    (double *)vptr + (char)(array[(char)pos + (char)1]);
                     count--;
                     remove_count++;
                     return remove_count;
                }
                break;
            case 4:
                *((short*)vptr + (char)4) = '\0';                   //removing the short.
                (short *)vptr + (char)(array[(char)pos + (char)1]);
                 swap_arr_pos(array,str_arr,pos,count);
                 count--;
                 remove_count++;
                     return remove_count;
                break;
            case 6:
                *((char*)vptr + (char)6) = '\0';                    //removing the 1st inserted char.
                rem_enter_0 = 0;
                (char *)vptr + (char)(array[(char)pos + (char)1]);
                 swap_arr_pos(array,str_arr,pos,count);
                 count--;
                 remove_count++;
                     return remove_count;
                break;
            case 7:
                *((char*)vptr + (char)7) = '\0';                    //removing the second inserted char.
                rem_enter_1 = 0;
                (char *)vptr + (char)(array[(char)pos + (char)1]);
                 swap_arr_pos(array,str_arr,pos,count);
                 count--;
                 remove_count++;
                     return remove_count;
                break;
        }
    }
  
}

void swap_arr_pos(int *array,char **str_arr,int pos, int count)             //swap function call.
{
    int iter;
        for( iter = pos; iter <= (count); iter++)                           //loop to swap the array positions.
        {
            if(iter == count - 1)              //condition to decrement the array contents postions from the removed element;s position.
            {
              array[iter]  = '\0';
              str_arr[iter] = '\0';
            }
            else
            {
                array[(char)iter] = array[(char)iter + (char)1];
                str_arr[(char)iter] = str_arr[(char)iter + (char)1];
            }

       }
}

void lining(int length,char *up_down)                   //lining function definition.(for display purpose)
{
    if( up_down == "down" )
        printf("\n");
    while(length-- > 0)
        printf("_");
    if( up_down == "up" )
        printf("\n");
}
/********************************************************END OF CODE********************************************************************/
