#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdio.h>
#include <stdlib.h>

#define SLIDE_LEFT 2
#define SLIDE_RIGHT 3

int slide_line(int *line, size_t size, int direction);
void slide_and_merge(int *line, int start, int end, int step);

#endif /* SLIDE_LINE_H */
