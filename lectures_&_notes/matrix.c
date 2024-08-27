#include <stdio.h>

void print(int h, int w, int matrix[h][w]) { 
  for (int r = 0; r < h; r++) { 
    for (int c = 0; c < w; c++) { 
      if (c > 0) printf(" "); 
      printf("%d", matrix[r][c]); 
    } 
    printf("\n"); 
  } 
} 

int main() {
  int matrix[3][2] = {{1, 4}, {5, 3}, {9, 2}};  
  print(3, 2, matrix);
  return 0;
}