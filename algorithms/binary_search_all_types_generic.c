/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 31/10/2021.
*   Description     : A Program to implement binary search for all basic datatypes.
*   Input           : ./a.out 
*   Output          :   	IMPLEMENTING BINARY SEARCH FOR ALL BASIC DATATYPES
*                       1. Int
*                       2. Char
*                       3. Float
*                       4. Double
*                       Choice:1
*                       Enter the length of array :5
*
*                       Enter 5 elements of type int
*                       1. 6
*                       2. 7
*                       3. 3
*                       4. 4
*                       5. 8
*                       After Sorting: 3 4 6 7 8 
*                       Enter the key element to search: 8
*                       Search Element 8 is at position 4 of array.
*                       Do you want to continue(y/Y):y
*
*                       1. Int
*                       2. Char
*                       3. Float
*                       4. Double
*                       Choice:2
*                       Enter the length of array :5
*
*                       Enter 5 elements of type char
*                       1. a
*                       2. s
*                       3. d
*                       4. f
*                       5. g
*                       After Sorting: a d f g s 
*                       Enter the key element to search: a
*                       Search Element a is at position 0 of array.
*                       Do you want to continue(y/Y):y
*
*                       1. Int
*                       2. Char
*                       3. Float
*                       4. Double
*                       Choice:3
*                       Enter the length of array :5
*
*                       Enter 5 elements of type float
*                       1. 12.34
*                       2. 12.33
*                       3. 1.112
*                       4. 3.43
*                       5. 4.52
*                       After Sorting: 1.112000 3.430000 4.520000 12.330000 12.340000 
*                       Enter the key element to search: 3.43
*                       Search Element 3.430000 is at position 1 of array
*                       Do you want to continue(y/Y):y
*
*                       1. Int
*                       2. Char
*                       3. Float
*                       4. Double
*                       Choice:4
*                       Enter the length of array :4
*
*                       Enter 4 elements of type double
*                       1. 222222.11
*                       2. 1.23
*                       3. 13.4
*                       4. 21
*                       After Sorting: 1.23 13.4 21 222222 
*                       Enter the key element to search: 222222.11
*                       Search Element 222222 is at position 3 of array
*                       Do you want to continue(y/Y):n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>                                                              //header file.

int binary_search(void *,char *,int,void *);                                    //function declaration.
void sort(void *,int,char *);
void get_elements(void *,int,char *);
int atoi(const char *);


int main(int argc,char *argv[],char *envp[])                         //main function declaration with command line i/p as parameter list.
{
    int choice,live = 0,length,ret;
    char character,*string;
    printf("\tIMPLEMENTING BINARY SEARCH FOR ALL BASIC DATATYPES");
    
    do                                                              //loop to continue the process.
    {
        printf("\n1. Int\n2. Char\n3. Float\n4. Double\nChoice:");
        scanf("%d",&choice);

                if( argv[1] == NULL)
                {
                    printf("Enter the length of array :");
                    scanf("%d",&length);
                }
                else 
                    length = atoi(argv[1]);
        
                if(length <= 0)
                    printf("\nERROR:Length of array should be greater than 0 and positive!");
                else
                {    
                    switch(choice)
                    {
                        case 1:                     //condition for int.
                            {
                                string = "int";
                                printf("\nEnter %d elements of type int\n",length);
                                int array[length],key;
                                int *ptr = array;
                                get_elements(ptr,length,string);
                                sort(ptr,length,string);
                                printf("\nEnter the key element to search: ");
                                scanf("%d",&key);
                                ret = binary_search(ptr,string,length,&key);
                                if(ret == -1)
                                    printf("Entered element %d is not found in the array",key);
                                else
                                    printf("Search Element %d is at position %d of array.",key,ret);
                            }
                            break;
                        case 2:                    //condition for char.
                            {
                                string = "char";
                                printf("\nEnter %d elements of type char\n",length);
                                char array1[length],key;
                                char *cptr = array1;
                                get_elements(cptr,length,string);
                                sort(cptr,length,string);
                                printf("\nEnter the key element to search: ");
                                scanf(" %c",&key);
                                ret = binary_search(cptr,string,length,&key);
                                if(ret == -1)
                                    printf("Entered element %c is not found in the array",key);
                                else
                                    printf("Search Element %c is at position %d of array.",key,ret);
                            }
                            break;
                        case 3:                 //condition for float.
                            {
                                string = "float";
                                printf("\nEnter %d elements of type float\n",length);
                                float array2[length],key;
                                float *fptr = array2;
                                get_elements(fptr,length,string);
                                sort(fptr,length,string);
                                printf("\nEnter the key element to search: ");
                                scanf("%f",&key);
                                ret = binary_search(fptr,string,length,&key);
                                if(ret == -1)
                                    printf("Entered element %f is not found in the array",key);
                                else
                                    printf("Search Element %f is at position %d of array.",key,ret);
                            }
                            break;
                        case 4:                 //condition for double.
                            {
                                string = "double";
                                printf("\nEnter %d elements of type double\n",length);
                                double array3[length],key;
                                double *dptr = array3;
                                get_elements(dptr,length,string);
                                sort(dptr,length,string);
                                printf("\nEnter the key element to search: ");
                                scanf("%le",&key);
                                ret = binary_search(dptr,string,length,&key); 
                                if(ret == -1)
                                    printf("Entered element %le is not found in the array",key);
                                else
                                    printf("Search Element %le is at position %d of array.",key,ret);
                            }
                            break;
                    }
                }

        printf("\nDo you want to continue(y/Y):");      //input fetch for next cycle.
        scanf(" %c",&character);
    }while(character == 'y' || character == 'Y');       //condition for next cycle executuion.

}


