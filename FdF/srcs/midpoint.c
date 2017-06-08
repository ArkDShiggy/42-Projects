/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 12:07:48 by jcatinea          #+#    #+#             */
/*   Updated: 2017/06/05 12:08:00 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	draw_pixel(int x, int y, char *pix_ar)
{
	int				color;
	unsigned int	*test;

	color = 0x00ffffff;
	test = (unsigned int *)pix_ar;
	test[y * WIN_WID + x] = color;
}

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	draw_line(t_point *p1, t_point *p2, char *img)
{
	t_midpoint *tmp;

	tmp = (t_midpoint *)ft_malloc(sizeof(t_midpoint));
	tmp->dx = abs(p1->x - p2->x);
	tmp->dy = abs(p1->y - p2->y);
	tmp->slopegt = 0;
	if (tmp->dy > tmp->dx)
	{
		swap(&(p1->x), &(p1->y));
		swap(&(p2->x), &(p2->y));
		swap(&(tmp->dx), &(tmp->dy));
		tmp->slopegt = 1;
	}
	if (p1->x > p2->x)
	{
		swap(&(p1->x), &(p2->x));
		swap(&(p1->y), &(p2->y));
	}
	tmp->incry = -1;
	if (p1->y < p2->y)
		tmp->incry = 1;
	draw_line_two(p1, p2, tmp, img);
	free(tmp);
}

void	draw_line_two(t_point *p1, t_point *p2, t_midpoint *tmp, char *img)
{
	int d;
	int x1;
	int y1;

	x1 = p1->x;
	y1 = p1->y;
	d = 2 * tmp->dy - tmp->dx;
	while (x1 < p2->x)
	{
		if (d <= 0)
			d += (2 * tmp->dy);
		else
		{
			d += (2 * (tmp->dy - tmp->dx));
			y1 += tmp->incry;
		}
		x1 += 1;
		if (tmp->slopegt)
		{
			draw_pixel(y1, x1, img);
		}
		else
			draw_pixel(x1, y1, img);
	}
}
