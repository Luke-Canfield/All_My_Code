/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. lcanfiel@purdue.edu
*
*  Homework #:2
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have I provided access to my code
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Friday, 1:30, SC231
*
*  Program Description: This program tells a user to input the mass of an airplane, the amount of forward force produced by its propellers, and the mass of two gliders being towed. Knowing these values the program  will calculate the tension on each cable and the acceleration of the glider. Vertical forces and air resistance are not considered during this calculation.
***************************************************************************/
#include<stdio.h>
#include<math.h>

int main()
{
  double mass_A; //Mass of the airplane inputted by the user
  double mass_G1; //Mass of glider 1 inputted by the user
  double mass_G2; //Mass of glider 2 inputted by the user
  double force_P; //Forward force produced by the propellers
  double accel_G; //Acceleration of the glider
  double tension_C1; //Tension on cable between the airplane and glider 1
  double tension_C2; //Tension on cable between glider 1 and glider 2

  printf("Enter mass of airplane (kg) ->");
  scanf("%lf", &mass_A);
  printf("Enter mass of glider #1 (kg) ->");
  scanf("%lf", &mass_G1);
  printf("Enter mass of glider #2 (kg) ->");
  scanf("%lf", &mass_G2);
  printf("Enter force produced by propellers (N) ->");
scanf("%lf", &force_P);

  accel_G = force_P / (mass_A + mass_G1 + mass_G2); //Calculates the acceleration of the glider
  tension_C1 = accel_G * (mass_G1 + mass_G2); //Calculates the tension of the cable between glider 1 and the airplane
  tension_C2 = accel_G * mass_G2; //Calculates the tension of the cable between glider 1 and glider 2

  printf("\nAcceleration: %0.2lf m/s^2\n",accel_G);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Resulting tension on cable #1:   %.2lf Newtons\n",tension_C1);
  printf("Resulting tension on cable #2:   %.2lf Newtons\n",tension_C2);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return(0);
}
