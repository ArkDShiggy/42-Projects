/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:43:07 by jcatinea          #+#    #+#             */
/*   Updated: 2017/06/07 17:43:09 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

char	*get_img_address(void *img)
{
	int		a;
	int		b;
	int		c;
	char	*pix_ar;

	pix_ar = mlx_get_data_addr(img, &a, &b, &c);
	return (pix_ar);
}

void	start_mlx(t_data *data)
{
	void *mlx;
	void *win;
	void *img;
	char *pix_ar;
	void *param;

	param = NULL;
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WID, WIN_HEI, "FdF");
	img = mlx_new_image(mlx, WIN_WID, WIN_HEI);
	pix_ar = get_img_address(img);
	draw_image(pix_ar, data);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_key_hook(win, &handle_key, param);
	mlx_loop(mlx);
}

int		main(int argc, char **argv)
{
	t_data *data;

	if (argc != 2)
		error("Wrong number of arguments");
	else
	{
		data = get_data_from_file(argv[1]);
		start_mlx(data);
		free(data->data);
		free(data);
	}
	return (0);
}
