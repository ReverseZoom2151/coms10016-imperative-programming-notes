#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

bool *q; 

void customFunction(int signalValue) {
  *q = 1; 
  signal(SIGINT, customFunction);
}

int main() {
  signal(SIGINT, customFunction);
  const bool volatile quit = false;
  __asm__ (
      "nop\n"
      : "=a" (q)
      : "a"  (&quit)
  );
  while (!quit) {
    printf("\nHello from the loop.\n");
    raise(SIGINT);
  }
  return 0;
}