#include <stdio.h>

int pack(char v[4]) {
  unsigned int r = 0;
  for (int i = 0; i < 4; i++) {
    unsigned int p = (unsigned char)v[i];
    r = (p << (8 * i)) | r;
  }
  return (int)r;
}

void unpack(int packed, char v[4]) {
  unsigned int m = 0xFF, p = (unsigned int)packed;
  for (int i = 0; i < 4; i++) {
    v[i] = (char)(m & p);
    if (i < 3) p = p >> 8;
  }
}

int main(void) {
  char v[4] = {127,0,-128,-1};
  int p = pack(v);
  unpack(p,v);
  for (int i = 0; i < 4; i++) {
    printf("%hhi\n",v[i]);
  }
  return 0;
}