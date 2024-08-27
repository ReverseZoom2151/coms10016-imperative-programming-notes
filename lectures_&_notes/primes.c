#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int findSize(int n, char *args[n]) {
  if (n != 2) {
    fprintf(stderr, "Use: ./primes max\n");
    exit(1);
  }
  return atoi(args[1]) + 1;
}

void uncrossAll(int size, bool crossedOut[size]) {
  for (int i = 0; i < size; i++) {
    crossedOut[i] = false;
  }
  crossedOut[0] = crossedOut[1] = true;
}

void crossOutMultiples(int size, bool crossedOut[size], int n) {
  for (int m = 2 * n; m < size; m = m + n) {
    crossedOut[m] = true;
  }
}

int findIterationLimit(int size) {
  double root = sqrt((double)size);
  return (int) root;
}

void crossOutComposites(int size, bool crossedOut[size]) {
  int limit = findIterationLimit(size);
  for (int i = 2; i <= limit; i++) {
    if (! crossedOut[i]) crossOutMultiples(size, crossedOut, i);
  }
}

void generatePrimes(int size, bool crossedOut[size]) {
  uncrossAll(size, crossedOut);
  crossOutComposites(size, crossedOut);
}

void printPrimes(int size, bool crossedOut[size]) {
  for (int i = 2; i < size; i++) {
    if (! crossedOut[i]) printf("%d\n", i);
  }
}

void test() {
    bool expected[12] = {1,1,0,0,1,0,1,0,1,1,1,0};
    bool crossedOut[12];
    generatePrimes(12, crossedOut);
    for (int i = 0; i < 12; i++) if (crossedOut[i] != expected[i]) {
        fprintf(stderr, "Wrong result for %d\n", i);
        exit(1);
    }
    printf("All tests pass.\n");
}

int main(int n, char *args[n]) {
  if (n == 1) test();
  int size = findSize(n, args);
  bool crossedOut[size];
  generatePrimes(size, crossedOut);
  printPrimes(size, crossedOut);
}