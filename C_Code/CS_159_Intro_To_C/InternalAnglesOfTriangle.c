/***************************************************************************
*  Program Description: Given three points(that will always create a triangle with a positive area) this program will calculate the measures of the three internal angles and the areas of the three quadrilaterals.
***************************************************************************/
#include<stdio.h>
#include<math.h>

void input(double *a,double *b,double *c,double *d,double *e,double *f);
void distance_p(double a,double b,double c,double d,double e,double f,double*g,double*h,double*i);
void internal_a(double a,double b,double c,double*d,double*e,double*f);
void time(double a,double b,double c,double*d,double*e,double*f);
void quad_area(double a,double b,double c,double d,double e,double f,double*g,double*h,double*i);
void output(int,int,double,int,int,double,int,int,double,double,double,double);
int main()
{
  double x_1; //first x-coordinate
  double x_2; //second x-coordinate
  double x_3; //third x-coordinate
  double y_1; //first y-coordiante
  double y_2; //second y-coordinate
  double y_3; //third y_coordinate
  double dis_1; //distance between first and second point
  double dis_2; //distance between second and third point
  double dis_3; //distance between third and first point
  double a_1; //interior angle formed at point 1
  double a_2; //interior angle formed at point 2
  double a_3; //interior angle formed at point 3
  double min_1; //minute component of the angle formed at point 1
  double min_2; //minute component of the angle formed at point 2
  double min_3; //minute component of the angle formed at point 3
  double sec_1; //second component of the angle formed at point 1
  double sec_2; //second component of the angle formed at point 2
  double sec_3; //second component of the angle formed at point 3
  double area_1; //area of the first quadrilateral
  double area_2; //area of the second quadrilateral
  double area_3; //area of the third quadrilateral

  input(&x_1,&y_1,&x_2,&y_2,&x_3,&y_3);

  distance_p(x_1,y_1,x_2,y_2,x_3,y_3,&dis_1,&dis_2,&dis_3);
  internal_a(dis_1,dis_2,dis_3,&a_1,&a_2,&a_3);
  time(a_1,a_2,a_3,&min_1,&min_2,&min_3);
  time(min_1,min_2,min_3,&sec_1,&sec_2,&sec_3);

  quad_area(dis_1,dis_2,dis_3,a_1,a_2,a_3,&area_1,&area_2,&area_3);

  output(a_1,min_1,sec_1,a_2,min_2,sec_2,a_3,min_3,sec_3,area_1,area_2,area_3);

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
*    1.double,a, x component of the first point
*    2.double,b, y component of the first point
*    3.double,c, x component of the second point
*    4.double,d, y component of the second point
*    5.double,e, x component of the third point
*    6.double,f, y component of the third point
*
*  Function Description: This function is where the user will input the three points of the triangle
***************************************************************************/
void input(double *a,double *b,double *c,double *d,double *e,double *f)
{
  printf("Enter X coordinate #1 ->");
  scanf("%lf",a);
  printf("Enter Y coordinate #1 ->");
  scanf("%lf",b);
  printf("Enter X coordinate #2 ->");
  scanf("%lf",c);
  printf("Enter Y coordinate #2 ->");
  scanf("%lf",d);
  printf("Enter X coordinate #3 ->");
  scanf("%lf",e);
  printf("Enter Y coordinate #3 ->");
  scanf("%lf",f);

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
*    1.double,a, x component of the first point
*    2.double,b, y component of the first point
*    3.double,c, x component of the second point
*    4.double,d, y component of the second point
*    5.double,e, x component of the third point
*    6.double,f, y component of the third point
*    7.double,g, distance from point 1 to point 2
*    8.double,h, distance from point 2 to point 3
*    9.double,i, distance from point 3 to point 1
*
*  Function Description:This function calculates the distance from each coordinate given
***************************************************************************/
void distance_p(double a,double b,double c,double d,double e,double f,double*g,double*h,double*i)
{
  *g = sqrt(pow((c - a),2.0) + pow((d - b),2.0)); //calculates the distance from point 1 to point 2
  *h = sqrt(pow((e - c),2.0) + pow((f - d),2.0)); //calculates the distance from point 2 to point 3
  *i = sqrt(pow((a - e),2.0) + pow((b - f),2.0)); //calculates the distance from point 3 to point 1

  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: internal_a
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.double,a, distance from point 1 to point 2
*    2.double,b, distance from point 2 to point 3
*    3.double,c, distance from point 3 to point 1
*    4.double,d, angle formed at the first point
*    5.double,e, angle formed at the second point
*    6.double,f, angle formed at the third point
*
*  Function Description: This function will use the distances and law of cosines to find the internal angles of the triangle
***************************************************************************/
void internal_a(double a,double b,double c,double*d,double*e,double*f)
{
  *d = acos((pow(a,2.0) + pow(c,2.0) - pow(b,2.0)) / (2 * a * c)) * 180 / M_PI; //calculates interior angle at point 1
  *e = acos((pow(a,2.0) + pow(b,2.0) - pow(c,2.0)) / (2 * a * b)) * 180 / M_PI; //calculates interior angle at point 2
  *f = acos((pow(b,2.0) + pow(c,2.0) - pow(a,2.0)) / (2 * b * c)) * 180 / M_PI; //calculates interior angle at point 3
  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: time
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.double,a, component of the first angle
*    2.double,b, component of the second angle
*    3.double,c, component of the third angle
*    4.double,d, minute or second of the first angle
*    5.double,e, minute or second of the second angle
*    6.double,f, minute or second of the third angle
*
*  Function Description: This function will take the components of the interior angles and calculate the minutes and seconds of each angle
***************************************************************************/
void time(double a,double b,double c,double*d,double*e,double*f)
{
  *d = (a - (int) a) * 60; //calculates the components of the first angle
  *e = (b - (int) b) * 60; //calculates the components of the second angle
  *f = (c - (int) c) * 60; //calculates the components of the third angle
  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: quad_area
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
*    7.double,g, area of the first quadrilateral
*    8.double,h, area of the second quadrilateral
*    9.double,i, area of the third quadrilateral
*
*  Function Description: This function will use the angles and distances to calculate the areas of the quadrilaterals formed within the triangle
***************************************************************************/
void quad_area(double a,double b,double c,double d,double e,double f,double*g,double*h,double*i)
{
  double r; //radius of the circle
  double s; //semiperimeter of the triangle

  s = (a + b + c) / 2; //calculates the semiperimeter
  r = sqrt((s - a) * (s - b) * (s - c) / s); //calculates the radius
  *g = pow(r,2.0) * tan((90 - d / 2) * M_PI / 180); //calculates the area of the first quadrilateral
  *h = pow(r,2.0) * tan((90 - e / 2) * M_PI / 180); //calculates the area of the second quadrilateral
  *i = pow(r,2.0) * tan((90 - f / 2) * M_PI / 180); //calculates the area of the third quadrilateral
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
*    1.int,a, degree component of the first angle
*    2.int,b, minute component of the first angle
*    3.double,c, second component of the first angle
*    4.int,d, degree component of the second angle
*    5.int,e, minute component of the second angle
*    6.double,f, second component of the second angle
*    7.int,g, degree component of the third angle
*    8.int,h, minute component of the third angle
*    9.double,i, second component of the third angle
*    10.double,j, area of the first quadrilateral
*    11.double,k, area of the second quadrilateral
*    12.double,l, area of the third quadrilateral
*
*  Function Description: This function will take all the values calculated and display them
***************************************************************************/
void output(int a,int b,double c,int d,int e,double f,int g,int h,double i,double j,double k,double l)
{
  printf("Internal triangle angles: %d%c%c %d' %.2lf\", %d%c%c %d' %.2lf\", %d%c%c%d' %.2lf\"\n",a,0xC2,0xB0,b,c,d,0xC2,0xB0,e,f,g,0xC2,0xB0,h,i);
  printf("Area of quadrilaterls: %.2lf, %.2lf, %.2lf\n",j,k,l);
  return;
}
