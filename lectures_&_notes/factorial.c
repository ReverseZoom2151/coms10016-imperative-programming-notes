#include <stdio.h>

long int factorial(int n) {
  if (n == 1) return 1; 
  return n * factorial(n - 1); 
}

int main() {
  int n;
  printf("Enter an integer (>0): ");
  scanf("%d", &n);
  printf("Factorial of %d is %ld\n", n, factorial(n));
  return 0;
}