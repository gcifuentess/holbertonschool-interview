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
	int n; /* number of nodes */
	int *buffer;  /* temp array */
	int pivot; /* pivot of the palindrome */
	int i;

	if (!(*head) || (*head)->next == NULL)
		return (1);

	n = 0;
	for (current = *head; current; current = current->next)
		n++;

	pivot = n / 2 - 1;

	buffer = malloc(sizeof(pivot) * pivot);
	if (!buffer)
		return (0);

	for (i = 0, current = *head; i <= pivot; i++, current = current->next)
		buffer[i] = current->n;

	if (n % 2 != 0)
		current = current->next;

	for (i = pivot; i >= 0; i--)
	{
		if (buffer[i] != current->n)
		{
			free(buffer);
			return (0);
		}
		current = current->next;
	}
	free(buffer);
	return (1);
}
