/***************************************************************************
*  Program Description: This asks the user to input a value for a radius of a circle. Given the radius the program will then calculate the side length of a pentagon, the area of that pentagon and the area of a circle given the specified radius.
***************************************************************************/
#include<stdio.h>
#include<math.h>
#define APPROX_PI 3.1416

int main()
 {
   float r;//radius of the circle inputted by the user
   printf("Please enter the value you want as the radius:");
   scanf("%f", &r);
   float c_a;//Area of the circle
   float p_s;//Side length of pentagon
   float p_a;//Area of the pentagon
   float h;//Height of triangles

   c_a = APPROX_PI * (pow(r,2.0));//Calculates the area of the circle
   p_s = 2 * r * sin(APPROX_PI/5);//Calculates the side length of pentagon
   h = sqrt(pow(r,2.0)-pow(.5 * p_s,2.0));//Calculates height of triangle
   p_a = 5 * (.5 * p_s * h);//Calculates Area of Pentagon

   printf("Side Length:%2.f\n",p_s);
   printf("\nCircle Area: %2.f\n",c_a);
   printf("Pentagon Area: %2.f\n",p_a);

   return(0);
 }
