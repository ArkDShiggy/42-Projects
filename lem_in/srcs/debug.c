/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 09:26:55 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/21 09:44:34 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_links(t_room *room, t_antfarm *antfarm)
{
	int		i;
	int		index;
	t_room	*dest;

	i = 0;
	while (i < room->link_num)
	{
		ft_putstr(" L");
		index = *(int *)(get_larray(room->links, i));
		dest = get_larray(antfarm->rooms, index);
		ft_putstr(dest->name);
		i++;
	}
}

void	print_path(t_path *path)
{
	t_list	*node;
	t_room	*room;
	int		turn;

	node = *(path->list);
	turn = 0;
	while (node)
	{
		room = (t_room *)(node->content);
		ft_putchar('T');
		while (search_turn(room, turn) > 1)
			turn++;
		ft_putnbr(turn);
		turn++;
		ft_putchar(' ');
		ft_putstr(room->name);
		ft_putchar(' ');
		node = node->next;
	}
	ft_putchar('\n');
}

void	print_paths(t_path **array, int ant_num)
{
	int	i;

	ft_putstr("array: \n");
	i = 0;
	while (i < ant_num)
	{
		if (array[i] == NULL)
			ft_putstr("(null)\n");
		else
			print_path(array[i]);
		i++;
	}
}

void	print_graph(t_antfarm *antfarm)
{
	int		i;
	t_room	*room;

	i = 0;
	while (i < antfarm->room_num)
	{
		room = (t_room *)get_larray(antfarm->rooms, i);
		ft_putstr(room->name);
		print_links(room, antfarm);
		ft_putchar('\n');
		i++;
	}
}

void	print_recursive_node(t_room *room, t_antfarm *antfarm)
{
	int		i;
	int		index;
	t_room	*dest;

	room->visited = 1;
	ft_putstr(room->name);
	ft_putchar('\n');
	i = 0;
	while (i < room->link_num)
	{
		index = *(int *)(get_larray(room->links, i));
		dest = get_larray(antfarm->rooms, index);
		if (dest->visited == 0)
			print_recursive_node(dest, antfarm);
		i++;
	}
}
