/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:25:21 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/02 16:31:08 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_v_wall(t_info *info, int a)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < info->map_h)
	{
		if (info->map_str[a + i * info->map_w] == info->player)
			return (1);
		if (info->map_str[a + i * info->map_w] == info->opponent)
			count++;
		i++;
	}
	if (count == info->map_h - 1)
		return (2);
	return (0);
}

int		check_h_wall(t_info *info, int a)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < info->map_w)
	{
		if (info->map_str[i + a * info->map_w] == info->player)
			return (1);
		if (info->map_str[a + i * info->map_w] == info->opponent)
			count++;
		i++;
	}
	if (count == info->map_h - 1)
		return (2);
	return (0);
}
