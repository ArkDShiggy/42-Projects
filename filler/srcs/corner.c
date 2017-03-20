/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:25:21 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/22 16:31:08 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ur_corner_strat(t_info *info, int enemy_pos)
{
	int corner;

	corner = info->map_w - 1;
	if (info->map_str[corner] == '.')
		return (fake_follow_coord(info, corner));
	else if (info->map_str[corner] == info->opponent)
	{
		if (check_v_wall(info, info->map_w - 1))
			return (2);
		else
			return (priority_ru(info));
	}
	else
		return (fake_follow_coord(info, enemy_pos));
}

int		dl_corner_strat(t_info *info, int enemy_pos)
{
	int corner;

	corner = (info->map_h - 1) * info->map_w;
	if (info->map_str[corner] == '.')
		return (fake_follow_coord(info, corner));
	else if (info->map_str[corner] == info->opponent)
	{
		if (check_h_wall(info, info->map_h - 1))
			return (2);
		else
			return (priority_dl(info));
	}
	else
		return (fake_follow_coord(info, enemy_pos));
}

int		corner_strat(t_info *info, int enemy_pos)
{
	int a;

	if (info->phase == 0)
	{
		if ((a = ur_corner_strat(info, enemy_pos)) == 2)
		{
			if ((a = dl_corner_strat(info, enemy_pos)) == 2)
				return (fake_follow_coord(info, enemy_pos));
		}
		return (a);
	}
	else
	{
		if ((a = dl_corner_strat(info, enemy_pos)) == 2)
		{
			if ((a = ur_corner_strat(info, enemy_pos)) == 2)
				return (fake_follow_coord(info, enemy_pos));
		}
		return (a);
	}
}
