#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    char ch = getchar();
    while (! feof(stdin)) {
        printf("%c", toupper(ch));
        ch = getchar();
    }
}