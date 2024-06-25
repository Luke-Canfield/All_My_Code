/***************************************************************************
*  Program Description: Given three points that create a triangle with a positive area, this program will calculate the distance between the points and it will calculate the coordinate of the incenter found within the triangle.
***************************************************************************/
#include<stdio.h>
#include<math.h>

double point_dist(int,int,int,int);
double center(int a,int b,int c,double d, double e, double f);
int main()
{
  int x_1; //first x-coordinate
  int x_2; //second x-coordinate
  int x_3; //third x-coordinate
  int y_1; //first y-coordinate
  int y_2; //second y-coordinate
  int y_3; //third y-coordinate
  double dis_1; //distance from point 1 to point 2
  double dis_2; //distance from point 2 to point 3
  double dis_3; //distance from point 3 to point 1
  double center_x; //x component of the incenter
  double center_y; //y component of the incenter
  
  printf("Enter X coordinate #1 ->");
  scanf("%d", &x_1);
  printf("Enter Y coordinate #1 ->");
  scanf("%d", &y_1);
  printf("Enter X coordinate #2 ->");
  scanf("%d", &x_2);
  printf("Enter Y coordinate #2 ->");
  scanf("%d", &y_2);
  printf("Enter Y coordinate #3 ->");
  scanf("%d", &x_3);
  printf("Enter Y coordinate #3 ->");
  scanf("%d", &y_3);

  dis_1 = point_dist(x_1,y_1,x_2,y_2);
  dis_2 = point_dist(x_2,y_2,x_3,y_3);
  dis_3 = point_dist(x_3,y_3,x_1,y_1);

  center_x = center(x_1,x_2,x_3,dis_1,dis_2,dis_3);
  center_y = center(y_1,y_2,y_3,dis_1,dis_2,dis_3);
  
  printf("\nDistance from point 1 to point 2: %0.2f\n", dis_1);
  printf("Distance from point 2 to point 3: %0.2f\n", dis_2);
  printf("Distance from point 3 to point 1: %0.2f\n", dis_3);
  printf("Location of Triangle Incenter: %0.2f, %0.2f\n",center_x,center_y);

  return(0);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: point_dist
*
*  Function Return Type: Double
*
*  Parameters (list data type, name, and comment one per line):
*    1.a,int, will be the x component of the first point
*    2.b,int, will be the y component of the first point
*    3.c,int, will be the x component of the second point
*    4.d,int, will be the y component of the second point
*
*  Function Description: This function calculates the distance from any two points
***************************************************************************/
double point_dist(a,b,c,d)
{
  double p; //placeholder for the distance
  p = sqrt(pow((c - a),2.0) + pow((d - b),2.0)); //Calculates the distance between two points
  return(p);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: center
*
*  Function Return Type: Double
*
*  Parameters (list data type, name, and comment one per line):
*    1.a,int, either x or y component of first point
*    2.b,int, either x or y component of second point
*    3.c,int, either x or y component of third point
*    4.d,int, distance between point 1 and point 2
*    5.e,int, distance between point 2 and point 3
*    6.f,int, distance between point 3 and point 1
*
*  Function Description: This function finds the incenter of the triangle given the coordinates of three points
***************************************************************************/
double center(int a,int b,int c,double d,double e,double f)
{
  double t; //placeholder for the incenter
  t = ((e * a) + (f * b) + (d * c)) / (d + e + f); //calculates the incenter of the triangle
  return(t);
}