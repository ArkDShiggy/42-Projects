/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:12:59 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/22 02:14:16 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*piece_init(void)
{
	t_piece *new;

	if (!(new = (t_piece *)malloc(sizeof(t_piece))))
		malloc_error();
	new->width = 0;
	new->height = 0;
	new->placed = 0;
	return (new);
}

t_piece	*piece_copy(t_piece *piece, int placed)
{
	t_piece	*new;
	int		i;

	if (!(new = (t_piece*)malloc(sizeof(t_piece))))
		malloc_error();
	new->width = piece->width;
	new->height = piece->height;
	i = -1;
	while (++i < 4)
		new->coord[i] = piece->coord[i];
	if (placed)
		new->placed = placed;
	else
		new->placed = piece->placed;
	return (new);
}

t_piece	*block_code(char *s)
{
	int		i;
	int		j;
	t_piece *piece;

	piece = piece_init();
	j = 0;
	i = -1;
	while (++i < 20)
	{
		if (s[i] == '#')
		{
			if ((i / 5) > piece->height)
				piece->height = i / 5;
			if ((i % 5) > piece->width)
				piece->width = i % 5;
			piece->coord[j] = i;
			if (j == 3)
				break ;
			j++;
		}
	}
	return (piece);
}

void	free_list(t_piece **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}
