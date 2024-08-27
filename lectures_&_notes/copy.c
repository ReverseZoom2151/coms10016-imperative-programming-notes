#include <string.h>
#include <stdio.h>

int main() {
  char str1[] = "Hi";
  char str2[3];
  strcpy(str2, str1);
  printf("%s\n", str2); 
  return 0;
}