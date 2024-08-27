#include <stdio.h>
#include <stdbool.h>

int main() {
    const int max = 100;
    FILE *in = fopen("in.txt", "r");
    char line[max];
    fgets(line, max, in);
    while (! feof(in)) {
        printf("Line: %s", line);
        fgets(line, max, in);
    }
    fclose(in);
}