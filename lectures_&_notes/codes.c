#include <stdio.h>
#include <stdbool.h>

int main() {
    FILE *in = fopen("in.txt", "r");
    char ch = fgetc(in);
    while (! feof(in)) {
        printf("%d\n", ch);
        ch = fgetc(in);
    }
    fclose(in);
}