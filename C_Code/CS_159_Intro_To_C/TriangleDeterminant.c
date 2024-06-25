/***************************************************************************
*  Program Description: This program given three coordinates that form a triangle by the user will calculate the orthocenter and the internal angles of the triangle as well as determine the type of the triangle.
*****************************************************************************/
#include<stdio.h>
#include<math.h>

void input(int,double*,double*);
void coord_ortho(double,double,double,double,double,double,double*,double*);
void distance_p(double,double,double,double,double,double,double*,double*,double*);
double longest_s(double,double,double);
void determine_p(double,double,double,double,double,double,double,double*,double*);
void internal_a(double,double,double,double*,double*,double*);
void output(double,double,double,double,double);

int main()
{
  double x_1; //x-coordinate of point A
  double y_1; //y-coordinate of point A
  double x_2; //x-coordinate of point B
  double y_2; //y-coordiante of point B
  double x_3; //x-coordinate of point C
  double y_3; //y-coordinate of point C
  double ortho_x; //x-coordinate of orthocenter
  double ortho_y; //y-coordinate of orthocenter
  double dis_ab; //distance from point A to point B
  double dis_bc; //distance from point B to point C
  double dis_ca; //distance from point C to point A
  double a_1; //internal angle 1
  double a_2; //internal angle 2
  double a_3; //internal angle 3
  double long_s; //longest side of triangle
  double side_1; //distance of internal triangle side 1
  double side_2; //distance of internal triangle side 2
  double ix_1; //x-coordinate of point 1 used to calculate internal angle
  double iy_1; //y-coordinate of point 1 used to calculate internal angle
  double ix_2; //x-coordinate of point 2 used to calculate internal angle
 double iy_2; //y-coordinate of point 2 used to calculate internal angle

  input(1,&x_1,&y_1);
  input(2,&x_2,&y_2);
  input(3,&x_3,&y_3);

  coord_ortho(x_1,y_1,x_2,y_2,x_3,y_3,&ortho_x,&ortho_y);
  distance_p(x_1,y_1,x_2,y_2,x_3,y_3,&dis_ab,&dis_bc,&dis_ca);
  long_s = longest_s(dis_ab,dis_bc,dis_ca);
  determine_p(long_s,dis_ab,dis_bc,dis_ca,x_1,x_2,x_3,&ix_1,&ix_2);
  determine_p(long_s,dis_ab,dis_bc,dis_ca,y_1,y_2,y_3,&iy_1,&iy_2);
  distance_p(ix_1,iy_1,ix_2,iy_2,ortho_x,ortho_y,&long_s,&side_1,&side_2);
  internal_a(long_s,side_1,side_2,&a_1,&a_2,&a_3);

  output(ortho_x,ortho_y,a_1,a_2,a_3);

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
*    1.int,a, number of point
*    2.double,b, x-coordinate of some point entered by user
*    3.double,c, y-coordinate of some point entered by user
*
*  Function Description: This function gets the input from the user
***************************************************************************/
void input(int a,double*b,double*c)
{
  printf("Enter point #%d ->",a);
  scanf("%lf", b);
  scanf("%lf", c);

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
*    1.double,a, x-coordinate of point A entered by user
*    2.double,b, y-coordinate of point A entered by user
*    3.double,c, x-coordinate of point B entered by user
*    4.double,d, y-coordinate of point B entered by user
*    5.double,e, x-coordinate of point C entered by user
*    6.double,f, y-coordinate of point C entered by user
*    7.double,g, x-coordinate of orthocenter
*    8.double,h, y-coordinate of orthocenter
*
*  Function Description: This function calculates the orthocenter given points A,B,C by the user
***************************************************************************/
void coord_ortho(double a,double b,double c,double d,double e,double f,double*g,double*h)
{
  double slope_1; //slope of line from point A to point B
  double slope_2; //slope of line from point A to point C

  slope_1 = -1 * pow(((d - b) / (c - a)),-1.0); //calculates slope of the first line
  slope_2 = -1 * pow(((b - f) / (a - e)),-1.0); //calculates slope of the second line

  *g = (slope_1 * e + d - slope_2 * c - f) / (slope_1 - slope_2); //calculates x-coordinate of orthocenter
  *h = slope_1 * *g - slope_1 * e + f; //calculates y-coordinate of orthocenter

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
*    1.double,a, x-coordinate of point A entered by user
*    2.double,b, y-coordinate of point A entered by user
*    3.double,c, x-coordinate of point B entered by user
*    4.double,d, y-coordinate of point B entered by user
*    5.double,e, x-coordinate of point C entered by user
*    6.double,f, y-coordiante of point C entered by user
*    7.double,g, distance from point A to point B
*    8.double,h, distance from point B to point C
*    9.double,i, distance from point C to point A
*
*  Function Description: This function calculates the distance from each point in the triangle
***************************************************************************/
void distance_p(double a,double b,double c,double d,double e,double f,double*g,double*h,double*i)
{
  *g = sqrt(pow((c - a),2.0) + pow((d - b),2.0)); //calculates the distance from point A to point B
  *h = sqrt(pow((e - c),2.0) + pow((f - d),2.0)); //calculates the distance from point B to point C
  *i = sqrt(pow((a - e),2.0) + pow((b - f),2.0)); //calculates the distance from point C to point A

  return;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: longest_s
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double,a, distance from point A to point B
*    2.double,b, distance from point B to point C
*    3.double,c, distance from point C to point A
*
*  Function Description: This function determines the longest side of the triangle
***************************************************************************/
double longest_s(double a,double b,double c)
{
  double z; //placeholder for longest side

  if (a > b && a > c)
  {
    z = a;
  }
  else if (b > a && b > c)
  {
    z = b;
  }
  else
  {
    z = c;
  }
  return(z);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: determine_p
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.double,a, longest side of external triangle
*    2.double,b, distance from point A to point B
*    3.double,c, distance from point B to point C
*    4.double,d, distance from point C to point A
*    5.double,e, some coordinate at point A
*    6.double,f, some coordinate at point B
*    7.double,g, some coordinate at point C
*    8.double,h, x-coordinate for internal triangle
*    9.double,i, x-coordinate for internal triangle
*
*  Function Description: This function determines which external points should be used in the internal triangle
***************************************************************************/
void determine_p(double a,double b,double c,double d,double e,double f,double g,double*h,double*i)
{
  if (a == b)
  {
    *h = e;
    *i = f;
  }
  else if (a == c)
  {
    *h = f;
    *i = g;
  }
  else
  {
    *h = g;
    *i = e;
  }

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
*    1.double,a, distance from point A to point B
*    2.double,b, distance from point B to point C
*    3.double,c, distance from point C to point A
*    4.double,d, angle 1
*    5.double,e, angle 2
*    6.double,f, angle 3
*
*  Function Description: This function calculates the internal angles of the triangle
***************************************************************************/
void internal_a(double a,double b,double c,double*d,double*e,double*f)
{
  *d = acos((pow(a,2.0) + pow(c,2.0) - pow(b,2.0)) / (2 * a * c)) * 180 / M_PI; //calculates angle 1
  *e = acos((pow(a,2.0) + pow(b,2.0) - pow(c,2.0)) / (2 * a * b)) * 180 / M_PI; //calculates angle 2
  *f = acos((pow(b,2.0) + pow(c,2.0) - pow(a,2.0)) / (2 * b * c)) * 180 / M_PI; //calculates angle 3

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
*    1.double,a, x-coordinate of orthocenter
*    2.double,b, y-coordinate of orthocenter
*    3.double,c, internal triangle 1
*    4.double,d, internal triangle 2
*    5.double,e, internal triangle 3
*
*  Function Description: This function will organize and display all the values calculated by the program
***************************************************************************/
void output(double a,double b,double c,double d,double e)
{
  printf("Coordinates of orthocenter: %0.2lf, %0.2lf\n", a,b);

  if (c > d && d > e)
  {
    printf("Internal triangle angles: %0.1lf, %0.1lf, %0.1lf\n", e,d,c);
  }
  else if (c > e && e > d)
  {
    printf("Internal triangle angles: %0.1lf, %0.1lf, %0.1lf\n", d,e,c);
  }
  else if (d > c && c > e)
  {
    printf("Internal triangle angles: %0.1lf, %0.1lf, %0.1lf\n", e,c,d);
  }
  else if (d > e && e > c)
  {
    printf("Internal triangle angles: %0.1lf, %0.1lf, %0.1lf\n", c,e,d);
  }
  else if (e > d && d > c)
  {
    printf("Internal triangle angles: %0.1lf, %0.1lf, %0.1lf\n", c,d,e);
  }
  else
  {
    printf("Internal triangle angles: %0.1lf, %0.1lf, %0.1lf\n", d,c,e);
  }

  if (((c != d) && (c != e)) && ((fabs(c - 90) < 0.001) || (fabs(d - 90) < 0.001) || (fabs(e - 90) < 0.001)))
  {
    printf("Triangle Type: Scalene obtuse\n");
  }
  else if (((fabs(c - 90) < 0.001) || (fabs(d - 90) < 0.001) || (fabs(e - 90) < 0)) && ((c == d || c == e || d == e)))
  {
    printf("Triangle Type: Isosceles obtuse\n");
  }
  else if ((fabs(c - 60) < 0.001) && (fabs(d - 60) < 0.001) && (fabs(e - 60) < 0.001))
  {
    printf("Triangle Type: Equilateral acute\n");
  }
  else if ((fabs(c - 90) < 0.001) || (fabs(d - 90) < 0.001) || (fabs(e - 90) < 0.001))
  {
    printf("Triangle Type: Isosceles right\n");
  }
  else if (((fabs(c - 90) < 0.001) && (fabs(d - 90) < 0.001) && (fabs(e - 90) < 0.001) && (c == e || c == d || e == d)))
  {
    printf("Triangle Type: Isosceles acute\n");
  }
  else
  {
    printf("Triangle Type: Scalene acute\n");
  }

  return;
}
