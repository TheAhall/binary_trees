#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return: created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
	if (parent->right == NULL)
	{
		parent->right = new;
		new->parent = parent;
	}
	else
	{
		tmp = parent->right;
		parent->right = new;
		new->parent = parent;
		new->right = tmp;
		tmp->parent = new;
	}
	return (parent);
}
