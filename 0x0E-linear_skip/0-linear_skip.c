#include "search.h"


/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: is a pointer to the head of the skip list to search in
 * @value:  is the value to search for
 *
 * Important: - it's assumed that list will be sorted in ascending order
 *            - A node of the express lane is placed every index which is a
 *              multiple of the square root of the size of the list
 *
 * Return: a pointer on the first node where value is located.
 *         If value is not present in list or if head is NULL, your function
 *         must return NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express, *inf, *sup;
	size_t inf_idx, sup_idx, i;

	if (!list)
		return (NULL);

	inf_idx = 0;
	inf = list;
	sup_idx = 0;
	sup = list;
	for (express = list->express; 1; express = express->express)
	{
		inf_idx = sup_idx;
		inf = sup;
		if (express)
		{
			printf("Value checked at index [%lu] = [%d]\n",
			       express->index, express->n);
			sup_idx = express->index;
			sup = express;
		}
		else  /* when value is not in the list: */
		{
			for (; sup; sup = sup->next)
				sup_idx = sup->index;
		}
		if (!express || express->n >= value)
			break;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       inf_idx, sup_idx);
	for (i = inf_idx; inf; i++, inf = inf->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", i, inf->n);
		if (inf->n == value)
			return (inf);
	}
	return (NULL);
}
