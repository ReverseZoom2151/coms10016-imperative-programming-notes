#include <stdio.h>

double avg(int n, double numbers[n]) {
  double sum = 0;
  for(int i = 0; i < n; i++) {
    sum += numbers[i];
  }
  return sum / n;
}

int main(void) {
  int n;
  printf("How many numbers to average:\n");
  scanf("%d", &n);
  double numbers[n];
  for(int i = 0; i < n; i++) {
    printf("Enter number no %d:\n", i + 1);
    scanf("%lf", &numbers[i]);
  }
  printf("Average is: %lf\n", avg(n, numbers));
  return 0;
}