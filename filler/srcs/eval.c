/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:25:21 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/02 16:31:08 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		valid_coord(t_info *info, int i, int x, int y)
{
	int coord;

	coord = (i / info->piece_w + y) * info->map_w + (i % info->piece_w + x);
	if (i / info->piece_w + y >= info->map_h)
		return (0);
	if (i / info->piece_w + y < 0)
		return (0);
	if (i % info->piece_w + x >= info->map_w)
		return (0);
	if (i % info->piece_w + x < 0)
		return (0);
	if (info->map_str[coord] == info->opponent)
		return (0);
	return (1);
}

int		check_piece(t_info *info, int x, int y)
{
	int i;
	int count;
	int coord;

	i = -1;
	count = 0;
	while (++i < (info->piece_w * info->piece_h))
	{
		if (info->piece_str[i] == '*')
		{
			coord = (i / info->piece_w + y) * info->map_w;
			coord += (i % info->piece_w + x);
			if (valid_coord(info, i, x, y) == 0)
				return (0);
			if (info->map_str[coord] == info->player)
			{
				if (++count > 1)
					return (0);
			}
		}
	}
	if (count == 1)
		return (1);
	return (0);
}

int		get_quadrant(t_info *info, int x, int y, int nmi_coord)
{
	int x_nmi;
	int y_nmi;

	x_nmi = nmi_coord % info->map_w;
	y_nmi = nmi_coord / info->map_w;
	if (info->map_w > info->map_h)
	{
		if (y < info->map_h / 2)
		{
			if (x < info->map_w / 2)
				return (7);
			else
				return (0);
		}
		else
		{
			if (x < info->map_w / 2)
				return (4);
			else
				return (3);
		}
	}
	else
		return (get_quadrant_two(info, x, y));
}

int		get_quadrant_two(t_info *info, int x, int y)
{
	if (y < info->map_h / 2)
	{
		if (x < info->map_w / 2)
			return (6);
		else
			return (1);
	}
	else
	{
		if (x < info->map_w / 2)
			return (5);
		else
			return (2);
	}
}

int		eval_map(t_info *info)
{
	int enemy_pos;

	enemy_pos = find_enemy_coord(info);
	if (info->phase == 0)
		info->phase = 1;
	else
		info->phase = 0;
	free(info->previous_map);
	if (!(info->previous_map = ft_strdup(info->map_str)))
		return (0);
	return (corner_strat(info, enemy_pos));
}