void get_elements(void *vptr,int length,char *string)               //function definition for getting elements for different types.
{
    int iter;
    if(string == "int")
    {
        for( iter = 0; iter < length; iter++ )
        {
            printf("%d. ",iter+1);
            scanf(" %d",(int*)vptr + (char)iter);
        }
    }
    else if(string == "char")
    {
        for( iter = 0; iter < length; iter++ )
        {
            printf("%d. ",iter + 1);
            getchar();
            scanf("%c",(char*)vptr + (char)iter);
        }
    }
    else if(string == "float")
    {
        for( iter = 0; iter < length; iter++ )
        {
            printf("%d. ",iter + 1);
            scanf(" %f",(float*)vptr + (char)iter);
        }
    }
    else if(string == "double")
    {
        for( iter = 0; iter < length; iter++ )
        {
            printf("%d. ",iter + 1);
            scanf(" %le",(double*)vptr + (char)iter);
        }
    }
}


void sort(void *vptr,int length ,char *string)                  //sorting based on the datatype.
{
    int iter,jiter;
    double temp;
    char c_temp;
        for(iter = 0;iter < length; iter++)
        {
            for(jiter = iter + 1; jiter < length; jiter++)
            {
                if( string == "int")
                {
                    if(*((int*)vptr + (char)iter) > *((int *)vptr + (char)jiter))
                    {
                        temp = *((int *)vptr + (char)iter);
                        *((int*)vptr + (char)iter) = *((int *)vptr + (char)jiter);
                        *((int *)vptr + (char)jiter) = temp;
                    }
                }
                else if( string == "char")
                {
                    if(*((char*)vptr + (char)iter) > *((char *)vptr + (char)jiter))
                    {
                        c_temp = *((char *)vptr + (char)iter);
                        *((char *)vptr + (char)iter) = *((char *)vptr + (char)jiter);
                        *((char *)vptr + (char)jiter) = c_temp;
                    }
                }
                else if( string == "float")
                {
                    if(*((float*)vptr + (char)iter) > *((float *)vptr + (char)jiter))
                    {
                        temp = *((float *)vptr + (char)iter);
                        *((float *)vptr + (char)iter) = *((float *)vptr + (char)jiter);
                        *((float *)vptr + (char)jiter) = temp;
                    }
                }
                else if( string == "double")
                {
                    if(*((double *)vptr + (char)iter) > *((double *)vptr + (char)jiter))
                    {
                        temp = *((double *)vptr + (char)iter);
                        *((double *)vptr + (char)iter) = *((double *)vptr + (char)jiter);
                        *((double *)vptr + (char)jiter) = temp;
                    }
                }
            }
        }
  
        printf("After Sorting: ");
        if(string == "int")
        {
            for(iter = 0; iter < length;iter++)
                printf("%d ",*((int*)vptr + (char)iter));
        }
        else if(string == "char")
        {
            for(iter = 0; iter < length;iter++)
                printf("%c ",*((char*)vptr + (char)iter));
        }
        else if(string == "float")
        {
            for(iter = 0; iter < length;iter++)
                printf("%f ",*((float*)vptr + (char)iter));
        }
        else if(string == "double")
        {
            for(iter = 0; iter < length;iter++)
                printf("%lg ",*((double*)vptr + (char)iter));
        }
}


