#include <string.h>
#include <stdio.h>

int main() {
  char str1[] = "Hi\n";
  char str2[] = "Lo\n";
  char str3[strlen(str1) + strlen(str2) + 1];
  strcpy(str3, str1);
  strcat(str3, str2);
  printf("%s", str3); 
  return 0;
}