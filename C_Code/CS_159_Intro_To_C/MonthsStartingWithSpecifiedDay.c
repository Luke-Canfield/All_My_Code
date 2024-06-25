/***************************************************************************
*  Program Description: This program given ten years and a desired day of the week will display the months within the first year that begin on the desired day of the week. The second through tenth year will have the desired day of the week continually incremented by one.
***************************************************************************/
#include<stdio.h>
#include<math.h>
#define SIZE 10
#define LENGTH 12

void input(int[],int*);
void desired_d(int);
void iterate_d(int[],int);
void start_m(int[],int[],int[]);
int main()
{
  int array[SIZE]; //user inputted array
  int day_w; //initial desired day of week
  int day_d[SIZE]; //iterated days of week
  int start[LENGTH]; //start days of each month

  input(array,&day_w);
  desired_d(day_w);
  iterate_d(day_d,day_w);
  start_m(array,day_d,start);

  return(0);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: input
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int,array, empty array of size 10
*    2.int,day, desired day of week
*
*  Function Description: This function stores the 10 years entered by the user in an empty array and receives the inital desired day of the week
***************************************************************************/
void input(int array[],int*day)
{
  int i; //loop control variable
  int a; //placholder for day

  printf("Enter 10 years [1700 - 2100] ->");

  for(i = 0; i < 10; i++)
  {
    scanf("%d",&array[i]);
  }
  printf("Enter day of week number ->");
  scanf("%d",&a);
  while(a < 0 || a > 6)
  {
    printf("\nError! Day of the week must be 0 to 6.\n");
    printf("\nEnter day of week number ->");
    scanf("%d",&a);
  }
  *day = a;
  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: desired_d
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int,day_w, desired day of the week
*
*  Function Description: This function displays the desired day of the week
***************************************************************************/
void desired_d(int day_w)
{
  if(day_w == 6)
  {
    printf("\nDesired day of the week: Saturday\n");
  }
  else if(day_w == 5)
  {
    printf("\nDesired day of the week: Friday\n");
  }

  else if(day_w == 4)
  {
    printf("\nDesired day of the week: Thursday\n");
  }
  else if(day_w == 3)
  {
    printf("\nDesired day of the week: Wednesday\n");
  }

  else if(day_w == 2)
  {
    printf("\nDesired day of the week: Tuesday\n");
  }
  else if(day_w == 1)
  {
    printf("\nDesired day of the week: Monday\n");
  }

  else if(day_w == 0)
  {
    printf("\nDesired day of the week: Sunday\n");
  }
  else
  {
  }

  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: iterate_d
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int, day_w, desired day of week
*    2.int, day_d, empty array of size 10
*
*  Function Description: This function iterates through and retreives the 10 days of the week
***************************************************************************/
void iterate_d(int day_d[],int day_w)
{
  int i; //loop control variable

  for(i = 0; i < 10; i++)
  {
    if(day_w == 16)
    {
      day_d[i] = 2;
    }
    else if(day_w == 15)
    {
      day_d[i] = 1;
    }

    else if(day_w == 14)
    {
      day_d[i] = 0;
    }
    else if(day_w == 13)
    {
      day_d[i] = 6;
    }

    else if(day_w == 12)
    {
      day_d[i] = 5;
    }
    else if(day_w == 11)
    {
      day_d[i] = 4;
    }

    else if(day_w == 10)
    {
      day_d[i] = 3;
    }
    else if(day_w == 9)
    {
      day_d[i] = 2;
    }

    else if(day_w == 8)
    {
      day_d[i] = 1;
    }
    else if(day_w == 7)
    {
      day_d[i] = 0;
    }

    else
    {
      day_d[i] = day_w;
    }
    day_w++; //increases the day by 1
  }

  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: start_m
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int,array, array of 10 years
*    2.int,day_d, iterated array of days
*
*  Function Description: This function calculates and displays the months of the specific year that start on the desired day
**************************************************************************/
void start_m(int array[],int day_d[],int start[])
{
  int day; //placeholder for day
  int leap; //placeholder for previous year being leap year
  int prev; //placholder for previous year
  int i; //loop control variable

  int month[LENGTH] = {0,3,3,6,1,4,6,2,5,0,3,5}; //month codes for calculating start day
  int last_d; //last digits in year
  int year_c; //year formula code
  int month_c; //month formula code

  int j; //loop control variable
  int leap_c; //placeholder for if current year is leap year
  int century_c; //placeholder for century

 for(i = 0; i < 10; i++)
  {
    if(day_d[i] == 6)
    {
      printf("Months in %d starting on Saturday: ",array[i]);
    }
    else if(day_d[i] == 5)
    {
      printf("Months in %d starting on Friday: ",array[i]);
    }

    else if(day_d[i] == 4)
    {
      printf("Months in %d starting on Thursday: ",array[i]);
    }
    else if(day_d[i] == 3)
    {
      printf("Months in %d starting on Wednesday: ",array[i]);
    }

    else if(day_d[i] == 2)
    {
      printf("Months in %d starting on Tuesday: ",array[i]);
    }
    else if(day_d[i] == 1)
    {
      printf("Months in %d starting on Monday: ",array[i]);
    }

    else if(day_d[i] == 0)
    {
      printf("Months in %d starting on Sunday: ",array[i]);
    }
    else
    {
    }

    prev = array[i] - 1;
    day = ((array[i] - 1) * 365 + ((array[i] - 1) / 4) - ((array[i] - 1) / 100) + ((array[i] - 1) / 400)) % 7; //calculates last day of previous year
    leap = (!(prev % 4) && (prev % 100)) || !(prev % 400); //calculates if previous year is leap year
    leap_c = (!(array[i] % 4) && (array[i] % 100)) || !(array[i] % 400); //calculates if current year is leap year

    if((leap = 1))
    {
      day = day + 1;
    }
    else
    {
    }

    for(j = 0; j < 12; j++)
    {
      last_d = array[i] % 100; //calculates last digits of current year
      year_c = (last_d + (last_d / 4)) % 7; //calculates year value for formula
      month_c = month[j]; //inserts month code for the formula to calculate first day of month
      century_c = array[i] / 100; //finds the century of the current year

      if(century_c == 21)
      {
        century_c = 4; //year code for 21st century
      }
      else if(century_c == 20)
      {
        century_c = 6; //year code for 20th century
      }

      else if(century_c == 19)
      {
        century_c = 0; //year code for 19th century
      }
      else if(century_c == 18)
      {
        century_c = 2; //year code for 18th century
      }

      else if(century_c == 17)
      {
        century_c = 4; //year code for 17th century
      }
      else
      {
      }

      if((leap_c == 1) && (j == 0 || j == 1))
      {
        start[j] = (year_c + month_c + century_c) % 7; //calculate start day if month is january or february and year is leap year
      }
      else
      {
        start[j] = (year_c + month_c + century_c + 1) % 7; //calculates start day of month
      }
    }
    if(start[0] == day_d[i])
    {
      printf("January ");
    }
    if(start[1] == day_d[i])
    {
      printf("February ");
    }

    if(start[2] == day_d[i])
    {
      printf("March ");
    }
    if(start[3] == day_d[i])
    {
      printf("April ");
    }

    if(start[4] == day_d[i])
    {
      printf("May ");
    }
    if(start[5] == day_d[i])
    {
      printf("June ");
    }

    if(start[6] == day_d[i])
    {
      printf("July ");
    }
    if(start[7] == day_d[i])
    {
      printf("August ");
    }

    if(start[8] == day_d[i])
    {
      printf("September ");
    }
    if(start[9] == day_d[i])
    {
      printf("October ");
    }

    if(start[10] == day_d[i])
    {
      printf("November ");
    }
    if(start[11] == day_d[i])
    {
      printf("December");
    }

    else
    {
    }
    printf("\n");
  }

  return;
}
