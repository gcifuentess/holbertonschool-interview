#ifndef SORT_H
#define SORT_H

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#define RAD 10

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
void sort_count(int *array, ssize_t size, int *array_b, long exp);

#endif /*SORT_H*/
