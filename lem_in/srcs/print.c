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

void	free_array(t_room ***array, int max_turns)
{
	int i;

	i = 0;
	while (i < max_turns)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

t_room	***create_array(int ant_num, int max_turns)
{
	t_room	***turn_array;
	int		i;
	int		j;

	if (!(turn_array = (t_room ***)malloc(sizeof(t_room **) * max_turns)))
		return (NULL);
	i = -1;
	while (++i < max_turns)
	{
		if (!(turn_array[i] = (t_room **)malloc(sizeof(t_room *) * ant_num)))
		{
			j = -1;
			while (++j < i)
				free(turn_array[j]);
			free(turn_array);
			return (NULL);
		}
		else
		{
			j = -1;
			while (++j < ant_num)
				turn_array[i][j] = NULL;
		}
	}
	return (turn_array);
}

void	turn_convert(t_room ***array, t_path *path, int ant)
{
	t_list	*node;
	t_room	*room;
	int		turn;

	node = *(path->list);
	turn = 0;
	while (node)
	{
		room = (t_room *)(node->content);
		while (search_turn(room, turn) > 1)
			turn++;
		array[turn][ant] = room;
		turn++;
		node = node->next;
	}
}

void	print_part(int i, int j, int count, t_room ***array)
{
	if (i > 0 && count == 0)
		ft_putchar('\n');
	if (count > 0)
		ft_putchar(' ');
	ft_putchar('L');
	ft_putnbr(j + 1);
	ft_putchar('-');
	ft_putstr(array[i][j]->name);
}

void	print_solution(t_room ***array, int max_turn, int ant_num)
{
	int	i;
	int	j;
	int count;

	i = 0;
	while (i < max_turn)
	{
		j = 0;
		count = 0;
		while (j < ant_num)
		{
			if (array[i][j] != NULL)
			{
				print_part(i, j, count, array);
				count++;
			}
			j++;
		}
		i++;
	}
}
