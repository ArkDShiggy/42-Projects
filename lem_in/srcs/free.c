/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 09:46:02 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/14 09:46:03 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_weight(void *content, size_t size)
{
	free(content);
	size++;
}

void	free_path_array(t_path **array, int ant_num)
{
	int i;

	i = 0;
	while (i < ant_num)
	{
		if (array[i])
			free_path(array[i]);
		i++;
	}
	free(array);
}

void	free_room(t_room *room)
{
	free_larray(room->links);
	free(room->links);
	free_larray(room->turns);
	free(room->turns);
	free(room);
}

void	free_antfarm(t_antfarm *antfarm)
{
	free_larray(antfarm->rooms);
	free(antfarm);
}

void	free_path(t_path *path)
{
	if (!path)
		return ;
	while (*(path->list))
		del_last_node(path->list);
	free(path->list);
	free(path);
}
