/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:02:31 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/22 06:31:03 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	erreur(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	malloc_error(void)
{
	ft_putstr("Error while allocating memory.Try again\n");
	exit(0);
}

void	usage(void)
{
	ft_putstr("usage: ./fillit entry_file\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_piece	**list;
	t_map	*map;
	int		i;

	i = 0;
	if (argc != 2)
		usage();
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr("file ");
			erreur();
		}
		else
		{
			list = read_entry(fd);
			map = test_size(list);
			print_map(map);
			free(map->map);
		}
	}
	return (0);
}
