/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 09:26:55 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/21 09:44:34 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		update_link_path(t_path *path)
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
		if (update_link_room(room, turn) == 0)
			return (0);
		turn++;
		node = node->next;
	}
	return (1);
}

int		update_link_room(t_room *room, int turn)
{
	int value;

	if (room->special == 2 || room->special == 1)
		return (1);
	value = *(int *)get_larray(room->turns, turn);
	value++;
	if (!(set_larray(room->turns, turn, &value)))
		return (0);
	return (1);
}
