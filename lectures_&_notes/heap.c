#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char *s[15];
  for(int i = 0; i < 15; i++) {
    s[i] = malloc(3);
    sprintf(s[i],"%d",i);
    printf("%s %p\n", s[i], s[i]);
  }
  for(int i = 0; i < 15; i++) {
    free(s[i]);
  }
  return 0;
}