#include <stdio.h>

int main() {
    const int max = 100;
    char line[max], name[50];
    int n;
    FILE *in = fopen("in.txt", "r");
    fgets(line, max, in);
    while (! feof(in)) {
        sscanf(line, "%d %s", &n, name);
        printf("Number %d name %s\n", n, name);
        fgets(line, max, in);
    }
    fclose(in);
}