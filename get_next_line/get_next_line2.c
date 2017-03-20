/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:55:37 by jcatinea          #+#    #+#             */
/*   Updated: 2017/03/07 11:34:41 by cfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static void		gnl_error(void)
{
	ft_putendl_fd("Error while reading file", 2);
	exit(0);
}

static void		binary_error(void)
{
	ft_putendl_fd("Input file contains \\0", 2);
	exit(0);
}

static int		read_file(int fd, char **mem_str)
{
	char	buf[BUFF_SIZE];
	char	*new_mem_str;
	int		read_len;
	int		i;

	if ((read_len = read(fd, buf, BUFF_SIZE)) < 0)
		gnl_error();
	if (read_len == 0)
		return (0);
	i = 0;
	while (i < read_len)
	{
		if (buf[i] == 0)
			binary_error();
		i++;
	}
	new_mem_str = (char *)ft_malloc(sizeof(char) *
		(ft_strlen(*mem_str) + read_len + 1));
	ft_strcpy(new_mem_str, *mem_str);
	ft_memcpy(new_mem_str + ft_strlen(*mem_str), buf, read_len);
	new_mem_str[ft_strlen(*mem_str) + read_len] = 0;
	free(*mem_str);
	*mem_str = new_mem_str;
	return (1);
}

static	void	split_mem(char **mem_str, char **line)
{
	int		i;
	char	*new;

	i = 0;
	while ((*mem_str)[i] != '\n')
		i++;
	*line = (char *)ft_malloc(sizeof(char) * (i + 1));
	if (i > 0)
		ft_strncpy(*line, *mem_str, i);
	(*line)[i] = 0;
	new = (char *)ft_malloc(ft_strlen(*mem_str) - i);
	ft_strcpy(new, (*mem_str) + i + 1);
	new[ft_strlen(*mem_str) - i - 1] = 0;
	free(*mem_str);
	*mem_str = new;
}

int				get_next_line(int fd, char **line)
{
	static char	*mem_str = NULL;
	int			n;

	if (mem_str == NULL)
		mem_str = ft_strnew(0);
	n = 1;
	if (fd < 0)
		return (-1);
	while (n > 0)
	{
		if (ft_strinc('\n', mem_str))
		{
			split_mem(&mem_str, line);
			return (1);
		}
		n = read_file(fd, &mem_str);
	}
	free(mem_str);
	return (0);
}
