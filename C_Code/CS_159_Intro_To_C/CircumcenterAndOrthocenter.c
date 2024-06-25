/***************************************************************************
*  Program Description: Given six coordinates this program will calculate the orthocenter and circumcenter and it will indidcate whether the nine point circle center is inside of the triangle
***************************************************************************/
#include<stdio.h>
#include<math.h>

void input(double*,double*,double*,double*,double*,double*);
void coord_ortho(double,double,double,double,double,double,double*,double*);
void distance_p(double,double,double,double,double,double,double*,double*,double*);
void angles(double,double,double,double*,double*,double*);
double coord_circum(double,double,double,double,double,double);
double nine_c(double,double);
double total_area(double,double,double);
double areas(double,double,double,double,double,double,double);
void output(double,double,double,double,double,double,double,double);

int main()
{
  double x_1; //first x-coordinate
  double y_1; //first y_coordinate
  double x_2; //second x-coordinate
  double y_2; //second y_coordinate
  double x_3; //third x-coordinate
 double y_3; //third y-coordinate
  double area_1; //first triangle area
  double area_2; //second triangle area
  double area_3; //third triangle area
  double nine_x; //x-coordinate of nine point circle center
  double nine_y; //y-coordinate of nine point circle center
  double dis_1; //distance between point A and point B
  double dis_2; //distance between point B and point C
  double dis_3; //distance between point C and point A
  double a_1; //angle formed at point 1
  double a_2; //angle formed at point 2
  double a_3; //angle formed at point 3
  double ortho_x; //x-coordinate of orthocenter
  double ortho_y; //y-coordinate of orthocenter
  double tot_area; //area enclosed by the three points
  double circum_x; //x-coordinate of circumcenter
  double circum_y; //y-coordinate of circumcenter

  input(&x_1,&y_1,&x_2,&y_2,&x_3,&y_3);

  distance_p(x_1,y_1,x_2,y_2,x_3,y_3,&dis_1,&dis_2,&dis_3);
  coord_ortho(x_1,y_1,x_2,y_2,x_3,y_3,&ortho_x,&ortho_y);
  angles(dis_1,dis_2,dis_3,&a_1,&a_2,&a_3);
  circum_x = coord_circum(x_1,x_2,x_3,a_1,a_2,a_3);
  circum_y = coord_circum(y_1,y_2,y_3,a_1,a_2,a_3);
  nine_x = nine_c(ortho_x,circum_x);
  nine_y = nine_c(ortho_y,circum_y);
  tot_area = total_area(dis_1,dis_2,dis_3);
  area_1 = areas(x_1,y_1,x_2,y_2,nine_x,nine_y,dis_1);
  area_2 = areas(x_2,y_2,x_3,y_3,nine_x,nine_y,dis_2);
  area_3 = areas(x_3,y_3,x_1,y_1,nine_x,nine_y,dis_3);

  output(ortho_x,ortho_y,circum_x,circum_y,nine_x,nine_y,tot_area,area_1 + area_2 + area_3);

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
*    1.double,a, first x-coordiante entered by user
*    2.double,b, first y-coordinate entered by user
*    3.double,c, second x-coordiante entered by user
*    4.double,d, second y-coordinate entered by user
*    5.double,e, third x-coordinate entereed by user
*    6.double,f, third y-coordinate entered by user
*
*  Function Description: this function gets the input from the user
***************************************************************************/
void input(double*a,double*b,double*c,double*d,double*e,double*f)
{
  printf("Enter X coordinate #1 ->");
  scanf("%lf", a);
  printf("Enter Y coordinate #1 ->");
  scanf("%lf", b);
  printf("Enter X coordinate #2 ->");
  scanf("%lf", c);
  printf("Enter Y coordinate #2 ->");
  scanf("%lf", d);
  printf("Enter X coordinate #3 ->");
  scanf("%lf", e);
  printf("enter Y coordiante #3 ->");
  scanf("%lf", f);

  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: distance_p
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.double,a, first x-coordinate
*    2.double,b, first y-coordinate
*    3.double,c, second x-coordinate
*    4.double,d, second y-coordinate
*    5.double,e, third x-coordinate
*    6.double,f, third y-cordinate
*    7.double,g, distance from point 1 to point 2
*    8.double,h, distance from point 2 to point 3
*    9.double,i, distance from point 3 to point 1
*
*  Function Description: This function calculates the distance between each point
***************************************************************************/
void distance_p(double a,double b,double c,double d,double e,double f,double*g,double*h,double*i)
{
  *g = sqrt(pow((c - a),2.0) + pow((d - b),2.0)); //calculates distance from point 1 to point 2
  *h = sqrt(pow((e - c),2.0) + pow((f - d),2.0)); //calculates distance from point 2 to point 3
  *i = sqrt(pow((a - e),2.0) + pow((b - f),2.0)); //calculates distance from point 3 to point 1

  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: coord_ortho
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.double,a, first x-coordinate of triangle
*    2.double,b, first y-coordinate of triangle
*    3.double,c, second x-coordinate of triangle
*    4.double,d, second y-coordiate of triangle
*    5.double,e, third x-coordinate of triangle
*    6.double,f, third y-coordinate of triangle
*    7.double,g, x-coordinate of orthocenter
*    8.double,h, y-coordinate of orthocenter
*
*  Function Description: This function calculates the orthocenter given the three points by the user
***************************************************************************/
void coord_ortho(double a,double b,double c,double d,double e,double f,double*g,double*h)
{
  double slope_1; //slope of line from point 1 to point 2
  double slope_2; //slope of line from point 1 to point 3
  slope_1 = -1 * pow(((b - d) / (a - c)),-1.0); //calculates slope of first line
  slope_2 = -1 * pow(((b - f) / (a - e)),-1.0); //calculates slope of second line
  *g = (slope_1 * e + d - slope_2 * c - f) / (slope_1 - slope_2); //calculates x-coordinate of orthocenter
  *h = slope_1 * *g - slope_1 * e +f; //calculates y-coordinate of orthocenter

  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: angles
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.double,a, distance from point 1 to point 2
*    2.double,b, distance from point 2 to point 3
*    3.double,c, distance from point 3 to point 1
*    4.double,d, angle formed at point 1
*    5.double,e, angle formed at point 2
*    6.double,f, angle formed at point 3
*
*  Function Description: This function will calculate the angles at each of the three points
***************************************************************************/
void angles(double a,double b,double c,double*d,double*e,double*f)
{
  *d = acos((pow(a,2.0) + pow(c,2.0) - pow(b,2.0)) / (2 * a * c)); //calculates angle at point 1
  *e = acos((pow(a,2.0) + pow(b,2.0) - pow(c,2.0)) / (2 * a * b)); //calculates angle at point 2
  *f = acos((pow(b,2.0) + pow(c,2.0) - pow(a,2.0)) / (2 * b * c)); //calculates angle at point 3

  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: coord_circum
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double,a, coordinate of first point
*    2.double,b, coordinate of second point
*    3.double,c, coordinate of third point
*    4.double,d, angle at first point
*    5.double,e, angle at second point
*    6.double,f, angle at third point
*
*  Function Description: This function will calculate the individual coordinate of the circumcenter
***************************************************************************/
double coord_circum(double a,double b,double c,double d,double e,double f)
{
  double z; //placeholder for circumcenter
  z = (a * sin(2 * d) + b * sin(2 * e) + c *sin(2 * f)) / (sin(2 * d) + sin(2 * e) + sin(2 * f)); //calculates the component of the circumcenter
  return(z);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: nine_c
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double,a, coordinate of orthocenter
*    2.double,b, coordinate of circumcenter
*
*  Function Description: This function will calculate the individual coordinate of nine point circle
***************************************************************************/
double nine_c(double a,double b)
{
  double y; //placeholder for the nine point circle coordinate
  y = (a + b) / 2; //calculates the coordinate of the nine point circle

  return(y);
}
/***************************************************************************
*
*
*  Function Information
*
*  Name of Function: total_area
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double,a, distance from point 1 to point 2
*    2.double,b, distance from point 2 to point 3
*    3.double,c, distance from piont 3 to point 1
*
*  Function Description: This function will calculate the area enclosed by the three points given by the user
***************************************************************************/
double total_area(double a,double b,double c)
{
  double w; //placeholder for total area
  double x; //semiperimeter of triangle
  x = (a + b + c) / 2; //calculates the semiperimeter
  w = sqrt(x * (x - a) * (x - b) * (x - c)); //calculates the total area

  return(w);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: areas
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double,a, x coordinate of some point
*    2.double,b, y coordinate of some point
*    3.double,c, x coordinate of some point
*    4.double,d, y coordinate of some point
*    5.double,e, x coordinate of nine point circle
*    6.double,f, y coordinate of nine point circle
*    7.double,g, distance from the given two points
*
*  Function Description: This function will calculate the area enclosed by two points that are given by the user and the nine point circle
***************************************************************************/
double areas(double a,double b,double c,double d,double e,double f,double g)
{
  double d_1; //distance from point 1 to nine center circle
  double d_2; //distance from point 2 to nine center circle
  double x; //semiperimeter of the triangle
  double A; //area of the triangle

  d_1 = sqrt(pow((a - e),2.0) + pow((b - f),2.0)); //calculates the distance from the first point to the nine point circle
  d_2 = sqrt(pow((c - e),2.0) + pow((d - f),2.0)); //calculates the distance from the second point to the nine point circle
  x = (g + d_1 + d_2) / 2; //calculates semiperimeter
  A = sqrt(x * (x - g) * (x - d_1) * (x - d_2)); //calculates the area of the triangle

  return(A);
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
*    1.double,a, x-coordinate of orthocenter
*    2.double,b, y-coordinate of orthocenter
*    3.double,c, x-coordinate of circumcenter
*    4.double,d, y-coordinate of circumcenter
*    5.double,e, x-coordinate of nine point circle
*    6.double,f, y-coordiante of nine point circle
*    7.double,g, area enclosed by the three points given by the user
*    8.double,h, sum of the areas enclosed by the two given points and the nine center circle
*
*  Function Description: This function will organize all the values calculated by the program
***************************************************************************/
void output(double a,double b,double c,double d,double e,double f,double g,double h)
{
  printf("Coordinates of Orthocenter: %0.2lf, %0.2lf\n", a,b);
  printf("Coordinates of Circumcenter: %0.2lf, %0.2lf\n", c,d);

  if (fabs(g - h) < 0.001)
  {
    printf("The nine point circle center: %0.2lf, %0.2lf is inside of the triangle\n", e,f);
  }
  else
  {
    printf("The nine point circle center: %0.2lf, %0.2lf is outside of the triangle\n", e,f);
  }
  return;
}