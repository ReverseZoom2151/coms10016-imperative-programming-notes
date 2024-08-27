#include <stdio.h>

int sum(int n) {
  printf("Address of argument n=%d is %p.\n", n, &n);
  if (n == 1) return 1;
  return n + sum(n - 1);
}

int main() {
  sum(5);
  return 0;
}