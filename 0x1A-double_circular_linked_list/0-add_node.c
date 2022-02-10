#include "list.h"


/**
 * add_node_end - add a new node to the end of a double circular linked list
 * @list: pointer to head
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node = NULL, *node;

	if (!list)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->prev = new_node->next = NULL;
	new_node->str = strdup(str);

	if (str && !new_node->str)
		return (free(new_node), NULL);

	if (!*list)
	{
		new_node->prev = new_node->next = new_node;
		return (*list = new_node);
	}

	node = (*list)->prev;
	new_node->next = *list;
	node->next = new_node;
	new_node->prev = node;
	(*list)->prev = new_node;

	return (new_node);
}

/**
 * add_node_begin - Add a new node to the beginning of a double circular linked
 *                  list
 * @list: pointer to head
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	if (add_node_end(list, str))
	{
		*list = (*list)->prev;
		return (*list);
	}

	return (NULL);
}
