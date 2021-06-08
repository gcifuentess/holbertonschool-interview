#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: the list to be checked
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *hare;
	listint_t *turtle;

	if (!list || !(list->next) || !((list->next)->next))
		return (0);

	turtle = list->next;
	hare = turtle->next;
	while (hare && hare->next)
	{
		if (turtle == hare)
			return (1);
		turtle = turtle->next;
		hare = (hare->next)->next;
	}

	return (0);
}
