#include <stdio.h> 

int minimum(int x, int y) { 
  int min; 
  if (x < y) min = x; 
  else min = y; 
  return min; 
}

int main(void) { 
  int x, y;
  printf("Enter x:\n");
  scanf("%d", &x); 
  printf("Enter y:\n");
  scanf("%d", &y); 
  printf("The smaller number is: %d\n", minimum(x, y)); 
  return 0; 
}