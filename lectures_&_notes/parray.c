#include <stdio.h>

int main(int n, char *args[]) {
  char s[] = "BRexit"; 
  char *t = "BRexit"; 
  t = s; 
  t[1] = 'r'; 
  printf("%c %c %c\n", s[1], t[1], *(t+1));
  int i = 3, *p = &i, **q = &p;
  printf("%d %d %d\n", i, *p, **q);
  int *w[] = {p, &i, *q}; 
  printf("%p %p %p\n", (void*) w[0],(void*) w[1],(void*) w[2]);
  int y[] = {1, 2, 3}; 
  int (*x)[] = &y;
  printf("%d %d %d\n", (*x)[0], (*x)[1], (*x)[2]);
  int *(*z)[] = &w; 
  printf("%p %d\n",(void*) (*z)[0], *(*z)[0]);
  int **r[] = {q, q, q}; 
  printf("%d\n", *(*(r[0])));
  int (*a[])[] = {x, x}; 
  printf("%d %d\n", (*a[0])[0], (*a[0])[1]);
  return 0;
}