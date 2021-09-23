#include "holberton.h"

/**
 * _strlen - returns the length of a string
 * @s: The original string
 *
 * Return: length of s.
 */
int _strlen(char *s)
{
	int length = 0, i;

	for (i = 0; s[i] != '\0'; i++)
		length = i + 1;

	return (length);
}

/**
 * _calloc - allocates memory for an array, using malloc.
 * @nmemb: number of elements of the array.
 * @size: size in bytes of each element of the array.
 *
 * Description: -The _calloc function allocates memory for an array
 *               of nmemb elements of size bytes each and returns a
 * pointer to the allocated memory.
 *-The memory is set to zero.
 *-If nmemb or size is 0, then _calloc returns NULL.
 *-If malloc fails, then _calloc returns NULL
 *
 * Return: pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	char *tmp_ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (!ptr)
		return (NULL);

	tmp_ptr = (char *)ptr;

	for (i = 0; i < (nmemb * size); i++)
		tmp_ptr[i] = 0;

	return (ptr);
}
