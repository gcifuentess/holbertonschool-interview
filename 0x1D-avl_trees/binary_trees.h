#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <limits.h>
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
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);


int binary_tree_is_avl(const binary_tree_t *tree);
int avl_check(const binary_tree_t *tree, int min, int max, int *height);

#endif /* _BINARY_TREES_H_ */
