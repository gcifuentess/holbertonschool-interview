#include "lists.h"


/**
 * find_listint_loop - finds the loop in a linked list
 * @head: head pointer of the linked list.
 *
 * Return: The address of the node where the loop starts,
 *          or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	return (the_tortoise_and_the_hare(head));
}

/**
 * the_tortoise_and_the_hare - to detect a loop in a linked list.
 * @head: head pointer of the linked list.
 *
 * Return: The node where the loop starts or NULL if no loop.
 */
listint_t *the_tortoise_and_the_hare(listint_t *head)
{
	listint_t *tortoise, *hare, *flag, *broken, *actual;
	int len, i;

	tortoise = head;
	hare = tortoise->next;

	if (!tortoise || !hare)
		return (NULL);
	len = 0;/*number of nodes of the loop*/
	while (tortoise != hare)
	{
		tortoise = tortoise->next;
		if (hare)
			flag = hare->next;

		if (!flag || !hare)
			return (NULL);
		hare = (hare->next)->next;
		len++;
	}
	/*The next section is to locate the real beginning of the loop*/
	broken = head;
	actual = tortoise;
	while (!(actual->next == broken))
	{
		actual = tortoise;
		for (i = 0; i < len; i++)
		{
			if (actual->next == broken)
				return (broken);
			actual = actual->next;
		}
		broken = broken->next;
	}
	if (len == 1)
		return (tortoise->next);
	return (tortoise);
}
