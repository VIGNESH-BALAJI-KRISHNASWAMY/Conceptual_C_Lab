/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 
*   Description     :
*   Input           : 
*   Output          : 
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    double num;
    char cha;
    void *vptr;
    vptr = &num;
    printf("\tIEEE ");
    printf("\nEnter a real nunmber:");
    scanf("%lf",&num);
    printf("%d",sizeof(float));
   /* float numb,current;
    numb = num;
    float mask = 0;
    while(numb != '.')
    {
        static float current;
        numb = (int)num >> (int)mask;
        current = numb;
        mask++;
        
    }
    printf("%f",current);*/
return 0;
}
/********************************************************END OF CODE********************************************************************/

