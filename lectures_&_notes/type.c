#include <stdio.h>
#include <stdbool.h>

void get(int max, char line[max]) {
    printf("Type: ");
    fgets(line, max, stdin);
}

int main() {
    const int max = 100;
    char line[max];
    get(max, line);
    while (! feof(stdin)) {
        printf("Line: %s", line);
        get(max, line);
    }
}