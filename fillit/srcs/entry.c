/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:12:29 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/22 06:50:57 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_pieces(char *file)
{
	int count;
	int lines;
	int i;

	i = -1;
	count = 0;
	lines = 0;
	while (file[++i])
	{
		if (file[i] == '\n')
		{
			if ((++lines % 5 > 0) && (((i - count) % 5) != 4))
				erreur();
			else if (lines % 5 == 0)
			{
				if (((i - count) % 5) != 0)
					erreur();
				count++;
			}
		}
	}
	return (count + 1);
}

t_piece	**read_entry(int fd)
{
	char	*file;
	t_piece	**list;
	int		count;
	int		i;

	if ((file = ft_read_file(fd)) == NULL)
		erreur();
	if ((count = count_pieces(file)) > 26)
		erreur();
	i = 0;
	if (!(list = (t_piece **)malloc(sizeof(t_piece *) * (count + 1))))
		malloc_error();
	while (i < count - 1)
	{
		list[i] = read_block(file + i * 21);
		if (file[i * 21 + 20] != '\n')
			erreur();
		i++;
	}
	list[i] = read_block(file + i * 21);
	list[i + 1] = 0;
	return (list);
}
