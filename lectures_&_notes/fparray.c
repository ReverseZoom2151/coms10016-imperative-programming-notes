#include <stdio.h>

int add(int x, int y) { return x+y; }
int subtract(int x, int y) { return x-y; }
int multiply(int x, int y) { return x*y; }
int divide(int x, int y) { return x/y; }

typedef int op(int x, int y);

enum opcode { Plus, Minus, Times, Over };

op *ops[] = { add, subtract, multiply, divide };

int main() {
    op *f = ops[Times]; 
    int n = f(6, 7); 
    printf("Answer 6 x 7 = %d\n", n); 
}