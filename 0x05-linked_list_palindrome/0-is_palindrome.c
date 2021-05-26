#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: the head pointer of the linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	const listint_t *current;
	unsigned int n; /* number of nodes */
	unsigned int *buffer;  /* temp array */
	unsigned int pivot; /* pivot of the palindrome */
	unsigned int i, j;

	if (!(*head))
		return (1);

	n = 0;
	for (current = *head; current; current = current->next)
		n++;

	buffer = malloc(sizeof(n) * n);
	if (!buffer)
		return (1);

	for (i = 0, current = *head; current; i++, current = current->next)
		buffer[i] = current->n;

	if (n % 2 == 0)
		pivot = n / 2;
	else
		pivot = (n / 2) + 1;

	for (i = 0; i < pivot; i++)
	{
		j = n - i - 1;
		if (buffer[i] != buffer[j])
		{
			free(buffer);
			return (0);
		}
	}
	free(buffer);
	return (1);
}
