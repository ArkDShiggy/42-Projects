#ifndef BTREE_H
# define BTREE_H

# include "libft.h"

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*node;
}					t_btree;

t_btree				*new_btree(void *node);
void				btree_add(t_btree **root_addr, t_btree *new,
	int (*compare)(void *, void *));
void				btree_map(t_btree *root, void (*f)(void *));
void				btree_free(t_btree *root, void (*free_f)(void *));
void				btree_map_one(t_btree *root,
	 void (*f)(void *, void *), void *arg);

#endif
