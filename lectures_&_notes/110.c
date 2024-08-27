#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int ENTRIES = 32;
const int ROUNDS  = 10;

void initialise(int n, char a[]) {
  for (int i = 0; i < n; i++) {
    a[i] = '0';
  }
  a[n/2] = '1';
}

void copy(int n, char a[], char b[]) {
  for (int i = 0; i < n; i++) b[i] = a[i];
}

void rule(int n, char a[], char b[]) {
  const char ONE[5][4] = {"110","101","011","010","001"};
  for (int i = 1; i < n - 1; i++) {
    char n = '0';
    for (int j = 0; j < 5; j++)
      if (!memcmp(b + i - 1, ONE[j], 3)) n = '1';
    a[i] = n;
  }
}

int main(void) {
  char a[ENTRIES + 1];
  char b[ENTRIES + 1];
  for (int i = 0; i <= ENTRIES; i++) {
    a[i] = 0;
    b[i] = 0;
  }
  initialise(ENTRIES, a);
  printf("%s\n", a);
  for (int i = 0; i < ROUNDS; i++) {
    copy(ENTRIES, a, b);
    rule(ENTRIES, a, b);
    printf("%s\n", a);
  }
  return 0;
}
