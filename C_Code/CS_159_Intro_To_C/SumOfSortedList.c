/***************************************************************************
*  Program Description: This program given a range of decimal values will determine the decimal value with the largest even digit change and the decimal value with the largest odd digit change
***************************************************************************/
#include<stdio.h>
#include<math.h>
void input(int*,int*);
int decToOctal(int);
int countEven(int);
int countOdd(int);
int difference(int,int);
void output(int,int,int,int);

int main()
{
  int start_base10; //starting decimal value
  int end_base10; //ending decimal value
  int base_i; //index for for loop
  int base_j; //index for for loop
  int oddBase_10; //base 10 number for odd digits
  int evenBase_10; //base 10 number for even digits
  int evenBase_8; //base 8 number converted from base 10
  int oddBase_8; //base 8 number converted from base 10
  int even_10; //even digits in base 10 number
  int odd_10; //odd digits in base 10 number
  int even_8; //even digits in base 8 number
  int odd_8; //odd digits in base 8 number
  int evenDifference; //difference in even digits between decimal and octal value
  int oddDifference; //difference in odd digits between decimal and octal value
  int evenDifference_1; //difference in even digits between octal and decimal
  int oddDifference_1; //difference in odd digits between octal and decimal
  int evenBase_8_1; //octal number converted from decimal
  int oddBase_8_1; //base 8 number converted from base 10
  int even_10_1; //even digits in decimal value
  int odd_10_1; //odd digits in decimal value
  int even_8_1; //even digits in octal value
  int odd_8_1; //odd digits in octal value

  input(&start_base10,&end_base10);
  oddBase_10 = start_base10;
  oddBase_8 = decToOctal(oddBase_10);
  odd_8 = countOdd(oddBase_8);
  odd_10 = countOdd(oddBase_10);
  oddDifference = difference(odd_10, odd_8);

  for(base_i = start_base10 + 1; base_i <= end_base10; base_i ++)
  {
    oddBase_8_1 = decToOctal(base_i);
    odd_8_1 = countOdd(oddBase_8_1);
    odd_10_1 = countOdd(base_i);
    oddDifference_1 = difference(odd_10_1, odd_8_1);

    if(pow(oddDifference_1,2) > pow(oddDifference,2))
    {
      oddDifference = oddDifference_1;
      oddBase_10 = base_i;
      oddBase_8 = decToOctal(base_i);
    }
  }

  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-Change-Decimal-=-Octal-\n");
  output(oddDifference,oddBase_10,oddBase_8,1);

  evenBase_10 = start_base10;
  evenBase_8 = decToOctal(evenBase_10);
  even_8 = countEven(evenBase_8);
  even_10= countEven(evenBase_10);
  evenDifference = difference(even_10, even_8);

  for(base_j = start_base10 + 1; base_j <= end_base10; base_j++)
  {
    evenBase_8_1 = decToOctal(base_j);
    even_8_1 = countEven(evenBase_8_1);
    even_10_1 = countEven(base_j);
    evenDifference_1 = difference(even_10_1, even_8_1);

    if(pow(evenDifference_1,2) > pow(evenDifference,2))
    {
      evenDifference = evenDifference_1;
      evenBase_10 = base_j;
      evenBase_8 = decToOctal(base_j);
    }
  }
  output(evenDifference,evenBase_10,evenBase_8,0);

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
*    1.int,a, starting decimal value
*    2.int,b, ending decimal value
*
*  Function Description: This function retrieves the input from the user
***************************************************************************/
void input(int*start_base10,int*end_base10)
{
  int a; //placeholder for starting value
  int b; //placeholder for ending value

  printf("Enter starting decimal value ->");
  scanf("%d",&a);
  while (a < 0)
  {
    printf("Error! The starting decimal value should be non-negative.");
    printf("\nEnter starting decimal value ->");
    scanf("%d", &a);
  }
  printf("Enter ending decimal value ->");
  scanf("%d", &b);
  while (b < 0 || b <= a)
  {
    printf("Error! The decimal ending value should be greater than %d.",a);
    printf("\nEnter ending decimal value ->");
    scanf("%d", &b);
 }
  *start_base10 = a;
  *end_base10 = b;
  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: decToOctal
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int, base_10, user inputted decimal number
*
*  Function Description: This function calculates the octal value of a non-negative decimal number
***************************************************************************/
int decToOctal(int base_10)
{
  int index; //starting index is 0
  int remainder; //remainder after dividing user input decimal by 8
  int quotient; //digits of input decimal
  int base_8; //converted octal number
  int base; //base of new octal value

  quotient = base_10;
  base_8 = 0;
  base = 8;
  index = 0;

  while(quotient != 0)
  {
    remainder = quotient % base;
    quotient = quotient / base;
    base_8 = base_8 + (remainder * pow(10,index));
    index++;
  }
  return(base_8);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: countEven
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int, number, value being analyzed
*
*  Function Description: This function calculates the number of even digits in a given number
***************************************************************************/
int countEven(int number)
{
  int evenCount; //placeholder for number of even digits
  int remainder; //last digit of input number

  evenCount = 0;
  remainder = 0;

  while(number > 0)
  {
    remainder = number % 10;
    if(remainder % 2 == 0)
    {
      evenCount++;
    }
    number = number / 10;
  }
  return(evenCount);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: countOdd
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int, number, value being analyzed
*
*  Function Description: This function calculates the number of odd digits in a given number
***************************************************************************/
int countOdd(int number)
{
  int oddCount; //placholder for number of odd digits
  int remainder; //last digit of input number

  oddCount = 0;
  remainder = 0;

  while(number > 0)
  {
    remainder = number % 10;
    if(remainder % 2 != 0)
    {
      oddCount++;
    }
    number = number / 10;
  }
  return(oddCount);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: difference
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int, num1, first value
*    2.int, num2, second value
*
*  Function Description: This function returns the difference between two numbers
***************************************************************************/
int difference(int num1,int num2)
{
  return(num1 - num2);
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
*    1.int, difference, differnence in even and odd digits
*    2.int, decimal, base 10 number with greatest difference
*    3.int, octal, base 8 number with greatest difference
*    4.int, evenOrOdd, printing greatest digit change in odd or even
*
*  Function Description: This function displays the results calculated within the program
***************************************************************************/
void output(int difference,int decimal,int octal,int evenOrOdd)
{
  if(evenOrOdd == 1)
  {
    printf("Largest odd digit change: %7d %7d %7d\n",difference,decimal,octal);
  }
  else
  {
    printf("Largest even digit change: %6d %7d %7d\n",difference,decimal,octal);
  }
  return;
}