struct text;
typedef struct text text;

text *newText(char *s);

void freeText(text *t);

int length(text *t);

char get(text *t, int i);

void set(text *t, int i, char c);

text *copy(text *t);

int compare(text *t1, text *t2);

void append(text *t1, text *t2);

text *slice(text *t, int i, int j);

int find(text *t, text *p);