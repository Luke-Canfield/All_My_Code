/***************************************************************************
*  Program Description: This program given a year and an occurence number for the week of the year will calculate the end and start dates of that week and display an array as a visual
***************************************************************************/
#include<stdio.h>
#include<math.h>

void input(int*,int*);
int first_day(int);
void start_week(int,int*);
void total_day(int*,int);
void find_date(int,int*,int,int);
void end_day(int,int,int*,int*,int*);
void output(int,int,int,int);

int main()
{
  int year; //year number
  int occurence_n; //occurence number of week
  int prev_d; //first day of entered year
  int total_d; //total days of year
  int date; //first date of week
  int last_d; //last date of week
  int end_date; //total number of days to calculate last day of week
 int end_d; //last day of previous year
  int c_var = 0; //control variable

  input(&year,&occurence_n);
  prev_d = first_day(year); //calculates the first day of the year
  start_week(prev_d,&c_var); //finds the first day of the week
  total_day(&total_d,occurence_n); //finds total amount of days used to calculate first and end dates
  find_date(total_d,&date,year,occurence_n); //finds the first date of the week

  end_day(total_d,prev_d,&end_date,&end_d,&c_var); //changes variables to find end date,day
  start_week(end_d,&c_var); //finds the end day of the week
  find_date(end_date,&last_d,year,occurence_n); //finds the end date of the week
  output(date,prev_d,total_d,last_d); //displays the calculated values

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
*    1.int,a, year number
*    2.int,b, occurence number of week
*
*  Function Description: This function will take the inputs given by the user
***************************************************************************/
void input(int*a,int*b)
{
  printf("Enter year number ->");
  scanf("%d",a);
  printf("Enter occurence number ->");
  scanf("%d",b);
  printf("\n");

  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: prev_day
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int,a, year entered by user
*
*  Function Description: This function will calculate the day of december 31st of the previous year
***************************************************************************/
int first_day(a)
{
  int b; //placeholder for day
  int c; //placeholder for leap year
  int d; //placeholder for previous year

  d = a - 1;
  b = ((a - 1) * 365 + ((a - 1) / 4) - ((a - 1) / 100) + ((a - 1) / 400)) % 7; //calculates last day of previous year
  c = (!(d % 4) && (d % 100)) || !(d % 400); //calculates if previous year is leap year

  if ((c = 1))
  {
    b = b + 1; //adds one if the previous year is a leap year
  }
  else
  {
    b = b + 0;
  }

  return(b);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: start_week
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int,a, last day of the previous year
*    2.int,b, control variable for output
*
*  Function Description: This function determines which day the week starts on
***************************************************************************/
void start_week(int a,int*b)
{
  int c; //placeholder for control

  c = *b;

  if ((a == 7) && (c == 0))
  {
    printf("Start of week: Sunday "); //prints Sunday if it's the first day of the week
  }
  else if ((a == 6) && (c == 0))
  {
    printf("Start of week: Saturday "); //prints Saturday if it's the first day of the week
  }

  else if ((a == 5) && (c == 0))
  {
 printf("Start of week: Friday "); //prints Friday if it's the first day of the week
  }
  else if ((a == 4) && (c == 0))
  {
    printf("Start of week: Thursday "); //prints Thursday if it's the first day of the week
  }

  else if ((a == 3) && (c == 0))
  {
    printf("Start of week: Wednesday "); //prints Wednesday if it's the first day of the week
  }
  else if ((a == 2) && (c == 0))
  {
    printf("Start of week: Tuesday "); //prints Tuesday if it's the first day of the week
  }

  else if ((a == 1) && (c == 0))
  {
    printf("Start of week: Monday "); //prints Monday if it's the first day of the week
  }
  else if ((a == 7) && (c == 1))
  {
    printf("End of week: Sunday "); //same thing but for the end of the week
  }

  else if ((a == 6) && (c == 1))
  {
    printf("End of week: Saturday ");
  }
  else if ((a == 5) && (c == 1))
  {
    printf("End of week: Friday ");
  }
 else if ((a == 4) && (c == 1))
  {
    printf("End of week: Thursday ");
  }
  else if ((a == 3) && (c == 1))
  {
    printf("End of week: Wednesday ");
  }

  else if ((a == 2) && (c == 1))
  {
    printf("End of week: Tuesday ");
  }
  else
 {
    printf("End of week: Monday ");
  }

  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: find_total
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int,a, occurence number
*
*  Function Description: This function finds the ending date of the week
***************************************************************************/
void total_day(int*a,int b)
{
  if (b == 1)
  {
    *a = 7; //total amount of days if occurence number is 1
  }
  else
  {
    *a = (b * 7) - 6; //calculates total days when occurence is greater than 1
  }
  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: find_date
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int,a, total number of days in year
*    2.int,b, day of month
*    3.int,year, year that user entered
*    4.int,n, occurence number
*
*  Function Description: This program calculates the month of the specified occurence
***************************************************************************/
void find_date(int a,int*b,int year,int n)
{
  int c; //placeholder for date
  int d; //placeholder for year
  int e; //placeholder for leap year
  int f; //placeholder for occurence

  d = year;
  f = n;
  e = (!(d % 4) && (d % 100)) || !(d % 400); //calculates if year entered by user is leap year

  if (f == 1)
{
    c = a - 6;
    printf("January %d, %d\n",c,d);
  }
  else if (a <= 31)
  {
    c = a;
    printf("January %d, %d\n",c,d);
  }
  else if (a <= 59 + e)
  {
    c = a - 31;
    printf("February %d, %d\n",c,d);
  }

  else if (a <= 90 + e)
  {
    c = a - (59 + e);
    printf("March %d, %d\n",c,d);
  }
else if (a <= 120 + e)
  {
    c = a - (90 + e);
    printf("April %d, %d\n",c,d);
  }
  else if (a <= 151 + e)
  {
    c = a - (120 + e);
    printf("May %d, %d\n",c,d);
  }
  else if (a <= 181 + e)
  {
    c = a - (151 + e);
    printf("June %d, %d\n",c,d);
  }

  else if (a <= 212 + e)
{
    c = a - (181 + e);
    printf("July %d, %d\n",c,d);
  }
  else if (a <= 243 + e)
  {
    c = a - (212 + e);
    printf("August %d, %d\n",c,d);
  }
  else if (a <= 273 + e)
  {
    c = a - (243 + e);
    printf("September %d, %d\n",c,d);
  }

  else if (a <= 304 + e)
  {
    c = a - (273 + e);
    printf("October %d, %d\n",c,d);
  }
else if (a <= 334 + e)
  {
    c = a - (304 + e);
    printf("November %d, %d\n",c,d);
  }

  else if (a <= 365 + e)
  {
    c = a - (334 + e);
    printf("December %d, %d\n",c,d);
  }
  else
  {
    c = a - (365 + e);
    printf("January %d, %d\n",c,d + 1);
  }

  *b = c;

  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: end_day
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int,a, total day
*    2.int,b, last day of prev year
*    3.int,c, last date of week
*    4.int,d, last day of week
*
*  Function Description: This function calculates the variables used to find the end day and date of the week
***************************************************************************/
void end_day(int a,int b,int*c,int*d,int*e)
{
  *c = a + 6; //adds six to the total number of days to find the end date
  *d = b - 1; //subtracts one to find the last day of the week
  *e += 1; //adds one to the control variable

  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int,a, end date
*    2.int,b, start date of week
*    3.int,c, total days
*    4.int,d, end date of week
*
*  Function Description: Displays calculations in calendar format
***************************************************************************/
void output(int a,int b,int c,int d)
{
  if (c <= 31)
  {
    printf("\n          January        \n");
  }
  else if (c <= 59)
  {
    printf("\n         February        \n");
  }
  else if (c <= 90)
  {
    printf("\n           March         \n");
  }
  else if (c <= 120)
  {
    printf("\n           April         \n");
  }
else if (c <= 151)
  {
    printf("\n            May          \n");
  }
  else if (c <= 181)
  {
    printf("\n           June          \n");
  }
  else if (c <= 212)
  {
    printf("\n           July          \n");
  }
  else if (c <= 243)
  {
    printf("\n          August         \n");
  }
 else if (c <= 273)
  {
    printf("\n         September       \n");
  }
  else if (c <= 304)
  {
    printf("\n          October        \n");
  }
  else if (c <= 334)
  {
    printf("\n         November        \n");
  }
  else
  {
    printf("\n         December        \n");
  }
 printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Sun Mon Tue Wed Thu Fri Sat\n");

  if (b == 1)
  {
    int i; //counter
    for (a = a; a < 32; a++)
    {
      printf("%d",a);
      i++;
    }
    printf("  %d  %d  %d  %d\n",d - 3,d - 2,d - 1,d);
  }

  else if (b == 2)
  {
    printf("         %d   %d   %d   %d   %d\n",a,a + 1,a + 2,a + 3,d - 2);
    printf(" %d   %d\n",d - 1,d);
  }
 else if (b == 3)
  {
    printf("             %d  %d  %d  %d\n",a,a + 1,a + 2,a + 3);
    printf(" %d  %d  %d\n",d - 2,d - 1,d);
  }

  else if (b == 4)
  {
    printf("                 %d   %d   %d\n",a,a + 1,a + 2);
    printf(" %d   %d   %d   %d\n",a + 3,d - 2,d - 1,d);
  }

  else if (b == 5)
  {
    printf("                     %d   %d\n",a,d - 5);
    printf(" %d   %d   %d   %d   %d\n",d - 4,d - 3,d - 2,d - 1,d);
  }
 else if (b == 6)
  {
    printf("                         %d\n",a);
    printf(" %d   %d   %d   %d   %d   %d\n",d - 5,d - 4,d - 3,d - 2,d - 1,d);
  }

  else
  {
    printf(" %d   %d   %d   %d   %d   %d   %d\n",a,d - 5,d - 4,d - 3,d - 2,d - 1,d);
  }

  return;
}