int binary_search(void *ptr,char *string,int length,void *key_ptr)      //binary search function definition for different datatye.
{
        void *mid;
        int low_pos,mid_pos,high_pos,count = 0;
        low_pos = 0;
        mid_pos = (length - 1)/2;
        high_pos = length;

            if(string == "int")
            {
                mid = (int *)ptr + (char)((length - 1)/2);

                while( *(int*)mid != *(int *)key_ptr)
                {
                    count++;
                    if(*(int*)mid < *(int *)key_ptr)
                    {
                        low_pos = mid_pos;
                        mid_pos = (low_pos + high_pos)/2;
                        mid = ((int *)ptr + (char)(mid_pos));
                    }
                    else if(*(int*)mid > *(int *)key_ptr)
                    {
                        high_pos = mid_pos;
                        mid_pos = (low_pos + high_pos)/2;
                        mid = ((int *)ptr + (char)(mid_pos));
                    }
                    if(count > length)
                        return -1;
                }
                return mid_pos;
            }
            else if(string == "double")
            {
                mid = (double *)ptr + (char)((length - 1)/2);
                
                while( *(double *)mid != *(double *)key_ptr)
                {
                    count++;
                    if(*(double *)mid < *(double *)key_ptr)
                    {
                        low_pos = mid_pos;
                        mid_pos = (low_pos + high_pos)/2;
                        mid = ((double *)ptr + (char)(mid_pos));
                    }
                    else if(*(double *)mid > *(double *)key_ptr)
                    {
                        high_pos = mid_pos;
                        mid_pos = (low_pos + high_pos)/2;
                        mid = ((double *)ptr + (char)(mid_pos));
                    }
                    if(count > length)
                        return -1;
                }
                return mid_pos;
            }
            else if(string == "char")
            {
                mid = (char *)ptr + (char)((length - 1)/2);
                
                while( *(char *)mid != *(char *)key_ptr)
                {
                    count++;
                    if(*(char *)mid < *(char *)key_ptr)
                    {
                        low_pos = mid_pos;
                        mid_pos = (low_pos + high_pos)/2;
                        mid = ((char *)ptr + (char)(mid_pos));
                    }
                    else if(*(char *)mid > *(char *)key_ptr)
                    {
                        high_pos = mid_pos;
                        mid_pos = (low_pos + high_pos)/2;
                        mid = ((char *)ptr + (char)(mid_pos));
                    }
                    if(count > length)
                        return -1;
                }
                return mid_pos;
            }
            else if(string == "float")
            {
                mid = (float *)ptr + (char)((length - 1)/2);
                
                while( *(float *)mid != *(float *)key_ptr)
                {
                    count++;
                    if(*(float *)mid < *(float *)key_ptr)
                    {
                        low_pos = mid_pos;
                        mid_pos = (low_pos + high_pos)/2;
                        mid = ((float *)ptr + (char)(mid_pos));
                    }
                    else if(*(float *)mid > *(float *)key_ptr)
                    {
                        high_pos = mid_pos;
                        mid_pos = (low_pos + high_pos)/2;
                        mid = ((float *)ptr + (char)(mid_pos));
                    }
                    if(count > length)
                        return -1;
                }
                return mid_pos;
            }
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
/********************************************************END OF CODE********************************************************************/
