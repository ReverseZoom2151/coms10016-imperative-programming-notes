#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

const int INITIAL_CAPACITY = 8;
const int GROWTH_RATE = 50;
const int FAILURE_CODE = 1;

typedef int item;

typedef struct list {
  int length, capacity;
  item *items;
} list;

list *newList() {
  list *l = malloc(sizeof(list));
  item *items = malloc(INITIAL_CAPACITY * sizeof(item));
  *l = (list) {0, INITIAL_CAPACITY, items};
  return l;
}

void freeList(list *l) {
  free(l->items);
  free(l);
}

int length(list *l) {
  return l->length;
}

void expand(list *l) {
  l->capacity = l->capacity * (100 + GROWTH_RATE) / 100;
  l->items = realloc(l->items, l->capacity * sizeof(item));
}

void add(list *l, item n) {
  if (l->length >= l->capacity) expand(l);
  l->items[l->length] = n;
  l->length++;
}

void error(char *message) {
  fprintf(stderr, "List failure: %s\n", message);
  exit(FAILURE_CODE);
}

void insert(list *l, int i, item n) { 
  if (l->length >= l->capacity) expand(l);
  if ((i < 0) || (i > l->length) || ((i == l->length) && (i != 0))) error("insert");
  for (int j = l->length; j > i; j--) {
    l->items[j] = l->items[j - 1];
  }
  l->items[i] = n;
  l->length++;
}

void delete(list *l, int i) { 
  if ((i < 0) || (i >= l->length)) error("remove");
  for (int j = i; j < l->length - 1; j++) {
    l->items[j] = l->items[j + 1];
  }
  l->length--;
}

item get(list *l, int i) {
  if ((i < 0) || (i >= l->length)) error("get");
  return l->items[i];
}

void set(list *l, int i, item n) {
  if ((i < 0) || (i >= l->length)) error("set");
  l->items[i] = n;
}

bool check(list *l, int n, item target[n]) {
  bool ok = true;
  if (l->length != n) ok = false;
  if (l->capacity < n) ok = false;
  for (int i = 0; i < n; i++) {
    if (l->items[i] != target[i]) ok = false;
  }
  return ok;
}

void test() {
  list *l = newList();
  assert(check(l, 0, NULL));
  insert(l, 0, 37);
  assert(check(l, 1, (int[]) {37}));
  add(l, 41);
  assert(check(l, 2, (int[]) {37, 41}));
  set(l, 1, 91);
  assert(check(l, 2, (int[]) {37, 91}));
  assert(get(l, 1) == 91);
  expand(l);
  assert(check(l, 2, (int[]) {37, 91}));
  insert(l, 1, 93);
  assert(check(l, 3, (int[]) {37, 93, 91}));
  delete(l, 1);
  assert(check(l, 2, (int[]) {37, 91}));
  delete(l, 1);
  assert(check(l, 1, (int[]) {37}));
  delete(l, 0);
  assert(check(l, 0, NULL));
  freeList(l);
}

int main() {
  test();
  return 0;
}