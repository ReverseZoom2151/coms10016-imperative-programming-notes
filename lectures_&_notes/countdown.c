#define _POSIX_C_SOURCE 200809L
#include <unistd.h>
#include <stdio.h>

int main() { 
  int t = 10;
  while (t > 0) {
    sleep(1); // wait 1 second
    printf("%d\n", t);
    t--;
  }
  return 0;
}