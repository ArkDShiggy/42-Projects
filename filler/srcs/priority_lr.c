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

int		priority_lu(t_info *info)
{
	int x;
	int y;

	x = -info->piece_w;
	while (x < info->map_w)
	{
		y = -info->piece_h;
		while (y < info->map_h)
		{
			if (check_piece(info, x, y))
			{
				print_result(y, x);
				return (1);
			}
			y++;
		}
		x++;
	}
	print_result(0, 0);
	return (0);
}

int		priority_ru(t_info *info)
{
	int x;
	int y;

	x = info->map_w - 1;
	while (x >= -info->piece_w)
	{
		y = -info->piece_h;
		while (y < info->map_h)
		{
			if (check_piece(info, x, y))
			{
				print_result(y, x);
				return (1);
			}
			y++;
		}
		x--;
	}
	print_result(0, 0);
	return (0);
}

int		priority_rd(t_info *info)
{
	int x;
	int y;

	x = info->map_w - 1;
	while (x >= -info->piece_w)
	{
		y = info->map_h - 1;
		while (y >= -info->piece_h)
		{
			if (check_piece(info, x, y))
			{
				print_result(y, x);
				return (1);
			}
			y--;
		}
		x--;
	}
	print_result(0, 0);
	return (0);
}

int		priority_ld(t_info *info)
{
	int x;
	int y;

	x = -info->piece_w;
	while (x < info->map_w)
	{
		y = info->map_h - 1;
		while (y >= -info->piece_h)
		{
			if (check_piece(info, x, y))
			{
				print_result(y, x);
				return (1);
			}
			y--;
		}
		x++;
	}
	print_result(0, 0);
	return (0);
}
