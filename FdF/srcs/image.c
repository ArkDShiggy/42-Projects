/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 17:55:38 by jcatinea          #+#    #+#             */
/*   Updated: 2017/06/04 17:57:50 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	data_to_points(t_data *data, t_point *array)
{
	int		i;
	int		j;
	t_point	a;
	t_point	*dim;

	dim = (t_point *)ft_malloc(sizeof(t_point));
	dim->x = data->width;
	dim->y = data->height;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			a = transform(j, i, data->data[i * data->width + j], dim);
			array[i * data->width + j] = a;
			j++;
		}
		i++;
	}
	free(dim);
}

t_point	transform(int x, int y, int z, t_point *dim)
{
	float	x2;
	float	y2;
	float	z2;
	t_point	result;

	x2 = x - dim->x / 2;
	y2 = cos(ANGLE) * y + sin(ANGLE) * z - dim->y / 2;
	z2 = cos(ANGLE) * z - sin(ANGLE) * y - Z_OFFSET;
	if (z2 < 0)
	{
		result.x = round((((-x2 / z2) + 1) / 2) * WIN_HEI);
		result.y = round((((-y2 / z2) + 1) / 2) * WIN_HEI);
	}
	else
	{
		result.x = -1;
		result.y = -1;
	}
	return (result);
}

int		on_screen(t_point *p1, t_point *p2)
{
	if (p1->x >= 0 && p1->x < WIN_WID && p1->y >= 0 && p1->y < WIN_HEI &&
		p2->x >= 0 && p2->x < WIN_WID && p2->y >= 0 && p2->y < WIN_HEI)
	{
		return (1);
	}
	else
		return (0);
}

void	draw_image_two(t_point *ij, t_data *data, char *pix_ar, t_point *array)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;

	i = ij->x;
	j = ij->y;
	if (j < data->width - 1)
	{
		p1 = array[i * data->width + j];
		p2 = array[i * data->width + (j + 1)];
		if (on_screen(&p1, &p2))
			draw_line(&p1, &p2, pix_ar);
	}
	if (i < data->height - 1)
	{
		p1 = array[i * data->width + j];
		p2 = array[(i + 1) * data->width + j];
		if (on_screen(&p1, &p2))
			draw_line(&p1, &p2, pix_ar);
	}
}

void	draw_image(char *pix_ar, t_data *data)
{
	int		i;
	int		j;
	t_point *ij;
	t_point	*array;

	ij = (t_point *)ft_malloc(sizeof(t_point));
	array = (t_point *)ft_malloc(sizeof(t_point) * data->width * data->height);
	data_to_points(data, array);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			ij->x = i;
			ij->y = j;
			draw_image_two(ij, data, pix_ar, array);
			j++;
		}
		i++;
	}
	free(array);
	free(ij);
}
