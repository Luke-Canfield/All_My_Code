/***************************************************************************
*  Program Description: The user inputs a value as the small radius which the program then uses to calculate the area of a circle. That radius is then used to find the ide length of a hexagon which is then used to calculate the area of a hexagon. The radius is then used to calculate a larger circle which the hexagon is inscribed in. Lastly, the radius is used to calculate the side length of a pentagon which intrun gives us the are of the pentagon.
***************************************************************************/
#include<stdio.h>
#include<math.h>

int main()
 {
  double radius_sc; //radius of the small circle
  double area_sc; //area of the small circle
  double side_h; //side length of the hexagon
  double area_h; //area of the hexagon
  double radius_lc; //radius of the large circle
  double area_lc; //area of the large circle
  double side_p; //side length of pentagon
  double area_p; //area of the pentagon

  printf("Enter the radius of the small circle ->");
  scanf("%lf",&radius_sc);

  area_sc = M_PI * pow(radius_sc,2.0); //calculates the area of the small circle
  side_h = 2 * tan(M_PI / 6) * radius_sc; //calculates the side length of the hexagon
  area_h = 3 * (sqrt(3) /2) * pow(side_h,2.0); //calculates the area of the hexagon
  radius_lc = sqrt(pow(radius_sc,2.0) + pow(side_h / 2,2.0)); //calculates the large radius
  area_lc = M_PI * pow(radius_lc,2.0); //calculates the area of the large circle
  side_p = 2 * tan(M_PI / 5) * radius_lc; //calculates the side length of the pentagon
  area_p = 0.25 * sqrt(5 * ( 5 + 2 * sqrt(5))) * pow(side_p,2.0); //calculates the area of the pentagon

  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Area of small circle: %.2lf\n", area_sc);
  printf("Side length of hexagon: %.2lf\n", side_h);
  printf("Area of hexagon: %.2lf\n", area_h);
  printf("Area of large circle: %.2lf\n", area_lc);
  printf("Side length of pentagon: %.2lf\n", side_p);
  printf("Area of pentagon: %.2lf\n", area_p);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return(0);
 }

int main()
 {
  double polygon_s; //number of polygon sides
  double p_area; //polygon area
  double p_apothem; //polygon apothem length
  double s_length; //polygon side length
  double circle_r; //circle radius
  double circle_a; //circle area
  double d_radius; //variable used to dictate the decision making process of the program
  double option; //the option that is selected by the user

  printf("Option 1: Polygon inside of circle\n");
  printf("Option 2: Circle inside of polygon\n");
  printf("Select your option ->");
  scanf("%lf",&option);
  printf("Enter number of polygon sides ->");
  scanf("%lf",&polygon_s);
  printf("Enter length of polygon apothem ->");
  scanf("%lf",&p_apothem);

  s_length = 2 * p_apothem * tan(M_PI / polygon_s); //calculates side length of polygon
  d_radius = sqrt(pow(s_length / 2,2.0) + pow(p_apothem,2.0)); //calculates radius used to help make decision

  option -= 1; //reduces the value of the option so a decision can be made
 circle_r = p_apothem * option; //if option 2 is selected by the user then the radius equals the apothem
  circle_r += d_radius * (1 - option); //if option 1 is selected the radius will equal the calculated radius
  circle_a = M_PI * pow(circle_r,2.0); //calculates the area of the circle
  p_area = 0.5 * p_apothem * s_length * polygon_s; //calculates the area of the polygon

  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Circle Radius: %0.2lf\n", circle_r);
  printf("Circle Area: %0.2lf\n", circle_a);
  printf("Polygon Side Length: %0.2lf\n", s_length);
  printf("Polygon Area: %0.2lf\n", p_area);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return(0);
 }
