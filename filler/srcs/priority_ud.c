/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_lr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:25:21 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/02 16:31:08 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		priority_ul(t_info *info)
{
	int x;
	int y;

	y = -info->piece_h;
	while (y < info->map_h)
	{
		x = -info->piece_w;
		while (x < info->map_w)
		{
			if (check_piece(info, x, y))
			{
				print_result(y, x);
				return (1);
			}
			x++;
		}
		y++;
	}
	print_result(0, 0);
	return (0);
}

int		priority_dl(t_info *info)
{
	int x;
	int y;

	y = info->map_h - 1;
	while (y >= -info->piece_h)
	{
		x = -info->piece_w;
		while (x < info->map_w)
		{
			if (check_piece(info, x, y))
			{
				print_result(y, x);
				return (1);
			}
			x++;
		}
		y--;
	}
	print_result(0, 0);
	return (0);
}

int		priority_ur(t_info *info)
{
	int x;
	int y;

	y = -info->piece_h;
	while (y < info->map_w)
	{
		x = info->map_w - 1;
		while (x >= -info->piece_w)
		{
			if (check_piece(info, x, y))
			{
				print_result(y, x);
				return (1);
			}
			x--;
		}
		y++;
	}
	print_result(0, 0);
	return (0);
}

int		priority_dr(t_info *info)
{
	int x;
	int y;

	y = info->map_w - 1;
	while (y >= -info->piece_h)
	{
		x = info->map_h - 1;
		while (x >= -info->piece_w)
		{
			if (check_piece(info, x, y))
			{
				print_result(y, x);
				return (1);
			}
			x--;
		}
		y--;
	}
	print_result(0, 0);
	return (0);
}
