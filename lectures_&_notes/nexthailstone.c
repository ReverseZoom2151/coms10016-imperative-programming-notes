#include <stdio.h>

int nextHailstone(int x) {
  int next;
  if (x % 2 == 1) {
    int base = 3 * x;
    next = base + 1;
  }
  else next = x / 2;
  return next;
}

int main(void) {
  int n;
  printf("Enter n:\n");
  scanf("%d", &n);
  printf("The next hailstone number is %d.\n", nextHailstone(n)); 
  return 0;
}