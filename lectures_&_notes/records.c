#include <stdio.h>

int main() {
  const int max = 100;
  char line[max], name[max], address[max];
  int n;
  FILE *in = fopen("in_add.txt", "r");
  fgets(line, max, in);
  while (! feof(in)) {
    sscanf(line, "%d, %40[^\r\n,], %40[^\r\n,]", &n, name, address);
    printf("Number [%d] name [%s] address [%s]\n", n, name, address);
    fgets(line, max, in);
  }
  fclose(in);
}