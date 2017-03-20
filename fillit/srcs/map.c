/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:25:59 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/21 12:29:34 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*empty_map(int size)
{
	t_map	*new;
	int		i;

	if (!(new = (t_map*)malloc(sizeof(t_map))))
		malloc_error();
	new->size = size;
	i = 0;
	if (!(new->map = (char*)malloc(sizeof(char) * (size * size))))
		malloc_error();
	while (i < size * size)
	{
		(new->map)[i] = '.';
		i++;
	}
	return (new);
}

void	del_map(t_map *map)
{
	if (!map)
		return ;
	free(map->map);
	free(map);
}

t_map	*copy_map(t_map *map)
{
	t_map	*new;
	int		i;
	int		size;

	i = 0;
	if (!(new = (t_map*)malloc(sizeof(t_map))))
		malloc_error();
	size = map->size;
	new->size = size;
	if (!(new->map = (char*)malloc(sizeof(char) * (size * size))))
		malloc_error();
	while (i < size * size)
	{
		(new->map)[i] = (map->map)[i];
		i++;
	}
	return (new);
}

t_map	*get_new_map(t_piece *piece, t_map *map, int coord, int letter)
{
	int		x;
	int		y;
	int		i;
	t_map	*new_map;

	new_map = copy_map(map);
	i = 0;
	while (i < 4)
	{
		x = piece->coord[i] % 5;
		y = piece->coord[i] / 5;
		(new_map->map)[coord + x + y * map->size] = letter + 'A';
		i++;
	}
	return (new_map);
}

void	print_map(t_map *map)
{
	int i;
	int j;
	int size;

	i = 0;
	size = map->size;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar((map->map)[i * size + j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
