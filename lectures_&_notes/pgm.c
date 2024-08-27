#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>  

#define H 480
#define W 640

int main() {

	double image[H][W], max = 0;
	unsigned char imageOut[H][W];

	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			image[i][j] = abs(sin( ((double)j) / (H/10)) * ((double)i));
			if (image[i][j] > max) max = image[i][j];
		}
	}

	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			imageOut[i][j] = (image[i][j] / max) * 255;
		}
	}

	FILE *ofp = fopen("image.pgm", "wb");
	if (ofp == NULL) {
		fprintf(stderr, "Cannot write image.pgm\n");
		exit(1);
	}

	fprintf(ofp,"P5 %d %d 255\n", W, H);
	fwrite(imageOut, 1, H*W, ofp);
	fclose(ofp);

	return 0;
}
