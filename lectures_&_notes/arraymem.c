#include <stdio.h>

const int ENTRIES = 10;

void initialise(int n, void *a[], void *b[]) {
  for (int i = 0; i < n; i++) {
    a[i] = &b[i];
    b[i] = &a[i];
  }
}

void print(int n, void *a[]){
  for (int i = 0; i < n; i++) {
    printf("%p", a[i]);
    if (i < n - 1) printf(", ");
  }
  printf("\n");
}

int main(void) {
 void *a[ENTRIES], *b[ENTRIES];
 initialise(ENTRIES, a, b);
 print(ENTRIES, a);
 print(ENTRIES, b);
 return 0;
}