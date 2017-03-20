/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 13:34:08 by jcatinea          #+#    #+#             */
/*   Updated: 2017/03/09 11:06:14 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		read_header_str(char *str, t_position *pos, int fd, t_nc *new)
{
	skip_whitespace(str, pos);
	if (str[pos->col - 1] != '"')
		parse_error("Expecting \" before end of line", pos);
	(pos->col)++;
	if (read_header_str_two(str, pos, fd, new) == 0)
		parse_error("Expecting \" before end of file", pos);
}

int			read_header_str_two(char *str, t_position *pos, int fd, t_nc *new)
{
	int i;
	int a;

	i = 0;
	a = 1;
	while (a > 0)
	{
		while (str[pos->col - 1] && str[pos->col - 1] != '"')
		{
			if (i == new->length)
				error("Name or comment is too long");
			new->dest[i++] = str[pos->col++ - 1];
		}
		if (str[pos->col - 1] == '"')
		{
			pos->col++;
			check_endline(str, pos);
			return (1);
		}
		if (str[pos->col - 1] == 0)
			read_header_new_line(pos, &i, new);
		free(str);
		a = get_next_line(fd, &str);
	}
	return (0);
}

void		read_header_new_line(t_position *pos, int *i, t_nc *new)
{
	if (*i == new->length)
		error("Name or comment is too long");
	pos->col = 1;
	(pos->line)++;
	new->dest[*i] = '\n';
	(*i)++;
}

int			get_header_str(t_header *header, char *str, t_position *pos, int fd)
{
	int		len;
	int		a;
	char	*sub;
	t_nc	*new;

	skip_whitespace(str, pos);
	len = ft_strlen(NAME_CMD_STRING);
	sub = ft_strsub(str, pos->col - 1, len);
	if ((a = 2) && ft_strequ(sub, NAME_CMD_STRING) == 0 && (a -= 1))
	{
		free(sub);
		len = ft_strlen(COMMENT_CMD_STRING);
		sub = ft_strsub(str, pos->col - 1, len);
		if (ft_strequ(sub, COMMENT_CMD_STRING) == 0)
		{
			free(sub);
			return (0);
		}
	}
	free(sub);
	pos->col += len;
	new = get_nc(header, a);
	read_header_str(str, pos, fd, new);
	free(new);
	return (a);
}

t_header	*read_header(int fd, t_position *pos)
{
	char		*str;
	t_header	*new;
	int			a;

	a = 0;
	new = (t_header *)ft_memalloc(sizeof(t_header));
	while (get_next_line(fd, &str) > 0)
	{
		if (line_content(str) == 1 && (skip_whitespace(str, pos)))
		{
			if (get_header_str(new, str, pos, fd) == 0)
			{
				free(new);
				free(str);
				parse_error("Missing name and/or comment", pos);
			}
			else
				a++;
		}
		free(str);
		if (((++(pos->line)) || !pos->line) && (pos->col = 1) && a == 2)
			return (new);
	}
	error("Empty file");
	return (NULL);
}
