#include <stdio.h>
#include <stdlib.h>

int compare(const void *p, const void *q) {
    const int *pi = p, *qi = q;
    int x = *pi, y = *qi;
    if (x < y) return -1;
    else if (x == y) return 0;
    else return 1;
}

int main() {
    int ns[] = { 8, 2, 6, 5, 9, 1, 7 }; 
    int itemSize = sizeof(int);
    int length = sizeof(ns) / itemSize;
    qsort(ns, length, itemSize, compare);
    for (int i = 0; i < length; i++) {
      printf("%d ", ns[i]);
    }
    printf("\n");
}