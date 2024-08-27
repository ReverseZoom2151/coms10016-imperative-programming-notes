#include <string.h>
#include <stdio.h>

void compareContent(char str1[], char str2[]) {
  if (strcmp(str1, str2) == 0) printf("Same content.\n");
  else printf("Different content.\n");
}

void checkIdentity(char str1[], char str2[]) {
  if (str1 == str2) printf("Strings are identical.\n");
  else printf("Strings are not identical.\n");
}

int main() {
  char str1[] = "Hi";
  char str2[] = "Hi";
  checkIdentity(str1, str2); 
  checkIdentity(str1, str1); 
  compareContent(str1, str2); 
}