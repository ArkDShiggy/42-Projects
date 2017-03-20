/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:17:36 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/02 15:25:13 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(t_info *info)
{
	int		i;
	char	*line;

	i = 0;
	info->phase = -1;
	info->map_str = NULL;
	info->piece_str = NULL;
	get_next_line(0, &line);
	if (line[0] == '$')
	{
		while (!(ft_isdigit(line[i])))
			i++;
		if (line[i] == '1')
		{
			info->player = 'O';
			info->opponent = 'X';
		}
		if (line[i] == '2')
		{
			info->player = 'X';
			info->opponent = 'O';
		}
		info->status = 1;
	}
	free(line);
}

void	get_map_size(t_info *info, char *line)
{
	int i;

	info->map_h = 0;
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (info->map_h == 0)
				info->map_h = ft_atoi(line + i);
			else
				info->map_w = ft_atoi(line + i);
			while (ft_isdigit(line[i]))
				i++;
		}
		i++;
	}
}

void	get_piece_size(t_info *info, char *line)
{
	int i;

	info->piece_h = 0;
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (info->piece_h == 0)
				info->piece_h = ft_atoi(line + i);
			else
				info->piece_w = ft_atoi(line + i);
			while (ft_isdigit(line[i]))
				i++;
		}
		i++;
	}
}

void	get_map_info(t_info *info)
{
	int		i;
	int		j;
	int		offset;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	while (i < info->map_h)
	{
		offset = 0;
		get_next_line(0, &line);
		while (line[offset] != ' ')
			offset++;
		offset++;
		j = 0;
		while (line[offset + j])
		{
			info->map_str[i * info->map_w + j] = line[offset + j];
			j++;
		}
		i++;
	}
}

void	get_piece_info(t_info *info)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < info->piece_h)
	{
		get_next_line(0, &line);
		j = 0;
		while (line[j])
		{
			info->piece_str[i * info->piece_w + j] = line[j];
			j++;
		}
		i++;
	}
}
