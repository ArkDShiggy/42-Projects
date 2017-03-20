/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:17:29 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/16 12:17:31 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		add_node_to_path(t_room *room, t_path *path, t_path *min, int ant_num)
{
	t_list	*node;

	if (!(node = ft_lstnew(room, sizeof(t_room))))
		return (0);
	if (min)
	{
		if (path->len > (min->len + ant_num))
		{
			free(node);
			return (1);
		}
	}
	path->len += 1;
	ft_lstappend(path->list, node);
	return (2);
}

t_path	*new_path(void)
{
	t_path *path;
	t_list **list;

	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	if (!(list = (t_list **)malloc(sizeof(t_list *))))
	{
		free(path);
		return (NULL);
	}
	*list = NULL;
	path->list = list;
	path->len = 0;
	return (path);
}

t_path	*copy_path(t_path *path)
{
	t_path *new;
	t_list *node;
	t_list *new_node;

	new = malloc(sizeof(t_path));
	new->list = malloc(sizeof(t_list *));
	*(new->list) = NULL;
	new->len = path->len;
	node = *(path->list);
	while (node)
	{
		if (!(new_node = ft_lstnew(node->content, sizeof(t_room))))
		{
			free_path(new);
			return (NULL);
		}
		ft_lstappend(new->list, new_node);
		node = node->next;
	}
	return (new);
}

void	del_last_node(t_list **list)
{
	t_list *node;
	t_list *previous;

	node = *list;
	previous = NULL;
	while (node->next)
	{
		previous = node;
		node = node->next;
	}
	free(node);
	if (previous)
		previous->next = NULL;
	else
		*list = NULL;
}

int		add_path_to_list(t_path **array, t_path *path, int ant_num)
{
	int i;
	int j;

	i = 0;
	while (i < ant_num && array[i] != NULL)
	{
		if (path->len > array[i]->len)
			i++;
		else
		{
			j = ant_num - 1;
			free_path(array[j]);
			while (j > i)
			{
				array[j] = array[j - 1];
				j--;
			}
			break ;
		}
	}
	if (!(array[i] = copy_path(path)))
		return (0);
	return (1);
}
