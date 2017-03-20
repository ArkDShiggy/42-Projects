/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:39:40 by jcatinea          #+#    #+#             */
/*   Updated: 2017/03/09 11:04:36 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_whitespace(char a)
{
	if (a == 32 || (a >= 9 && a <= 13))
	{
		return (1);
	}
	return (0);
}

int		skip_whitespace(char *str, t_position *pos)
{
	while (str[pos->col - 1] && is_whitespace(str[pos->col - 1]))
		(pos->col)++;
	return (OK);
}

int		line_content(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != COMMENT_CHAR)
	{
		if (is_whitespace(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

/*
** skip_comment also removes starting whitespace
*/

void	skip_comment(char *str)
{
	int i;
	int k;
	int len;

	i = 0;
	k = 0;
	len = ft_strlen(str);
	while (is_whitespace(str[k]))
		k++;
	while (str[i + k])
	{
		str[i] = str[i + k];
		if (str[i] == COMMENT_CHAR)
			break ;
		i++;
	}
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
}

void	check_endline(char *str, t_position *pos)
{
	skip_whitespace(str, pos);
	if (str[pos->col - 1] != 0)
		parse_error("Expected end of line", pos);
}
