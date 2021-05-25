#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: the head pointer of the linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	const listint_t *current, *respective;
	unsigned int n; /* number of nodes */
	unsigned int pivot; /* pivot of the palindrome */
	unsigned int i, j;

	if (!(*head))
		return (1);

	n = 0;
	for (current = *head; current; current = current->next)
		n++;
	if (n % 2 == 0)
		pivot = n / 2;
	else
		pivot = (n / 2) + 1;

	for (i = 0, current = *head; i < pivot; i++, current = current->next)
	{
		respective = current;
		for (j = i; j < (n - i - 1); j++)
			respective = respective->next;
		if (current->n != respective->n)
			return (0);
	}
	return (1);
}
