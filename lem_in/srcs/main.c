/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 14:43:39 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/24 14:43:41 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(t_antfarm *antfarm)
{
	antfarm = NULL;
	ft_putendl_fd("ERROR", 1);
	exit(0);
}

void	malloc_error_one(t_antfarm *antfarm, char *s)
{
	free_antfarm(antfarm);
	malloc_error(s);
}

void	malloc_error(char *s)
{
	if (!s)
		s = "the program";
	ft_putstr_fd("Error while allocating memory in ", 2);
	ft_putstr_fd(s, 2);
	ft_putchar_fd('\n', 2);
	exit(0);
}

void	malloc_error_two(t_antfarm *antfarm, t_path **array, t_path *path)
{
	free_path(path);
	free_path_array(array, antfarm->ant_num);
	malloc_error_one(antfarm, "explore");
}

int		main(void)
{
	t_antfarm	*antfarm;
	t_path		**paths;

	if ((antfarm = get_antfarm()) == NULL)
		error(antfarm);
	ft_putnbr(antfarm->ant_num);
	ft_putchar('\n');
	if (create_graph(antfarm) == 0)
		error(antfarm);
	if (!(paths = find_paths(antfarm)))
		error(antfarm);
	if (paths[0] == NULL)
		error(antfarm);
	ft_putchar('\n');
	solve(paths, antfarm->ant_num);
	free_path_array(paths, antfarm->ant_num);
	free_antfarm(antfarm);
	return (0);
}
