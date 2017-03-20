/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:55:37 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/22 17:13:57 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int		read_file(t_file *file, char **line)
{
	int		n;
	char	buf[BUF_SIZE];
	char	*s;

	if ((n = read(file->fd, buf, BUF_SIZE)) < 0)
		return (-1);
	if (!(s = (char *)ft_memalloc(file->len + n)))
		return (-1);
	if (file->len > 0)
		ft_memcpy(s, file->str, file->len);
	if (n > 0)
		ft_memcpy(s + file->len, buf, n);
	else
	{
		if (!(*line = (char *)ft_memalloc(file->len + 1)))
			return (-1);
		ft_memcpy(*line, file->str, file->len);
	}
	free(file->str);
	file->str = s;
	file->len += n;
	return (n);
}

static t_file	*get_file(int fd)
{
	t_file			*file;
	static t_list	*node;
	t_list			*new;
	t_list			*next;

	next = node;
	while (next)
	{
		if ((((t_file *)(next->content))->fd) == fd)
			return ((t_file *)(next->content));
		next = next->next;
	}
	if (!(file = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	file->fd = fd;
	file->len = 0;
	file->str = NULL;
	if (!(new = ft_lstnew(file, sizeof(t_file))))
		return (NULL);
	if (node)
		new->next = node;
	node = new;
	return ((t_file *)(node->content));
}

static int		nl_split(t_file *file, char **line, char *file_cpy, char *s1)
{
	char *s2;

	if (!(file->str = (char *)ft_memalloc(file->len - (s1 + 1 - file_cpy))))
		return (0);
	ft_memcpy(file->str, s1 + 1, file->len - (s1 + 1 - file_cpy));
	if (!(s2 = (char *)ft_memalloc(s1 - file_cpy + 1)))
		return (0);
	ft_memcpy(s2, file_cpy, s1 - file_cpy);
	s2[s1 - file_cpy] = '\0';
	file->len -= (s1 + 1 - file_cpy);
	*line = s2;
	free(file_cpy);
	return (1);
}

static int		check_for_nl(t_file *file, char **line, int n)
{
	char *file_cpy;
	char *s1;

	n++;
	if (!(file_cpy = (char *)ft_memalloc(file->len)))
		return (0);
	ft_memcpy(file_cpy, file->str, file->len);
	if (!(s1 = (char *)ft_memchr(file_cpy, '\n', file->len)))
		return (1);
	if (nl_split(file, line, file_cpy, s1) == 0)
		return (0);
	else
		return (2);
}

int				get_next_line(int fd, char **line)
{
	t_file	*file;
	int		n;
	int		i;

	if (!(file = get_file(fd)) || fd < 0)
		return (-1);
	n = BUF_SIZE + 1;
	while (n > 0)
	{
		if (!(i = check_for_nl(file, line, n)))
			return (-1);
		if (i >= 2)
			return (1);
		n = read_file(file, line);
	}
	if (n < 0)
		return (-1);
	if (file->len > 0)
	{
		file->len = 0;
		return (1);
	}
	return (0);
}
