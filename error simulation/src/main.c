#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "channel.h"

int main(int argc, const char* argv[]) {
	srand(time(0));
	double ber;
	char outname[FILENAME_MAX];
	ber = atof(argv[1]);
	sprintf(outname, "%s.err", argv[2]);
	FILE* in;
	FILE* out;
	in = fopen(argv[2], "rb");
	out = fopen(outname, "wb");
	simulate(in, out, ber);
	fclose(in);
	fclose(out);
	return 0;
}
