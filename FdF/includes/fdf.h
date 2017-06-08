/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 14:55:38 by jcatinea          #+#    #+#             */
/*   Updated: 2017/06/04 14:55:39 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

# define WIN_WID 400
# define WIN_HEI 400
# define ANGLE 0
# define Z_OFFSET 100

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_midpoint
{
	int			slopegt;
	int			incry;
	int			dy;
	int			dx;
}				t_midpoint;

typedef struct	s_data
{
	int			width;
	int			height;
	int			*data;
}				t_data;

void			error(char *str);
t_data			*get_data_from_file(char *filename);
void			print_image(void *mlx, void *win, t_data *data);
void			draw_pixel(int x, int y, char *pix_ar);
void			draw_image(char *pix_ar, t_data *data);
int				handle_key(int keycode, void *param);

void			data_to_points(t_data *data, t_point *array);
t_point			transform(int x, int y, int z, t_point *dim);

void			draw_line_points(int x1, int y1, int x2, int y2);
void			draw_line(t_point *p1, t_point *p2, char *img);
void			draw_line_two(t_point *p1, t_point *p2, t_midpoint *tmp,
	 char *img);

void			print_data(t_data *data);
void			print_hexa(char *pix_ar);

#endif
