/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:46:45 by jcatinea          #+#    #+#             */
/*   Updated: 2017/03/03 10:52:35 by cfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_env	*new_env(void)
{
	t_env	*new;

	new = (t_env *)ft_memalloc(sizeof(t_env));
	new->to_write = (t_list **)ft_memalloc(sizeof(t_list *));
	*(new->to_write) = NULL;
	new->used_labels = (t_list **)ft_memalloc(sizeof(t_list *));
	*(new->used_labels) = NULL;
	new->defined_labels = (t_list **)ft_memalloc(sizeof(t_list *));
	*(new->defined_labels) = NULL;
	return (new);
}

void	add_used_label(t_env *env, char *name)
{
	t_list	*node;
	t_label	*new;

	new = (t_label *)ft_memalloc(sizeof(t_label));
	new->byte = 0;
	new->name = (char *)ft_memalloc(sizeof(char) * ft_strlen(name) + 1);
	ft_strcpy(new->name, name);
	node = ft_lstnew(new, sizeof(t_label));
	free(new);
	ft_lstadd(env->used_labels, node);
}

void	add_defined_label(t_env *env, char *name, int byte)
{
	t_list	*node;
	t_label	*new;

	new = (t_label *)ft_memalloc(sizeof(t_label));
	new->byte = byte;
	new->name = (char *)ft_memalloc(sizeof(char) * ft_strlen(name) + 1);
	ft_strcpy(new->name, name);
	node = ft_lstnew(new, sizeof(t_label));
	free(new);
	ft_lstadd(env->defined_labels, node);
}

int		label_exists(t_env *env, char *name)
{
	t_list	*node;
	t_label	*label;

	node = *(env->defined_labels);
	while (node)
	{
		label = (t_label *)(node->content);
		if (ft_strequ(label->name, name) == 1)
			return (1);
		node = node->next;
	}
	return (0);
}
