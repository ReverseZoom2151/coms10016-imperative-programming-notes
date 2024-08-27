extern int a;

int d = 25;
int *ap = &a;

static int n() {
  return *ap;
}

int m() {
  return *ap + n();
}
