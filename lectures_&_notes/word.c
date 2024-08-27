#include <stdio.h>
#include <string.h>

typedef struct word {
  char s[30];
  int count;
} word; 

void check(word *w, char *s) {
  if (strcmp(w->s, s) == 0) w->count++;
}

int main(int n, char *args[]) {
  word wordData;
  sprintf(wordData.s, "Brexit");
  wordData.count = 0;
  word *w = &wordData;
  for(int i = 0; i < n; i++) {
    check(w, args[i]);
  }
  printf("Struct word is %d bytes long.\n", (int)sizeof(word));
  printf("Found Brexit %d times in args.\n", w->count);
}