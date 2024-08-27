#include <stdio.h>

void move(int n, int source, int target, int aux)
{
  if (n == 1)
    printf("Move disk 1 from stack %d to stack %d\n", source, target); 
  else {
    move(n - 1, source, aux, target); 
    printf("Move disk %d from stack %d to stack %d\n", n, source, target); 
    move(n - 1, aux, target, source); 
  }
}

int main()
{
    int n;
    printf("Enter the number of disks:\n");
    scanf("%d", &n);
    printf("Solution sequence of moves is:\n");
    move(n, 1, 3, 2);
    return 0;
}