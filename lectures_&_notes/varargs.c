#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

int sum(int argNum, ...) { 
  int overall = 0;
  va_list arguments; 
  va_start(arguments, argNum); 
  for (int j = 1; j <= argNum; j++) {
    overall += va_arg(arguments, int); 
  }
  va_end(arguments); 
  return overall;
}

int main() {
  printf("%d\n", sum(2,1,2));
  printf("%d\n", sum(3,2,3,4)); 
  return 0;
}