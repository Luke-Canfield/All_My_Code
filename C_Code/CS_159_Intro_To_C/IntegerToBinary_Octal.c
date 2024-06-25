/***************************************************************************
*  Program Description: This program given an array of 20 integers will determine if each integer is even or odd. The n if the integer is odd the program will calculate its binary value. If the integer is even then the program will calculate the octal value of the integer.
***************************************************************************/
#include<stdio.h>
#include<math.h>
#define SIZE 20

void input(int[]);
void decToBinary(int[]);
void decToOctal(int[]);
int main()
{
  int array[SIZE]; //array of integers

  input(array);
  decToBinary(array);
  decToOctal(array);

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
 *    1.int,a, empty array of size 20
 *
 *  Function Description: This program gets the input from the user
 ***************************************************************************/
void input(int array[])
{
  int i; //loop control variable

  printf("Enter 20 integer values ->");

  for(i = 0; i < 20; i++)
  {
    scanf("%d",&array[i]);
  }
  return;
}

/***************************************************************************
 *
 *  Function Information
 *
 *  Name of Function: decToBinary
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1.int,array, array of 20 integers
 *
 *  Function Description: This function determines if any integers within the array are odd and if so calculates the binary value of each odd integer
 ***************************************************************************/
void decToBinary(int array[])
{
  int index; //starting index is 0
  int remainder; //remainder after dividing user input by 8
  int quotient; //digits of input decimal
  int base_2; //converted binary number
  int base; //base of new octal value
  int i; //loop control variable

  printf("\nBinary values: ");

  for(i = 0; i < 20; i++)
  {
    if(array[i] % 2 != 0)
    {
      quotient = array[i];
      base_2 = 0;
      base = 2;
      index = 0;

      while(quotient != 0)
      {
        remainder = quotient % base;
        quotient = quotient / base;
        base_2 = base_2 + (remainder * pow(10,index));
        index++;
      }
     printf("%d ",base_2);
    }
    else
    {
    }
  }
  printf("\n");

  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: decToOctal
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int,array, array with all of the user inputs
*
*  Function Description: This function iterates through the array and if any of the integers are even, if so it calculates the binary value of the integer otherwise it calculates the octal value
***************************************************************************/
void decToOctal(int array[])
{
  int index; //starting index is 0
  int remainder; //remainder after dividing user input by 8
  int quotient; //digits of input decimal
  int base_8; //converted octal number
  int base; //base of new octal value
  int i; //loop control variable

  printf("Octal values: ");

  for(i = 0; i < 20; i++)
  {
    if(array[i] % 2 == 0)
    {
      quotient = array[i];
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
     printf("%d ", base_8);
    }
    else
    {
    }
  }
  printf("\n");

  return;
}
