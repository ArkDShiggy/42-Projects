/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:13:45 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/13 17:13:46 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read_room(t_antfarm *antfarm, char *str, int special)
{
	int		i;
	char	*name;
	int		a;
	t_room	*room;

	i = 0;
	a = 1;
	while (str[i] && str[i] != ' ')
		i++;
	if (!(name = ft_strsub(str, 0, i)))
		malloc_error_one(antfarm, "get_rooms");
	if (name_search(antfarm, name) >= 0)
		a = 0;
	else if (!(room = new_room(name, special)))
		malloc_error_one(antfarm, "new_room");
	else if (!check_coordinates(str + i + 1, antfarm, room) || name[0] == 'L')
		a = 0;
	else
	{
		set_larray(antfarm->rooms, antfarm->room_num, room);
		antfarm->room_num += 1;
	}
	return (a);
}

int		get_x(char *str, int *i, int *x)
{
	if (str[*i] == '-')
		(*i)++;
	*x = ft_atoi(str + *i);
	if (x == 0 && str[*i] != '0')
		return (0);
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (str[*i] == ' ')
		(*i)++;
	else
		return (0);
	return (1);
}

int		get_y(char *str, int *i, int *y)
{
	if (str[*i] == '-')
		(*i)++;
	*y = ft_atoi(str + *i);
	if (y == 0 && str[*i] != '0')
		return (0);
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (str[*i])
		return (0);
	else
		return (1);
}

int		check_coordinates(char *str, t_antfarm *antfarm, t_room *room)
{
	int i;
	int x;
	int y;

	i = 0;
	if (get_x(str, &i, &x) == 0)
		return (0);
	if (get_y(str, &i, &y) == 0)
		return (0);
	if (coord_search(antfarm, x, y) >= 0)
		return (0);
	room->x = x;
	room->y = y;
	return (1);
}

t_room	*new_room(char *name, int special)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	new->name = name;
	new->visited = 0;
	new->special = special;
	new->x = 0;
	new->y = 0;
	new->link_num = 0;
	if (!(new->links = new_larray(8, sizeof(int))))
	{
		free(new);
		return (NULL);
	}
	if (!(new->turns = new_larray(8, sizeof(int))))
	{
		free(new->links);
		free(new);
		return (NULL);
	}
	return (new);
}
