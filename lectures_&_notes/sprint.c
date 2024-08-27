#include <string.h>
#include <stdio.h>

int main() {
  char str[25];
  sprintf(str, "%d squared is %d", 3, 3 * 3);
  printf("%s\n", str); 
  return 0;
}