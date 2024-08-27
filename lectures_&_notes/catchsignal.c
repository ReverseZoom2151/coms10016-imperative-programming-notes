#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

void customFunction(int signalValue) { 
  printf("Code executed before program ends...\n");
}

int main() {
  signal(SIGFPE, customFunction); 
  int a = 0;
  a /= a; 
  return 0;
}