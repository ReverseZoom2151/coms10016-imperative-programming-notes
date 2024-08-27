#include <stdio.h> 

int area(int length, int width, int height) { 
  return 2 * (width + length) * height + length * width; 
} 

int main(void) {
  printf("The paint area is: %d\n", area(5, 3, 2)); 
  return 0;
}