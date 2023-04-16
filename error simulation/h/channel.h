#ifndef CHANNEL_H
#define CHANNEL_H

#include <stdio.h>

void simulate(FILE* in, FILE* out, double ber);
char get_error(double ber);

#endif
