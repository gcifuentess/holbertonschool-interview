#include "sort.h"

/**
 * heap_sort - sift-down heap sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array to be sorted
 *
 */
void heap_sort(int *array, size_t size)
{
	size_t last;

	if (!array || size < 2)
		return;

	sort(array, size);

	for (last = size - 1; last > 1;)
	{
		swap(array, size, &array[last], &array[0]);
		sift_down(array, 0, --last, size);
	}
}


/**
 * swap - to swap two integers
 * @array: array to be sorted
 * @size: the size of the array to be sorted
 * @first: pointer of the first integer
 * @second: pointer of the second integer
 *
 */
void swap(int *array, size_t size, int *first, int *second)
{
	int temp;

	if (*first != *second)
	{
		temp = *first;
		*first = *second;
		*second = temp;
	}

	print_array((const int *)array, size);
}

/**
 * sift_down - heap sort shift down
 *
 * @array: the array to be sorted
 * @first: first element of the array
 * @last: last element of the array
 * @size: size of array
 *
 */
void sift_down(int *array, size_t first, size_t last, size_t size)
{
	size_t root = first, swp;

	swp = root;
	for (; left_ch(root) < last; root = swp)
	{
		swp = root;

		if (array[left_ch(root)] > array[root])
			swp = left_ch(root);

		if (right_ch(root) < last &&
		    array[right_ch(root)] > array[swp])
			swp = right_ch(root);

		if (swp == root)
			break;

		swap(array, size, &array[root], &array[swp]);
	}
}

/**
 * sort - heap sort in place
 *
 * @array: the array to be sorted
 * @size: size of the array
 *
 */
void sort(int *array, size_t size)
{
	ssize_t first;

	for (first = parent(size - 1); first >= 0; first--)
		sift_down(array, first, size, size);
}
