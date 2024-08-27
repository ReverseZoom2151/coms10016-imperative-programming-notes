#include <stdio.h>

int hailstone(int seed, int n) {
  int next;
  if (seed % 2 == 1) next = 3 * seed + 1;
  else next = seed / 2;
  if (n == 1) return next;
  else return hailstone(next, n - 1);
}

int main(void) {
  int seed, n;
  printf("Enter seed:\n");
  scanf("%d", &seed);
  printf("Enter how many steps to go:\n");
  scanf("%d", &n);
  printf("The %dth hailstone number for seed %d is: %d\n", n, seed, hailstone(seed, n));
  return 0;
}