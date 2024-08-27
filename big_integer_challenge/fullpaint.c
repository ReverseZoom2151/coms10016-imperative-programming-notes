#include <stdio.h>

int area(int length, int width, int height) {
  int sides = 2 * length * height;
  int ends = 2 * width * height;
  int ceiling = length * width;
  return sides + ends + ceiling;
}

int main(void) {
  int lengths, width, height;
  printf("Enter room length:\n");
  scanf("%d", &lengths);
  printf("Enter room width:\n");
  scanf("%d", &width);
  printf("Enter room height:\n");
  scanf("%d", &height);
  int total = area(lengths, width, height);
  printf("The paint area is: %d\n", total);
  return 0;
}