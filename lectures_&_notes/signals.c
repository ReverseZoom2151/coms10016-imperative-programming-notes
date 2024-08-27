#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

void customFunction(int signalValue) { 
  printf("Signal value %d received. End program? (0 = no, 1 = yes):\n", signalValue);
  int finito;
  scanf("%d",&finito);
  if (finito == 1) exit(0); 
  else signal(SIGINT, customFunction); 
}

int main() {
  signal(SIGINT, customFunction);
  bool quit = false;
  while (!quit) {
    printf("\nHello from the loop.\n");
    raise(SIGINT); 
  }
  return 0;
}