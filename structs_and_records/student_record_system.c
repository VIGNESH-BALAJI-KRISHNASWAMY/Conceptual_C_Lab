/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 
*   Description     :
*   Input           : ./a.out 
*   Output          :
*                       	STUDENT RECORD 
*                       Enter the number of students : 2
*
*                       Enter the number of subjects:3
*                       Enter the name of subject 1 : Maths
*                       Enter the name of subject 2 : Science
*                       Enter the name of subject 3 : Social
*                       ----------Enter the student datails-------------
*                       Enter the student Roll no.: 01
*                       Enter the student 1 name :Nandhu
*                       Enter Maths mark :100
*                       Enter Science mark :95.5
*                       Enter Social mark :80
*                       ----------Enter the student datails-------------
*                       Enter the student Roll no.: 02
*                       Enter the student 2 name :Mandhu
*                       Enter Maths mark :85
*                       Enter Science mark :56
*                       Enter Social mark :100
*
*                       ----Display Menu----
*                       1. All student details
*                       2. Particular student details
*                       Enter Your choice : 1
*                       Roll No.       Name               Maths             Science              Social       Average            Grade
*                          1           Nandhu               100              95.5                80              91.8               A
*                          2           Mandhu                85                56               100              80.3               F
*
*
*                       Do you want another search(y/Y): y
*
*                       ----Display Menu----
*                       1. All student details
*                       2. Particular student details
*                       Enter Your choice : 2
*                       ----Menu for Particular student----
*                       1. Name.
*                       2. Roll no.
*                       Enter you choice : 1
*                       Enter the name of the student :Mandhu
*                       Roll No.       Name               Maths             Science              Social       Average            Grade
*                          2           Mandhu                85                56               100              80.3               F
*
*
*                       Do you want another search(y/Y): y
*
*                       ----Display Menu----
*                       1. All student details
*                       2. Particular student details
*                       Enter Your choice : 2
*                       ----Menu for Particular student----
*                       1. Name.
*                       2. Roll no.
*                       Enter you choice : 2
*                       Enter the Roll No. of the student :1
*                       Roll No.       Name               Maths             Science              Social       Average            Grade
*                          1           Nandhu               100              95.5                80              91.8               A
*
*
*                       Do you want another search(y/Y): n
*                       Do you want to continue(y/Y):y
*                       	STUDENT RECORD 
*                       Enter the number of students : 3
*
*                       Enter the number of subjects:4
*                       Enter the name of subject 1 : Maths 
*                       Enter the name of subject 2 : Science
*                       Enter the name of subject 3 : Social
*                       Enter the name of subject 4 : Language
*                       ----------Enter the student datails-------------
*                       Enter the student Roll no.: 1440201
*                       Enter the student 1440201 name :Abishek
*                       Enter Maths mark :100
*                       Enter Science mark :89
*                       Enter Social mark :98
*                       Enter Language mark :70
*                       ----------Enter the student datails-------------
*                       Enter the student Roll no.: 1440202
*                       Enter the student 1440202 name :Bindhu
*                       Enter Maths mark :89
*                       Enter Science mark :88.7
*                       Enter Social mark :100
*                       Enter Language mark :56
*                       ----------Enter the student datails-------------
*                       Enter the student Roll no.: 1440203
*                       Enter the student 1440203 name :Chandru
*                       Enter Maths mark :57
*                       Enter Science mark :76
*                       Enter Social mark :78
*                       Enter Language mark :87
*
*                       ----Display Menu----
*                       1. All student details
*                       2. Particular student details
*                       Enter Your choice : 1
*       Roll No.       Name               Maths             Science              Social            Language       Average            Grade
*       1440201          Abishek               100                89                98                70              89.2               B
*       1440202           Bindhu                89              88.7               100                56              83.4               B
*       1440203          Chandru                57                76                78                87              74.5               C
*
*
*                       Do you want another search(y/Y): y
*
*                       ----Display Menu----
*                       1. All student details
*                       2. Particular student details
*                       Enter Your choice : 2
*                       ----Menu for Particular student----
*                       1. Name.
*                       2. Roll no.
*                       Enter you choice : 1440204
*
*                       ERROR:Invalied Input!
*
*                       Do you want another search(y/Y): y
*
*                       ----Display Menu----
*                       1. All student details
*                       2. Particular student details
*                       Enter Your choice : 2
*                       ----Menu for Particular student----
*                       1. Name.
*                       2. Roll no.
*                       Enter you choice : 1
*                       Enter the name of the student :Bindhu
*       Roll No.       Name               Maths             Science              Social            Language       Average            Grade
*       1440202           Bindhu                89              88.7               100                56              83.4               B
*
*                       No Data found with name Bindhu .
*
*                       Do you want another search(y/Y): n
*                       Do you want to continue(y/Y):n
*                                                             
********************************************************START OF CODE********************************************************************/
#include <stdio.h>                                                  //header file.


