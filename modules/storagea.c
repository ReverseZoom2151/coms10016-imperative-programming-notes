#include <stdio.h>

int a = 5;

int m();

static int f() {
  extern int a;
  auto int b = a;
  b++;
  return b;
}

extern int g() {
  static int c = 5;
  c++;
  return c;
}

int main() {
  extern int d;

  register int l = m();

  l += g();
  l += f();

  printf("%d %d %d %d\n", d, l, g(), f());
  return 0;
}
