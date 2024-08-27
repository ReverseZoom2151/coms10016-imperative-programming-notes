#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

const int FAILURE_CODE = 1; 

typedef int item;

typedef struct cell {
  item x;
  struct cell *next;
} cell;

typedef struct stack {
  cell *first;
} stack;

void error(char *message) {
  fprintf(stderr, "List failure: %s\n", message);
  exit(FAILURE_CODE);
}

stack *newStack() {
  stack *s = malloc(sizeof(stack));
  s->first = NULL;
  return s;
}

bool isEmpty(stack *s) {
  return (s->first == NULL);
}

void push(stack *s, item n) {
  cell *c = malloc(sizeof(cell)); 
  *c = (cell) {n, s->first};
  s->first = c;
}

item peek(stack *s) {
  if (s->first == NULL) error("peek on empty stack");
  return s->first->x;
}

item pop(stack *s) {
  cell *c = s->first;
  if (c == NULL) error("pop on empty stack");
  s->first = c->next; 
  item x = c->x; 
  free(c);
  return x;
}

void freeStack(stack *s) {
  cell *c = s->first;
  while (c != NULL) { 
    cell *next = c->next; 
    free(c); 
    c = next; 
  }
  free(s);
}

bool check(stack *s, int n, item target[n]) {
  bool ok = true;
  cell *c = s->first;
  for (int i = 0; i < n; i++) {
    if ((c->x) != (target[i])) ok = false; 
    c = c->next;
  }
  if (c != NULL) ok = false;
  return ok;
}

void test() {
    stack *s = newStack();
    push(s, 41);
    assert(check(s, 1, (int[]) {41}));
    push(s, 43);
    assert(check(s, 2, (int[]) {43, 41}));
    assert(peek(s) == 43);
    assert(check(s, 2, (int[]) {43, 41}));
    assert(pop(s) == 43);
    assert(check(s, 1, (int[]) {41}));
    freeStack(s);
}

int main() {
  test();
  return 0;
}