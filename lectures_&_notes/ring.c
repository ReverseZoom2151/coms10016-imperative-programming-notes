#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int ENTRIES = 8;
const int TRIALS = 100;

void initialise(int n, void *a[]) {
  for (int i = 0; i < n; i++) {
    a[i] = &a[i];
  }
}

int cycle(int n, void *a[], char visited[]) {
  int isCycle = 1;
  for (int i = 0; i < n; i++)
    visited[i] = 0;
  void *p = a[0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[j] == p) visited[j]++;
    }
    p = *(void**)p;
  }
  for (int i = 0; i < n; i++)
    if (visited[i] != 1) isCycle = 0;
  return isCycle;
}

void shuffle(int n, void *a[]) {
  for (int i = 0; i < n; i++) {
    int j = rand() % n;
    void *c = a[i];
    a[i] = a[j];
    a[j] = c;
  }
}

void print(int n, void *a[]){
  for (int i = 0; i < n; i++) {
    printf("%p",a[i]);
    if (i < n - 1) printf(", ");
  }
  printf("\n");
}

int trial(int n, void *a[], char v[]){
  int trials = 0;
  int tests = 0;
  while (trials < TRIALS) {
    initialise(n, a);
    shuffle(n, a);
    while (cycle(n, a, v) != 1) {
      shuffle(n, a);
      tests++;
    }
    trials++;
  }
  return tests/trials;
}

int main(void) {
  void *a[ENTRIES];
  char v[ENTRIES];
  srand(time(NULL));
  initialise(ENTRIES, a);
  printf("AVG NUMBER OF SHUFFLES: %d\n", trial(ENTRIES, a, v));
  return 0;
}