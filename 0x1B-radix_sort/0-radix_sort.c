#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 *               sort algorithm
 * @array: the array to sort. Should contain only numbers >= 0
 * @size: size of array
 *
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int max = INT_MIN, *array_b;
	long exp;

	if (!array || size < 2)
		return;
	array_b = malloc(sizeof(*array_b) * size);
	if (!array_b)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	for (exp = 1; max / exp > 0; exp *= RAD)
	{
		sort_count(array, size, array_b, exp);
		print_array(array, size);
	}
	free(array_b);
}

/**
 * sort_count - sort by current digit
 * @array: array to sort
 * @size: size of array
 * @array_b: temp array
 * @exp: current digital exponent
 *
 * Return: nothing
 */
void sort_count(int *array, ssize_t size, int *array_b, long exp)
{
	ssize_t i;
	int count[RAD] = {0};

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % RAD]++, array_b[i] = 0;

	for (i = 1; i < RAD; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
		array_b[--count[(array[i] / exp) % RAD]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = array_b[i];
}
