#include <stdio.h>

int main(void) {
  int i, j, k = 137;
  int a[3] = {2, 4, 6};
  int *p; 
  i = j = k; 
  p = &k; 
  printf("k is stored at address %p\n", p);
  *p = 138; 
  printf("k now stores %d\n", k);
  p = &a[2]; 
  *p = 3; 
  printf("a[2] now stores %d\n", a[2]);
  p = &a[0]; 
  printf("a[0] stores %d at address %p\n", *p, p);
  p = a; 
  printf("a[0] stores %d at address %p\n", *p, p);
  printf("a[0] stores %d at address %p\n", *a, a);
  printf("a[1] stores %d\n", p[1]);
  p++; 
  printf("a[1] stores %d at address %p\n", *p, p);
  p = a;
  printf("pointer p consists of %lu Bytes\n", sizeof(p));
  printf("array a consists of %lu Bytes\n", sizeof(a));
  printf("first element of a consists of %lu Bytes\n", sizeof(*p));
  return 0;
}