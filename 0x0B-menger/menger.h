#ifndef MENGER_H
#define MENGER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void menger(int level);
char **menger_recursive(int level);
char **sponge_builder(char **sponge, int sponge_size,
		      char **sponge_prev, int sponge_prev_size);


#endif /* MENGER_H */
