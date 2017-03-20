/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 06:50:22 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/22 06:50:54 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			g_tetromino[19][21] = {
	"##..\n##..\n....\n....\n",
	"####\n....\n....\n....\n",
	"#...\n#...\n#...\n#...\n",
	"#...\n##..\n#...\n....\n",
	"###.\n.#..\n....\n....\n",
	".#..\n##..\n.#..\n....\n",
	".#..\n###.\n....\n....\n",
	"###.\n..#.\n....\n....\n",
	"##..\n#...\n#...\n....\n",
	"#...\n###.\n....\n....\n",
	".#..\n.#..\n##..\n....\n",
	"..#.\n###.\n....\n....\n",
	"##..\n.#..\n.#..\n....\n",
	"###.\n#...\n....\n....\n",
	"#...\n#...\n##..\n....\n",
	"##..\n.##.\n....\n....\n",
	".#..\n##..\n#...\n....\n",
	".##.\n##..\n....\n....\n",
	"#...\n##..\n.#..\n....\n"
};

void	push_up(char *s)
{
	int i;
	int j;

	j = 0;
	while (s[0] == '.' && s[1] == '.' && s[2] == '.' && s[3] == '.' && j < 5)
	{
		i = -1;
		while (++i < 19)
		{
			if (i < 15)
				s[i] = s[i + 5];
			else
				s[i] = '.';
		}
		j++;
	}
}

void	push_left(char *s)
{
	int i;
	int j;

	j = 0;
	while (s[0] == '.' && s[5] == '.' && s[10] == '.' && s[15] == '.' && j < 5)
	{
		i = -1;
		while (++i < 20)
		{
			if ((i % 5) < 3)
				s[i] = s[i + 1];
			if ((i % 5) == 3)
				s[i] = '.';
		}
		j++;
	}
}

int		valid_block(char *s)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if (ft_strcmp(g_tetromino[i], s) == 0)
			return (1);
		i++;
	}
	erreur();
	return (0);
}

t_piece	*read_block(char *s)
{
	int		i;
	char	*piece;

	if (!(piece = (char *)malloc(sizeof(char) * 20)))
		malloc_error();
	i = -1;
	while (++i < 20)
	{
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
			erreur();
		piece[i] = s[i];
	}
	piece[20] = '\0';
	push_up(piece);
	push_left(piece);
	valid_block(piece);
	return (block_code(piece));
}
