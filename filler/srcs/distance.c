/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 08:55:40 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/16 08:55:42 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	new_best(t_info *info, t_minmax *best)
{
	best->x = 0;
	best->y = 0;
	best->wtf = 0;
	best->distance = 2 * (info->map_w + info->map_h);
}

void	change_best(t_minmax *best, int distance, int x, int y)
{
	best->x = x;
	best->y = y;
	best->wtf = 1;
	best->distance = distance;
}

int		check_distance(int coord, int x, int y, t_info *info)
{
	int i;
	int a;
	int b;
	int min;

	min = 2 * (info->map_w + info->map_h);
	i = 0;
	while (++i < (info->piece_w * info->piece_h))
	{
		if (info->piece_str[i] == '*')
		{
			b = (i / info->piece_w + y);
			a = (i % info->piece_w + x);
			if ((ft_abs(a - coord % info->map_w)
		+ ft_abs(b - coord / info->map_w)) < min)
				min = (ft_abs(a - coord % info->map_w)
		+ ft_abs(b - coord / info->map_w));
		}
	}
	return (min);
}
