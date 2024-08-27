#include <stdio.h>
#include <stdlib.h>

typedef struct item {int x, y;} item; 

item *newItem(int x0, int y0) { 
  item *fresh = malloc(sizeof(item)); 
  *fresh = (item) {x0, y0}; 
  return fresh; 
}

void move(item *i, int dx, int dy) { 
  i->x = i->x + dx; 
  i->y = i->y + dy; 
}

int main() { 
  item *i = newItem(41, 37); 
  move(i, 1, 15); 
  printf("%d %d\n", i->x, i->y); 
  free(i); 
}