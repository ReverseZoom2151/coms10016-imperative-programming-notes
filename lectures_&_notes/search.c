#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int linearSearch1(char c, int n, char a[n]) {
  int result = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] == c) result = i;
  }
  return result;
}

int linearSearch2(char c, int n, char a[n]) {
  int result = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] == c) return i; 
  }
  return result;
}

int linearSearch3(char c, int n, char a[n]) {
  int result = -1;
  int found = 0; 
  for (int i = 0; (i < n) && (!found); i++) {
    if (a[i] == c) {
      result = i;
      found = 1;
    }
  }
  return result;
}

int linearSearch4(char c, int n, char a[n]) {
  int result = -1;
  bool found = false;
  for (int i = 0; (i < n) && (!found); i++) {
    if (a[i] == c) {
      result = i;
      found = true;
    }
  }
  return result;
}

int binarySearch(char c, int n, char a[n]) {
  int start = 0, end = n, mid;
  bool found = false;
  while ((!found) && (end > start)) {
    mid = start + (end - start) / 2;
    if (c == a[mid]) found = true;
    else if (c < a[mid]) end = mid;
    else start = mid + 1;
  }
  if (!found) mid = -1;
  return mid;
}

int main(int n, char *args[]) {
  if ((n < 3) || (strlen(args[2]) != 1)) {
    fprintf(stderr,"Usage: ./program string character\n"); 
    return -1; 
  }
  else {
    if (strlen(args[2]) < 1) return -1; 
    int l = strlen(args[1]);
    char c = args[2][0];
    printf("Char %c search1 yields %d\n", c, linearSearch1(c, l, args[1]));
    printf("Char %c search2 yields %d\n", c, linearSearch2(c, l, args[1]));
    printf("Char %c search3 yields %d\n", c, linearSearch3(c, l, args[1]));
    printf("Char %c search4 yields %d\n", c, linearSearch4(c, l, args[1]));
    printf("Char %c binary search yields %d\n", c, binarySearch(c, l, args[1]));
  }
  return 0;
}