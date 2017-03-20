/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:25:21 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/22 10:40:16 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	starting_strategy(t_info *info)
{
	int i;
	int x_p;
	int y_p;
	int x_e;
	int y_e;

	i = 0;
	while (info->map_str[i] != info->player)
		i++;
	x_p = i % info->map_w;
	y_p = i / info->map_w;
	i = 0;
	while (info->map_str[i] != info->opponent)
		i++;
	x_e = i % info->map_w;
	y_e = i / info->map_w;
	if (x_p > x_e)
		info->strategy = 0;
	else
		info->strategy = 1;
	info->phase = 0;
}

int		follow_priority(t_info *info, int quadrant)
{
	if (quadrant == 0)
		return (priority_ur(info));
	if (quadrant == 1)
		return (priority_ru(info));
	if (quadrant == 2)
		return (priority_rd(info));
	if (quadrant == 3)
		return (priority_dl(info));
	if (quadrant == 4)
		return (priority_dl(info));
	if (quadrant == 5)
		return (priority_ld(info));
	if (quadrant == 6)
		return (priority_lu(info));
	if (quadrant == 7)
		return (priority_ul(info));
	return (-1);
}

int		fake_follow_coord(t_info *info, int coord)
{
	t_minmax	*best;
	int			a;

	best = (t_minmax *)malloc(sizeof(t_minmax));
	best->x = 0;
	best->y = 0;
	best->wtf = 0;
	best->distance = 2 * (info->map_w + info->map_h);
	true_follow_coord(info, coord, best);
	a = best->wtf;
	print_result(best->y, best->x);
	free(best);
	if (a > 0)
		return (1);
	return (0);
}

void	true_follow_coord(t_info *info, int coord, t_minmax *best)
{
	int			x;
	int			y;
	int			distance;

	x = -info->piece_w;
	while (x < info->map_w)
	{
		y = -info->piece_h;
		while (y < info->map_h)
		{
			if (check_piece(info, x, y))
			{
				distance = check_distance(coord, x, y, info);
				if (distance < best->distance)
					change_best(best, distance, x, y);
			}
			y++;
		}
		x++;
	}
}

int		find_enemy_coord(t_info *info)
{
	int x;
	int y;

	x = 0;
	if (info->phase == -1)
		return (-1);
	while (x < info->map_w)
	{
		y = 0;
		while (y < info->map_h)
		{
			if (info->map_str[x + y * info->map_w] == info->opponent)
			{
				if (info->previous_map[x + y * info->map_w] != info->opponent)
					return (x + y * info->map_w);
			}
			y++;
		}
		x++;
	}
	return (-1);
}
