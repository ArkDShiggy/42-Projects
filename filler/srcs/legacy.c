/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legacy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:25:21 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/22 16:31:08 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	wall_check(t_info *info)
{
	int a;
	int quadrant;

	quadrant = info->priorities[info->phase];
	if (quadrant == 0 || quadrant == 7)
		a = check_h_wall(info, 0);
	if (quadrant == 1 || quadrant == 2)
		a = check_v_wall(info, info->map_w - 1);
	if (quadrant == 3 || quadrant == 4)
		a = check_h_wall(info, info->map_h - 1);
	if (quadrant == 5 || quadrant == 6)
		a = check_v_wall(info, 0);
	if (a == 2)
		wall_check_two(info);
	if (a == 1)
		info->phase += 1;
}

void	wall_check_two(t_info *info)
{
	int a;
	int quadrant;

	quadrant = info->priorities[info->phase];
	if (quadrant == 0 || quadrant == 3)
		a = check_v_wall(info, info->map_w - 1);
	if (quadrant == 1 || quadrant == 6)
		a = check_h_wall(info, 0);
	if (quadrant == 7 || quadrant == 4)
		a = check_v_wall(info, 0);
	if (quadrant == 5 || quadrant == 2)
		a = check_h_wall(info, info->map_h - 1);
	if (a == 1)
		info->phase += 1;
}
