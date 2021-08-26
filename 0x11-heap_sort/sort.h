#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

#define parent(x) (((x) - 1) / 2)
#define left_ch(x) (((x) * 2) + 1)
#define right_ch(x) (((x) * 2) + 2)


void heap_sort(int *array, size_t size);
void swap(int *array, size_t size, int *first, int *second);
void sift_down(int *array, size_t first, size_t last, size_t size);
void sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif /* SORT_H */
