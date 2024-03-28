#include "binary_trees.h"

/**
 * binary_tree_insert_left - nserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return:  the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *tmp;

	if (parent == NULL)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	if (parent->left == NULL)
	{
		parent->left = new;
		new->parent = parent;
	}
	else
	{
		tmp = parent->left;
		parent->left = new;
		new->parent = parent;
		new->left = tmp;
		tmp->parent = new;
	}
	return (parent);
}
