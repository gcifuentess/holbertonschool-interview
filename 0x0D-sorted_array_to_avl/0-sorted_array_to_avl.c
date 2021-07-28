#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of elements in the array
 *
 * Return: a pointer to the root node of the created AVL tree,
 *         or NULL on failure
 *
 * Important - Assumes there will be no duplicate value in the array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t pivot;

	if (!array || !size)
		return (NULL);

	tree = calloc(1, sizeof(avl_t));
	if (!tree)
		return (NULL);


	if (size % 2 == 0)
		pivot = size / 2 - 1;
	else
		pivot = size / 2;

	tree->n = array[pivot];
	tree->parent = NULL;
	if (size > 1)
	{
		tree->left = sub_tree(array, tree, 0, pivot);
		tree->right = sub_tree(array, tree,  pivot + 1, size);
	}
	else
	{
		tree->left = NULL;
		tree->right = NULL;
	}

	return (tree);
}

/**
 * sub_tree - builds the sub tress an AVL tree
 * @array: is a pointer to the first element of the array to be converted
 * @parent: is a pointer of the parent node
 * @lo: lowest index of the array to built the sub_tree
 * @hi: highest index of the array to built the sub_tree
 *
 * Return: a pointer to the root node of the sub_tree
 *
 */
avl_t *sub_tree(int *array, avl_t *parent, size_t lo, size_t hi)
{
	avl_t *s_tree = NULL;
	size_t pivot;

	if (hi - lo == 0)
		return (NULL);

	s_tree = calloc(1, sizeof(avl_t));
	if (!s_tree)
		return (NULL);

	if ((hi - lo) % 2 == 0)
		pivot = lo + (hi - lo) / 2 - 1;
	else
		pivot = lo + (hi - lo) / 2;

	s_tree->n = array[pivot];
	s_tree->parent = parent;

	/*
	 * printf("lo: %lu, hi: %lu, pivot: %lu, n: %d\n",
	 * lo, hi, pivot, s_tree->n);
	*/
	if ((hi - lo) > 1)
	{
		s_tree->left = sub_tree(array, s_tree, lo, pivot);
		s_tree->right = sub_tree(array, s_tree, pivot + 1, hi);
	}
	else
	{
		s_tree->left = NULL;
		s_tree->right = NULL;
	}

	return (s_tree);
}
