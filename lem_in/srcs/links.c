/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:13:35 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/13 17:13:39 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read_link(t_antfarm *antfarm, char *line)
{
	char	*name1;
	char	*name2;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	name1 = ft_strsub(line, 0, i);
	j = ++i;
	while (line[j])
		j++;
	name2 = ft_strsub(line, i, j - i);
	return (name_to_links(antfarm, name1, name2));
}

int		name_to_links(t_antfarm *antfarm, char *name1, char *name2)
{
	int		room1_index;
	int		room2_index;
	t_room	*room1;
	t_room	*room2;

	room1_index = name_search(antfarm, name1);
	room2_index = name_search(antfarm, name2);
	if ((room1_index < 0) || (room2_index < 0))
		return (0);
	room1 = (t_room *)(get_larray(antfarm->rooms, room1_index));
	room2 = (t_room *)(get_larray(antfarm->rooms, room2_index));
	if (!(add_link(room1, room2_index)))
		malloc_error_one(antfarm, "add_link");
	if (!(add_link(room2, room1_index)))
		malloc_error_one(antfarm, "add_link");
	return (1);
}

int		add_link(t_room *room1, int room2_index)
{
	if (!(set_larray(room1->links, room1->link_num, &room2_index)))
		return (0);
	room1->link_num += 1;
	return (1);
}
