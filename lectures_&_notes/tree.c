#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node {
  struct node *left;
  int key;
  struct node *right;
} node;

typedef struct tree {
  node *root;
} tree;

node *newNode(int value) {
  node *p = malloc(sizeof(node));
  *p = (node) {NULL, value, NULL};
  return p;
}

bool insertNode(node **p, int n) {
  if (*p == NULL) {
    *p = newNode(n);
    return true;
  }
  else if (n < (*p)->key) return insertNode(&((*p)->left), n);
  else if (n > (*p)->key) return insertNode(&((*p)->right), n);
  else return false;
}

node *findNode(node *p, int n) {
  if (p != NULL) { 
    if (n < p->key) p = findNode(p->left, n);
    else if (n > p->key) p = findNode(p->right, n);
  }
  return p;
}

int countNodes(node *p) {
  int n = 0;
  if (p != NULL) { 
    n += 1 + countNodes(p->left) + countNodes(p->right);
  }
  return n;
}

void printNode(node *p, char *s) {
  char space[2] = " ";
  if (strcmp(s, "") == 0) space[0] = '\0';
  if (p != NULL) sprintf(s,"%s%s%d", s, space, p->key);
}

void printNodes(node *p, char *s) {
  if (p != NULL) {
    if (p->left == NULL) printNode(p, s);
    else {
      printNodes(p->left, s);
      printNode(p, s);
    }
    if (p->right != NULL) printNodes(p->right, s);
  }
}

void freeNodes(node *p) {
  if (p != NULL) {
    freeNodes(p->left);
    freeNodes(p->right);
    free(p);
  }
}

tree *newTree() {
  tree *t = malloc(sizeof(tree));
  t->root = NULL;
  return t;
}

bool insert(tree *t, int n) {
  return insertNode(&(t->root), n);
}

bool contains(tree *t, int n) {
  return (findNode(t->root, n) != NULL);
}

void print(tree *t, char *s, bool printToScreen) {
  printNodes(t->root, s);
  if (printToScreen) printf("%s\n", s);
}

int count(tree *t) {
  return countNodes(t->root);
}

void freeTree(tree *t) {
  freeNodes(t->root);
  free(t);
}

bool check(tree *t, char *target) {
  char s[count(t) * 12 + 1]; 
  s[0] = '\0';
  print(t, s, false);
  return (strcmp(s, target) == 0);
}

void test() {
  tree *t = newTree();
  assert(check(t, ""));
  assert(count(t) == 0);
  assert(insert(t, 5));
  assert(check(t, "5"));
  assert(count(t) == 1);
  assert(insert(t, 3));
  assert(check(t, "3 5"));
  assert(contains(t, 7) == false);
  assert(insert(t, 7));
  assert(check(t, "3 5 7"));
  assert(insert(t, 3) == false);
  assert(check(t, "3 5 7"));
  assert(contains(t, 7));
  assert(count(t) == 3);
  freeTree(t);
}

int main() {
  test();
  return 0;
}