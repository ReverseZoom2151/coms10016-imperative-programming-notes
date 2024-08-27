#include <stdio.h> 

int sum(int n) { 
  if (n == 1) return 1; 
  else return n + sum(n - 1); 
} 

int main(void) { 
  int n;
  printf("Enter n:\n");
  scanf("%d", &n); 
  printf("The %dth triangle number is: %d\n", n, sum(n)); 
  return 0; 
}