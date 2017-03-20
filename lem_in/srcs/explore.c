/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 12:17:29 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/20 12:17:31 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		verify_graph(t_antfarm *antfarm)
{
	int		i;
	t_room	*room;
	int		count;

	count = 0;
	i = 0;
	while (i < antfarm->room_num)
	{
		room = (t_room *)(get_larray(antfarm->rooms, i));
		if (room->special == 1)
			count++;
		i++;
	}
	if (count != 1)
		return (0);
	return (verify_graph_two(antfarm));
}

int		verify_graph_two(t_antfarm *antfarm)
{
	int		i;
	t_room	*room;
	int		count;

	count = 0;
	i = 0;
	while (i < antfarm->room_num)
	{
		room = (t_room *)(get_larray(antfarm->rooms, i));
		if (room->special == 2)
			count++;
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

t_path	**find_paths(t_antfarm *antfarm)
{
	t_path	*path;
	t_path	**path_array;
	t_room	*start;
	int		i;

	if (verify_graph(antfarm) == 0)
		return (NULL);
	if (!(path = new_path()))
		malloc_error_one(antfarm, "new_path");
	if (!(path_array = (t_path **)malloc(sizeof(t_path *) * antfarm->ant_num)))
	{
		free(path);
		malloc_error_one(antfarm, "new_stuff");
	}
	i = 0;
	while (i < antfarm->ant_num)
	{
		path_array[i] = NULL;
		i++;
	}
	start = (t_room *)get_larray(antfarm->rooms, special_search(antfarm, 1));
	if (explore(start, path_array, path, antfarm) == 0)
		malloc_error_two(antfarm, path_array, path);
	free_path(path);
	return (path_array);
}

int		explore_two(t_room *dest, t_path *path, t_path **ar, t_antfarm *antfarm)
{
	int a;

	if ((a = (add_node_to_path(dest, path, ar[0], antfarm->ant_num))) == 0)
		return (0);
	else if (a == 2)
	{
		if (explore(dest, ar, path, antfarm) == 0)
			return (0);
		path->len -= 1;
		del_last_node(path->list);
	}
	return (1);
}

int		explore(t_room *start, t_path **array, t_path *path, t_antfarm *antfarm)
{
	int		i;
	int		index;
	t_room	*room;

	start->visited = 1;
	i = 0;
	if (start->special == 2)
		add_path_to_list(array, path, antfarm->ant_num);
	else
	{
		while (i < start->link_num)
		{
			index = *(int *)(get_larray(start->links, i));
			room = (t_room *)(get_larray(antfarm->rooms, index));
			if (room->visited == 0)
			{
				if (explore_two(room, path, array, antfarm) == 0)
					return (0);
			}
			i++;
		}
	}
	start->visited = 0;
	return (1);
}
