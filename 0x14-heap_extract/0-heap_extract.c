#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: is a double pointer to the root node of the heap
 *
 * Return: the value stored in the root node, 0 if fails
 */
int heap_extract(heap_t **root)
{
	int n, size, deph, max_deph;
	heap_t *node;

	if (!root || !*root)
		return (0);

	n = (*root)->n;
	deph = 0;
	max_deph = 0; /* max_deph initalizated in 0. Not reached yet*/
	size = size_heap(*root, &deph, &max_deph);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (n);
	}

	node = last_node(*root);
	(*root)->n = node->n;
	/*printf("node->n: %d\n", node->n);*/

	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;

	free(node);
	rebuild_heap(*root);

	return (n);
}

/**
 * size_heap - calculates the size and deph of the heap
 * @root: to the root node of the heap
 * @deph: pointer to a counter started in ceros. Will store the
 *        deph of the heap
 * @max_deph: a pointer to control the deph counter. 0 for max_deph not
 *            reached, 1 when reached.
 *
 * Return: the size of the heap
 */
int size_heap(heap_t *root, int *deph, int *max_deph)
{
	if (root)
	{
		if (!*max_deph)
			*deph += 1;
		return (1 + size_heap(root->left, deph, max_deph) +
			size_heap(root->right, deph, max_deph));
	}

	*max_deph = 1; /* 1 == True. Max_deph reached*/
	return (0);
}

/**
 * last_node - returns the last node
 * @root: to the root node of the heap
 *
 * Description: this function takes into account the deph of each side of
 * the tree to check if it is balanced or not, and with this dectect wich
 * side has the last node
 *
 * Return: last node in the heap
 */

heap_t *last_node(heap_t *root)
{
	int left_s, right_s, right_deph, left_deph;
	int r_max_deph, l_max_deph, l_goal, r_goal, i, j, pow;

	/* printf("last_node: %d\n", root->n);*/
	if (!root->right)
		return (root->left);
	left_deph = 0;
	l_max_deph = 0; /* max_deph initalizated in 0. Not reached yet*/
	left_s = size_heap(root->left, &left_deph, &l_max_deph);

	if (left_s == 1)
		return (root->right);
	for (i = 1, l_goal = 0; i < left_deph; i++)
	{
		for (j = 0, pow = 1; j < i; j++)
			pow *= 2;
		l_goal += pow;
	}
	/**
	 *printf("size %d, deph: %d, goal: %d\n",
	 * left_s, left_deph, l_goal + 1);
	 */
	if (left_s != l_goal + 1)
		return (last_node(root->left));
	right_deph = 0;
	r_max_deph = 0; /* max_deph initalizated in 0. Not reached yet*/
	right_s = size_heap(root->right, &right_deph, &r_max_deph);
	for (i = 1, r_goal = 0; i < right_deph; i++)
	{
		for (j = 0, pow = 1; j < i; j++)
			pow *= 2;
		r_goal += pow;
	}
	if (right_s != r_goal + 1)
		return (last_node(root->right));
	if (left_deph > right_deph)
		return (last_node(root->left));
	return (last_node(root->right));
}

/**
 * rebuild_heap - rebuilds the Max Binary Heap
 * @root: to the root node of the heap
 *
 * Return: Nothing
 */
void rebuild_heap(heap_t *root)
{

	heap_t *node, *child, *left, *right;
	int tmp;

	node = root;
	while (node->left)
	{
		if (!node->right)
			child = node->left;
		else
		{
			left = node->left;
			right = node->right;
			if (left->n > right->n)
				child = left;
			else
				child = right;
		}
		if (node->n > child->n)
			break;
		tmp = node->n;
		node->n = child->n;
		child->n = tmp;
		node = child;
		/*
		 * printf("\n");
		 * binary_tree_print(root);
		 */
	}
}
