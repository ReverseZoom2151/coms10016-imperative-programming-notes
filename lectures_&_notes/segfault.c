#include <stdio.h>

int main() {
  int seq[3] = {10, 5, 4};
  int outOfBoundsIndex = 1000000000;   
  printf("%d\n", seq[outOfBoundsIndex]);  
  return 0;
}