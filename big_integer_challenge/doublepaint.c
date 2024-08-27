#include <stdio.h> 

double area(double length, double width, double height) { 
  double sides = 2 * length * height; 
  double ends = 2 * width * height; 
  double ceiling = length * width; 
  return sides + ends + ceiling; 
} 

int main(void) { 
  double length, width, height;
  printf("Enter room length:\n");
  scanf("%lf", &length); 
  printf("Enter room width:\n");
  scanf("%lf", &width); 
  printf("Enter room height:\n");
  scanf("%lf", &height); 
  double total = area(length, width, height); 
  printf("The paint area is: %lf\n", total); 
  return 0;
}