#include "btree.h"

t_btree	*new_btree(void *node)
{
	t_btree *new;

	new = (t_btree *)ft_malloc(sizeof(t_btree));
	new->node = node;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void	btree_add(t_btree **root_addr, t_btree *new,
	int (*compare)(void *, void *))
{
	t_btree *root;

	root = *root_addr;
	if (root == NULL)
		*root_addr = new;
	else if ((*compare)(new->node, root->node) < 0)
	{
		if (root->left == NULL)
			root->left = new;
		else
			btree_add(&root->left, new, compare);
	}
	else
	{
		if (root->right == NULL)
			root->right = new;
		else
			btree_add(&root->right, new, compare);
	}
}

void	btree_map(t_btree *root, void (*f)(void *))
{
	if (root)
	{
		btree_map(root->left, f);
		(*f)(root->node);
		btree_map(root->right, f);
	}
}

void	btree_map_one(t_btree *root, void (*f)(void *, void *), void *arg)
{
	if (root)
	{
		btree_map_one(root->left, f, arg);
		(*f)(root->node, arg);
		btree_map_one(root->right, f, arg);
	}
}

void	btree_free(t_btree *root, void (*free_f)(void *))
{
	if (root)
	{
		btree_free(root->left, free_f);
		(*free_f)(root->node);
		btree_free(root->right, free_f);
		free(root);
	}
}
