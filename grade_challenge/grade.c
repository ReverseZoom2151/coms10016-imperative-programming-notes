#include <stdio.h> 

int grade(int mark);

int main() { 
  int mark;
  printf("Enter your mark:\n");
  scanf("%d", &mark); 
  printf("Your grade is: %d\n", grade(mark)); 
  return 0; 
}

int grade(int mark) { 
  int grade; 
  if (mark >= 70) grade = 1; 
  else if (mark >= 50) grade = 2; 
  else if (mark >= 40) grade = 3; 
  else grade = 4; 
  return grade; 
}