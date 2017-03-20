/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 09:26:55 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/21 09:44:34 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		search_turn(t_room *room, int turn)
{
	int value;

	value = *(int *)get_larray(room->turns, turn);
	return (value + 1);
}

int		path_length(t_path *path)
{
	t_list	*node;
	t_room	*room;
	int		turn;

	turn = 0;
	node = *(path->list);
	while (node)
	{
		room = (t_room *)(node->content);
		while (search_turn(room, turn) > 1)
			turn++;
		node = node->next;
		turn++;
	}
	return (turn);
}

t_path	*search_paths(t_path **paths, int ant_num)
{
	int j;
	int len;
	int min;
	int min_len;

	min = 0;
	min_len = path_length(paths[0]);
	j = 1;
	while (j < ant_num && paths[j])
	{
		len = path_length(paths[j]);
		if (len < min_len)
		{
			min_len = len;
			min = j;
		}
		j++;
	}
	return (paths[min]);
}

void	solve(t_path **paths, int ant_num)
{
	t_room	***array;
	t_path	*path;
	int		max_turns;
	int		i;

	max_turns = path_length(paths[0]) + ant_num + 1;
	array = create_array(ant_num, max_turns);
	i = 0;
	while (i < ant_num)
	{
		path = search_paths(paths, ant_num);
		turn_convert(array, path, i);
		if (update_link_path(path) == 0)
		{
			free_array(array, max_turns);
			return ;
		}
		i++;
	}
	print_solution(array, max_turns, ant_num);
	ft_putchar('\n');
	free_array(array, max_turns);
}
