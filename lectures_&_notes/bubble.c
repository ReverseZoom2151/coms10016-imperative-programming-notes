#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int item; 

void swap(int i, int j, item xs[]) {
  item temp = xs[i];
  xs[i] = xs[j];
  xs[j] = temp;
}

void bubbleSort(int n, item xs[n]) {

  for(int i = n - 2; i >= 0; i--) {
    for(int j = 0; j <= i; j++) {
      if (xs[j] > xs[j + 1]) swap(j, j + 1, xs);
    }
  }
}

bool check(int n, item source[n], item target[n]) {
  for (int i = 0; i < n; i++) {
    if (source[i] != target[i]) return false;
  }
  return true;
}

void print(int n, item a[n]) {
  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);
    if (i < n-1) printf(", ");
  }
  printf("\n");
}

void init(int n, item source[n], item target[n]) {
  for (int i = 0; i < n; i++) {
    target[i] = source[i];
  }
}

void test() {
  printf("\nBASIC SORTING ALGORITHM TEST\n");
  printf("----------------------------\n");
  item a[5];
  init(5, (int[]) {5, 7, 3, 1, 4}, a);
  printf("Original Array:   ");
  print(5, a);
  bubbleSort(5, a);
  printf("After BubbleSort: ");
  print(5, a);
  for(int i = 1; i < 5; i++) {
    assert(check(5, a, (int[]) {1, 3, 4, 5, 7}));
  }
}

int main() {
  test();
  return 0;
}