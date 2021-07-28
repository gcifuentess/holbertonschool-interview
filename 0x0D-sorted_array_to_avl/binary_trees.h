#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} avl_t;

void binary_tree_print(const avl_t *);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *sub_tree(int *array, avl_t *parent, size_t lo, size_t hi);

#endif /* BINARY_TREES_H */
