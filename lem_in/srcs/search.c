/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:13:23 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/13 17:13:24 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		special_search(t_antfarm *antfarm, int special)
{
	t_room	*room;
	int		i;

	i = 0;
	while (i < antfarm->room_num)
	{
		room = (t_room *)(get_larray(antfarm->rooms, i));
		if (room->special == special)
			return (i);
		i++;
	}
	return (-1);
}

int		name_search(t_antfarm *antfarm, char *name)
{
	t_room	*room;
	int		i;

	i = 0;
	while (i < antfarm->room_num)
	{
		room = (t_room *)(get_larray(antfarm->rooms, i));
		if (ft_strequ(room->name, name))
			return (i);
		i++;
	}
	return (-1);
}

int		coord_search(t_antfarm *antfarm, int x, int y)
{
	t_room	*room;
	int		i;

	i = 0;
	while (i < antfarm->room_num)
	{
		room = (t_room *)(get_larray(antfarm->rooms, i));
		if (room->x == x && room->y == y)
			return (i);
		i++;
	}
	return (-1);
}
