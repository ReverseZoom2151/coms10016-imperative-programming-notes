#include <stdio.h>
#include <string.h>

typedef union data { 
  int i;
  float f;
  char str[4];
} data;

int main() {
  data d;
  d.i = 16;
  d.f = 11.11;
  strcpy(d.str, "Hi!"); 
  printf("d.i = %d\n", d.i);
  printf("d.f = %f\n", d.f);
  printf("d.str = %s\n", d.str);
  return 0;
}