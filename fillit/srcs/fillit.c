/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:29:48 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/22 07:17:47 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			piece_check(t_piece *piece, t_map *map, int coord)
{
	int i;
	int x;
	int y;
	int size;

	i = 0;
	size = map->size;
	if (piece->width + coord % size >= size)
		return (0);
	if (piece->height + coord / size >= size)
		return (0);
	while (i < 4)
	{
		x = piece->coord[i] % 5;
		y = piece->coord[i] / 5;
		if ((map->map)[coord + x + y * size] != '.')
			return (0);
		i++;
	}
	return (1);
}

t_piece		**get_new_tab(t_piece **tab, int piece)
{
	int		i;
	t_piece	**new;

	i = 0;
	while (tab[i])
		i++;
	if (!(new = (t_piece **)malloc(sizeof(t_piece *) * (i + 1))))
		malloc_error();
	i = 0;
	while (tab[i])
	{
		if (i == piece)
			new[i] = piece_copy(tab[i], 1);
		else
			new[i] = piece_copy(tab[i], 0);
		i++;
	}
	new[i] = 0;
	return (new);
}

t_map		*fill_piece(t_piece **tab, t_map *map, int piece)
{
	int		i;
	t_map	*new_map;
	t_piece	**new_tab;

	i = -1;
	while (++i < (map->size * map->size))
	{
		if (piece_check(tab[piece], map, i))
		{
			new_map = get_new_map(tab[piece], map, i, piece);
			new_tab = get_new_tab(tab, piece);
			if ((new_map = fillit(new_tab, new_map)))
			{
				free_list(new_tab);
				return (new_map);
			}
			del_map(new_map);
			free_list(new_tab);
			if (map->size > 4)
				break ;
		}
	}
	return (NULL);
}

t_map		*fillit(t_piece **tab, t_map *map)
{
	int		piece;
	int		result;
	t_map	*new_map;

	piece = -1;
	result = 0;
	while (tab[++piece])
	{
		if ((tab[piece]->placed) == 0)
		{
			if ((new_map = fill_piece(tab, map, piece)))
				return (new_map);
		}
		else
			result++;
	}
	if (result == piece)
		return (map);
	return (NULL);
}

t_map		*test_size(t_piece **tab)
{
	int		size;
	t_map	*map;
	int		i;

	i = 0;
	size = 1;
	while (tab[i])
		i++;
	i *= 4;
	while (size * size < i)
		size++;
	map = empty_map(size);
	while (!(map = fillit(tab, map)))
	{
		size++;
		del_map(map);
		map = empty_map(size);
	}
	free_list(tab);
	return (map);
}
