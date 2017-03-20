/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:50:03 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/13 10:50:05 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_antfarm	*get_antfarm(void)
{
	t_antfarm	*antfarm;
	char		*line;

	if (!(antfarm = (t_antfarm *)malloc(sizeof(t_antfarm))))
	{
		free(antfarm);
		malloc_error(NULL);
	}
	antfarm->room_num = 0;
	if (!(antfarm->rooms = new_larray(8, sizeof(t_room))))
	{
		free_antfarm(antfarm);
		malloc_error_one(antfarm, "get_antfarm");
	}
	get_next_line(0, &line);
	if (line[0] == '#')
	{
		free(line);
		return (get_antfarm());
	}
	if ((antfarm->ant_num = ft_atoi(line)) <= 0)
		return (NULL);
	free(line);
	return (antfarm);
}

int			is_comment(char *str)
{
	if (str[0] != '#')
		return (0);
	if (ft_strequ(str, "##start"))
		return (2);
	if (ft_strequ(str, "##end"))
		return (2);
	return (1);
}

int			get_special(char **line)
{
	int special;
	int a;

	special = 0;
	a = 1;
	while (a > 0 && is_comment(*line) == 1)
	{
		free(*line);
		a = get_next_line(0, line);
	}
	if (ft_strequ(*line, "##start"))
		special = 1;
	else if (ft_strequ(*line, "##end"))
		special = 2;
	if (a > 0 && is_comment(*line) == 2)
	{
		ft_putendl(*line);
		free(*line);
		get_next_line(0, line);
	}
	return (special);
}

int			create_graph(t_antfarm *antfarm)
{
	int		special;
	int		a;
	char	*line;
	int		phase;

	a = get_next_line(0, &line);
	phase = 0;
	while (a == 1)
	{
		special = get_special(&line);
		if (is_comment(line) == 2)
			break ;
		else if (ft_strinc(line, ' ') == 0)
		{
			phase = 1;
			break ;
		}
		else if (read_room(antfarm, line, special) == 0)
			break ;
		else
			ft_putendl(line);
		free(line);
		a = get_next_line(0, &line);
	}
	return (create_graph_two(antfarm, line, phase));
}

int			create_graph_two(t_antfarm *antfarm, char *line, int phase)
{
	int		a;

	a = 1;
	while (a == 1)
	{
		if (line[0] == '#' || ft_strlen(line) == 0)
			;
		else if (read_link(antfarm, line) == 0)
			break ;
		else
			ft_putendl(line);
		free(line);
		a = get_next_line(0, &line);
	}
	free(line);
	if (phase == 0)
		free_antfarm(antfarm);
	return (phase);
}
