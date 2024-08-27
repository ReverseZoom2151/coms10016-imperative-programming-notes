#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int input1 = 100, input2 = 100, output;
  __asm__ (
      "addl %%ebx, %%eax"
      : "=a" (output)
      : "a"  (input1), "b" (input2)
  );
  printf("Output=%d\n",output);
  return 0;
}