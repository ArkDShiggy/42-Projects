/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 11:52:43 by jcatinea          #+#    #+#             */
/*   Updated: 2017/06/04 11:52:45 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

int		main(int argc, char **argv)
{
	t_data *data;

    if (argc < 2)
        error("Filename missing");
    else
    {
        data = get_data_from_file(argv[1]);
		ft_putstr("print\n");
		print_data(data);
		free(data->data);
		free(data);
    }
	return (0);
    /*
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 400, 400, "mlx 42 ");
    mlx_loop(mlx);
    */
}