int my_strcmp(char *,char *);                                       //string compare function declaration.

struct student                                                      //student structure definition.
{
    int roll;
    char name[40];
    double average;
    char grade;
    float sub_mark[20];
};

struct subject                                                      //subject structure definition.
{
    char sub_name[30];
};


int main()
{
    char inner_loop,outer_loop;

    do                                                              //outer loop to create new record.
    {
        int num_stud,iter,num_sub,jiter,flag = 0;                   //input variable declaration.
        double sum;
        int choice,menu,ret,roll_num;
        char nam[40];

        printf("\tSTUDENT RECORD ");
    
        printf("\nEnter the number of students : ");                //input fetching for structure subject.
        scanf("%d",&num_stud);
        printf("\nEnter the number of subjects:");
        scanf("%d",&num_sub);
        struct subject Sub[num_sub];

        for(jiter = 0; jiter < num_sub; jiter++)
        {
            printf("Enter the name of subject %d : ",jiter + 1);
            scanf(" %[^\n]",Sub[jiter].sub_name);
        }
    
    
        struct student St[num_stud];

                                                                    //fetching input for structure student.
        for(iter = 0; iter < num_stud; iter++)
        {
            printf("----------Enter the student datails-------------\n");
            printf("Enter the student Roll no.: ");
            scanf("%d",&St[iter].roll);
            printf("Enter the student %d name :",St[iter].roll); 
            scanf(" %40[^\n]",St[iter].name);
    
            sum = 0;
            for(jiter = 0; jiter < num_sub; jiter++)
            {
                printf("Enter %s mark :",Sub[jiter].sub_name);
                scanf("%f",&St[iter].sub_mark[jiter]);
                sum = sum + St[iter].sub_mark[jiter];
            }
            St[iter].average = sum/num_sub;                         //storing average of each student.
            
            if ( St[iter].average > (float)90 )                     //storing grades based on each average.
                St[iter].grade = 'A';
            else if ( St[iter].average >= (float)81 && St[iter].average <= (float)90 )
                St[iter].grade = 'B';
            else if ( St[iter].average >= (float)71 && St[iter].average <= (float)80 )
                St[iter].grade = 'C';
            else if ( St[iter].average >= (float)61 && St[iter].average <= (float)70 )
                St[iter].grade = 'D';
            else 
                St[iter].grade = 'F';
        }
        do                                                          //innerloop to display the contents of each record.
        {
            printf("\n----Display Menu----\n1. All student details\n2. Particular student details\nEnter Your choice : ");
            scanf("%d",&choice);
        
        switch(choice)
        {
                case 1:                                            //case 1 to deisplay all student details at once.
                    printf("%4s %10s","Roll No.","Name");
                    for(iter = 0;iter < num_sub; iter++)
                    {
                        printf("%20s",Sub[iter].sub_name);
                    }
                    printf("%14s %16s\n","Average","Grade");
                    for(iter = 0;iter < num_stud; iter++)
                    {
                        printf("%4d %16s",St[iter].roll,St[iter].name);
                        for(jiter = 0; jiter < num_sub; jiter++)
                        {
                            printf("%18g",St[iter].sub_mark[jiter]);
                        }
                        printf("%18.3lg",St[iter].average);
                        printf("%16c\n",St[iter].grade);
                    }
                    printf("\n");
                    break;
                    
                case 2:                                             //case to display particular student details.
                    printf("----Menu for Particular student----\n1. Name.\n2. Roll no.\nEnter you choice : ");
                    scanf("%d",&menu);
            
                    switch (menu)
                    {
                        case 1:                                     //displaying based on matching given name.
                            printf("Enter the name of the student :");                            
                            scanf(" %[^\n]",nam);
                    
                            for( iter = 0; iter < num_stud; iter++)
                            {
                                ret = my_strcmp(nam,St[iter].name);
                                if(ret == 0)
                                {
                                    flag = 1;
                                    printf("%4s %10s","Roll No.","Name");
                                    for(jiter = 0;jiter < num_sub; jiter++)
                                    {
                                        printf("%20s",Sub[jiter].sub_name);
                                    }
                                    printf("%14s %16s\n","Average","Grade");
                                    printf("%4d %16s",St[iter].roll,St[iter].name);
                                    for(jiter = 0; jiter < num_sub; jiter++)
                                    {
                                        printf("%18g",St[iter].sub_mark[jiter]);
                                    }
                                    printf("%18.3lg",St[iter].average);
                                    printf("%16c\n",St[iter].grade);
                                    printf("\n");
                                }    
                            }
                                if(flag == 0)
                                     printf("No Data found with name %s .\n",nam);
                                break;
                            
                            case 2:                                                 //displaying based on given roll number.
                                printf("Enter the Roll No. of the student :");
                                scanf("%d",&roll_num);
                                    for( iter = 0; iter < num_stud; iter++)
                                    {
                                        if(roll_num == St[iter].roll)  
                                        {
                                            flag = 1;
                                            printf("%4s %10s","Roll No.","Name");
                                            for(jiter = 0;jiter < num_sub; jiter++)
                                            {
                                                printf("%20s",Sub[jiter].sub_name);
                                            }
                                            printf("%14s %16s\n","Average","Grade");
                                            printf("%4d %16s",St[iter].roll,St[iter].name);
                                            for(jiter = 0; jiter < num_sub; jiter++)
                                            {
                                                printf("%18g",St[iter].sub_mark[jiter]);
                                            }
                                            printf("%18.3lg",St[iter].average);
                                            printf("%16c\n",St[iter].grade);
                                            printf("\n");
                                        }
                                    }
                                    if(flag==0)
                                        printf("No Data found with Roll No. %d.\n",roll_num);
                                break;
                        default:
                             printf("\nERROR:Invalied Input!\n");
                    }

        }                
        printf("\nDo you want another search(y/Y): ");                 //input fetch for inner loop. 
        scanf(" %c",&inner_loop);
        }while ( inner_loop == 'Y' || inner_loop == 'y');              //condition for inner loop to execute.

        printf("Do you want to continue(y/Y):");                       //input fetch for outer loop.
        scanf(" %c",&outer_loop);

    }while(outer_loop =='y'|| outer_loop =='Y');                       //condition for outer loop to execute.
}

int my_strcmp(char *name1,char *name2)                                  //string comparision function definition.
{
    static char *base_add1,*base_add2;
    base_add1 = name1;
    base_add2 = name2;
    while( (*name1 == *name2) && *name1 != '\0' && *name2 != '\0')      //condition for dtring comparision.
    {
        name1++;
        name2++;
    }
    if(*name1 == *name2)
    {
        name1 = base_add1;
        name2 = base_add2;
        return 0;                                                       //if strings are equal return 0.
    }
    else if(*name1 > *name2)
    {
        name1 = base_add1;
        name2 = base_add2;
        return 1;                                                       //if string 1 is greater than return 1.
    }
    else if(*name1 < *name2)
    {  
        name1 = base_add1;
        name2 = base_add2;
        return -1;                                                      //if string 2 is greater than return -1.
    }
}
/********************************************************END OF CODE********************************************************************/
