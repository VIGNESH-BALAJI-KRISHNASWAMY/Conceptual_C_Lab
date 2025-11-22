/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 
*   Description     : A Program to take n and k (1 <= k <= 10) as inputs. Generate consecutive NRPS of length n using k distinct character (1 <= k <= 9).
*   Input           : 
*   Output          : 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int check_distinct(char *);
void pattern(int,int,char*,char*);

int main()
{
    int num,length,count = 0,ret;
    printf("\tCONSECUTIVE NON REPEATATIVE PATTERN STRINGS ");
    printf("\nEnter the number of distinct characters (C) : ");
    scanf("%d",&num);
    if ( num > 10 || num <= 1 )
        printf("ERROR:Out of Range. correct range: 1 < C <= 10");
    else
    {
        printf("Enter the length of the string (N) : ");
        scanf("%d",&length);
        char dist_char[num + 1],NRPS[length + 1];
        printf("Enter the %d distinct characters : ",num);
        for(count = 0; count < num; count++)
        {
            scanf(" %c",&dist_char[count]);
        }
        dist_char[count] = '\0';
        NRPS[length + 1] = '\0';
        ret = check_distinct(dist_char);
        if(ret == 1)
        {
            printf("\nError : Enter distinct characters");
        }
        else
        {
            pattern(num,length,dist_char,NRPS);
            printf("Possible NRPS is '%s'",NRPS);
        }
    }
}

void pattern(int num_dist,int len,char *string,char *out_array)
{
    int iter,shift,temp = 0,count = 1;
    char *base_address;
    base_address = string;
    if(num_dist >= len)
    {
        for(iter = 0; iter < len; iter++)
        {
            *out_array = *string;
            out_array++;
            string++;
        }
    }
    else if(num_dist < len)
    {
        for(iter = 0; iter < len; iter++)
        {
           // no_iter = len/num_dist + len%num_dist;
            while( len != 0 )
            {
                *out_array = *string;
                out_array++;
                string++;
                if(*string == '\0')
                {
                   // no_iter--;
                    string = base_address;
                }
                len--;
            }
            
        }
    }
}

int check_distinct( char *string ) //to check distinct characters or not.
{
    int count = 0; 
    char *base_address,*iterative;
    base_address = string;
    iterative = string;
    ++iterative;
    while(*base_address != '\0')
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
