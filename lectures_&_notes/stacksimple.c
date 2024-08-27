#include <stdio.h>
#include <stdlib.h>

struct stackelem {
    int value;
    struct stackelem *prev;
};
typedef struct stackelem Elem;

struct thestack {
    Elem *tp;
};

typedef struct thestack Stack;

void InitialiseStack(Stack *s);
void Push(Stack *s, int n);
int Pop(Stack *s);

int main(void) {
    Stack s;
    InitialiseStack(&s);

    Push(&s, 12);
    Push(&s, 117);
    Push(&s, 13);
    Push(&s, 15);
    printf("%d\n", Pop(&s));
    printf("%d\n", Pop(&s));
    printf("%d\n", Pop(&s));
    printf("%d\n", Pop(&s));
    printf("%d\n", Pop(&s));
    Push(&s, 15);
    printf("%d\n", Pop(&s));
    
    return 0;
}

void InitialiseStack(Stack *s) {
    s->tp = NULL;
}

void Push(Stack *s, int n) {
    Elem *e;
    e = (Elem *) malloc(sizeof(Elem));
    e->prev = s->tp;
    s->tp = e;
    s->tp->value = n;
}

int Pop(Stack *s) {
    int retValue;
    Elem * curr; 
    if (s->tp == NULL) {
        return -1000; 
    }
    curr = s->tp; 
    retValue = s->tp->value;
    s->tp = s->tp->prev;
    free(curr); 
    return retValue;
}