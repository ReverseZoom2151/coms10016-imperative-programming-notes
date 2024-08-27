#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[1]) {
	int hist[128] = {0}, cnt = 0;

	FILE *in = fopen(argv[1], "r");
	if (in == NULL) {
		fprintf(stderr, "Cannot open %s\n", argv[1]);
		exit(1);
	}

	fseek(in, 0, SEEK_END); 
	int len = ftell(in); 
	rewind(in); 

  char ch = fgetc(in);
  while (! feof(in)) {
    if ((ch > 31) && (ch < 123)) hist[(int)ch] += 1; 
		ch = fgetc(in);
		if (cnt % 1000 == 0) printf("Processed %d/%d\n", cnt, len);
		cnt++;
  }
  fclose(in);

	FILE *ofp = fopen("out.txt", "w");
	if (ofp == NULL) {
		fprintf(stderr, "Cannot write out.txt\n");
		exit(1);
	}

	fprintf(ofp, "character\tcount\r\n");
	for (int i = 32; i < 123; ++ i){
		fprintf(ofp, "%c\t%d\r\n", i, hist[i]);
	}
	fclose(ofp);
}