#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word {int count; char s[];} word;

word *newWord(char *s) {
  int n = strlen(s) + 1; 
  word *w = malloc(sizeof(word) + n); 
  strcpy(w->s, s); 
  w->count = 0; 
  return w;
}

int main() {
  word *w = newWord("hello");
  printf("%s %d\n", w->s, w->count);
  free(w); 
}