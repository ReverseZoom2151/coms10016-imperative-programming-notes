#include <stdio.h>
#include <string.h>

typedef struct data {
  unsigned int a;
  unsigned int b;
  unsigned int c;
  unsigned int d;
} data;

typedef struct bitfield {
  unsigned int a : 2; 
  unsigned int b : 2; 
  unsigned int c : 14;
  unsigned int d : 14;
} bitfield; 

int main() {
  data x = { 3, 4, 16383, 16384};
  bitfield y = { 3, 4, 16383, 16384}; 
  printf("data x size = %d\n", (int)sizeof(x));
  printf("bitfield y size = %d\n", (int)sizeof(y));
  printf("data x: .a=%d, .b=%d, .c=%d, .d=%d\n", x.a, x.b, x.c, x.d);
  printf("bitfield y: .a=%d, .b=%d, .c=%d, .d=%d\n", y.a, y.b, y.c, y.d);
  return 0;
}