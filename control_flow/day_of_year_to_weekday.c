/*******************************************************DOCUMENTATION********************************************************************
*                                     
*   Name            : K.Vignesh Balaji
*   Date            : 02/03/2021
*   Description     : A Program to find which day of the year when given the number from 1 to 365.
*   Input           : ./a.out 
*                    	FINDING THE DAY OF THE YEAR
*                     Enter the value of 'n' i.e. 1 <= N <= 365 : 37
*                     Choose First Day : 
*                     1.Sunday
*                     2.Monday
*                     3.Tuesday
*                     4.Wednesday
*                     5.Thursday
*                     6.Friday
*                     7.Saturday
*                     Enter the option to set the first iday : 4
*                     The 37 th day is THURSDAY
*                     Do you want to continue (y/Y): y
*
*                     Enter the value of 'n' i.e. 1 <= N <= 365 : 0
*                     Error : Invalid Input, n value should be > 0 and <= 365
*                     Do you want to continue (y/Y): y
*
*                     Enter the value of 'n' i.e. 1 <= N <= 365 : 90
*                     Choose First Day : 
*                     1.Sunday
*                     2.Monday
*                     3.Tuesday
*                     4.Wednesday
*                     5.Thursday
*                     6.Friday
*                     7.Saturday
*                     Enter the option to set the first iday : 0
*                     Error : Invalid input, first day should be > 0 and <= 7
*                     Do you want to continue (y/Y): n
*                                                            
********************************************************START OF CODE********************************************************************/
#include <stdio.h>

int main()
{
    int num,day_num,rem_day,first_day; //declaring variables
    char* day;
    char character;

    printf("\tFINDING THE DAY OF THE YEAR\n");
  
  do                                  //loop to continue the process
  {
      printf("Enter the value of 'n' i.e. 1 <= N <= 365 : ");       // fetching day number
      scanf("%d",&day_num);

      if ( day_num > 365 || day_num <= 0 )                          //input evaluation
          printf("Error : Invalid Input, n value should be > 0 and <= 365");
      else
      {
          printf("Choose First Day : \n1.Sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n5.Thursday\n6.Friday\n7.Saturday\nEnter the option to set the first iday : ");
          scanf("%d",&first_day);                                   //fetching starting day
          if ( first_day > 7 || first_day <= 0 )                    //input evaluation
          printf("Error : Invalid input, first day should be > 0 and <= 7");
          else
          {
              rem_day = (day_num % 7);//finding the remaining days after the completion of week(s) == extra days which will surpass or preceed the First Day
              
              switch ( first_day )   //Switch statement to set the different sets of remaining days for Different First day.
              {
                  case 1:                         //case in which starting day is Sunday
                        switch ( rem_day ) //selecting the current day (which preceed or surpass the week) in which starting day is Sunday
                        {
                            case 1:
                                day = "SUNDAY";
                                break;
                            case 2:
                                day = "MONDAY";
                                break;
                            case 3:
                                day = "TUESDAY";
                                break;
                            case 4:
                                day = "WEDNESDAY";
                                break;
                            case 5:
                                day = "THURSDAY";
                                break;
                            case 6:
                                day = "FRIDAY";
                                break;
                            case 0:
                                day = "SATURDAY";
                                break;
                        }
                        break;
          
                  case 2:                           //starting day is Monday
                        switch ( rem_day )          //remaining days after a week started with its first day as Monday
                        {
                            case 0:
                                day = "SUNDAY";
                                break;
                            case 1:
                                day = "MONDAY";
                                break;
                            case 2:
                                day = "TUESDAY";
                                break;
                            case 3:
                                day = "WEDNESDAY";
                                break;
                            case 4:
                                day = "THURSDAY";
                                break;
                            case 5:
                                day = "FRIDAY";
                                break;
                            case 6:
                                day = "SATURDAY";
                                break;
                        }
                        break;
                  
                  case 3:                           //starting day is Tuesday
                        switch ( rem_day )
                        {
                            case 6:
                                day = "SUNDAY";
                                break;
                            case 0:
                                day = "MONDAY";
                                break;
                            case 1:
                                day = "TUESDAY";
                                break;
                            case 2:
                                day = "WEDNESDAY";
                                break;
                            case 3:
                                day = "THURSDAY";
                                break;
                            case 4:
                                day = "FRIDAY";
                                break;
                            case 5:
                                day = "SATURDAY";
                                break;
                        }
                        break;
                  
                  case 4:                           //starting Day is Wednesday
                        switch ( rem_day )
                        {
                            case 5:
                                day = "SUNDAY";
                                break;
                            case 6:
                                day = "MONDAY";
                                break;
                            case 0:
                                day = "TUESDAY";
                                break;
                            case 1:
                                day = "WEDNESDAY";
                                break;
                            case 2:
                                day = "THURSDAY";
                                break;
                            case 3:
                                day = "FRIDAY";
                                break;
                            case 4:
                                day = "SATURDAY";
                                break;
                        }
                        break;
                  
                  case 5:                           //Starting day is Thursday
                        switch ( rem_day )
                        {
                            case 4:
                                day = "SUNDAY";
                                break;
                            case 5:
                                day = "MONDAY";
                                break;
                            case 6:
                                day = "TUESDAY";
                                break;
                            case 0:
                                day = "WEDNESDAY";
                                break;
                            case 1:
                                day = "THURSDAY";
                                break;
                            case 2:
                                day = "FRIDAY";
                                break;
                            case 3:
                                day = "SATURDAY";
                                break;
                        }
                        break;
                  
                  case 6:                           //Starting day is Friday
                        switch ( rem_day )
                        {
                            case 3:
                                day = "SUNDAY";
                                break;
                            case 4:
                                day = "MONDAY";
                                break;
                            case 5:
                                day = "TUESDAY";
                                break;
                            case 6:
                                day = "WEDNESDAY";
                                break;
                            case 0:
                                day = "THURSDAY";
                                break;
                            case 1:
                                day = "FRIDAY";
                                break;
                            case 2:
                                day = "SATURDAY";
                                break;
                        }
                        break;

                  case 7:                           //starting day is Saturday
                        switch ( rem_day )
                        {
                            case 2:
                                day = "SUNDAY";
                                break;
                            case 3:
                                day = "MONDAY";
                                break;
                            case 4:
                                day = "TUESDAY";
                                break;
                            case 5:
                                day = "WEDNESDAY";
                                break;
                            case 6:
                                day = "THURSDAY";
                                break;
                            case 0:
                                day = "FRIDAY";
                                break;
                            case 1:
                                day = "SATURDAY";
                                break;
                        }
                        break;
              }
              printf("The %d th day is %s",day_num,day);    //printing the output
          }
      }

   printf("\nDo you want to continue (y/Y): ");             //input fetch for continuing the process.
   getchar();
   scanf("%c",&character);
   printf("\n");

  } while (character == 'y' || character == 'Y');           //condition to continue the process
return 0;
}
/********************************************************END OF CODE********************************************************************/
