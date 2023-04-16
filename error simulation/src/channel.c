#include <stdlib.h>
#include "channel.h"

void simulate(FILE* in, FILE* out, double ber) {
	char byte, error;
	while(fread(&byte, sizeof(byte), 1, in)) {
		error = get_error(ber);
		byte ^= error;
		fwrite(&byte, sizeof(byte), 1, out);
	}
}

char get_error(double ber) {
	char error = 0;
	int treshold;
	treshold = RAND_MAX * ber;
	for(int i = 0 ; i < sizeof(error)*8 ; i++) {
		if(rand() < treshold){
			error |= 1<<i;
		}
	}
	return error;
}
