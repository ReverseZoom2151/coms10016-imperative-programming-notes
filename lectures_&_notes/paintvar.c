#include <stdio.h> 

int area(int length, int width, int height) { 
  int sides = 2 * length * height; 
  int ends = 2 * width * height; 
  int ceiling = length * width; 
  return sides + ends + ceiling; 
} 

int main(void) { 
  int total = area(5, 3, 2); 
  printf("The paint area is: %d\n", total); 
  return 0;
}