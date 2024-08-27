#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char *s = malloc(4); 
  strcpy(s,"cat");
  printf("%s\n", s);
  free(s);
  return 0;
}