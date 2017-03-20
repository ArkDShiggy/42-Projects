/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:17:36 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/22 10:37:39 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

int		get_info(t_info *info)
{
	char *line;

	get_next_line(0, &line);
	if (line[0] == 'P' && line[1] == 'l')
	{
		get_map_size(info, line);
		free(info->map_str);
		if (!(info->map_str = ft_strnew(info->map_h * info->map_w + 1)))
			return (0);
		get_map_info(info);
	}
	else if (line[0] == 'P' && line[1] == 'i')
	{
		get_piece_size(info, line);
		free(info->piece_str);
		if (!(info->piece_str = ft_strnew(info->piece_h * info->piece_w + 1)))
			return (0);
		get_piece_info(info);
		info->status = 2;
	}
	return (1);
}

void	print_result(int x, int y)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

void	free_all(t_info *info)
{
	free(info->map_str);
	free(info->piece_str);
	free(info->previous_map);
}

int		main(void)
{
	t_info info[1];

	info->status = -1;
	info->previous_map = NULL;
	while (1)
	{
		if (info->status == -1)
			get_player(info);
		if (info->status == 0 || info->status == 1)
		{
			if (!(get_info(info)))
				return (0);
		}
		if (info->status == 2)
		{
			if (!(eval_map(info)))
			{
				free_all(info);
				return (0);
			}
			info->status = 0;
		}
	}
	return (0);
}
