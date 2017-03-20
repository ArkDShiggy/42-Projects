/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <eflorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 13:32:27 by eflorenz          #+#    #+#             */
/*   Updated: 2016/11/22 02:07:23 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#define BUFF_SIZE 512

char	*ft_realloc(char *tab, int size)
{
	char	*new_tab;

	if (!(new_tab = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	if (tab == NULL)
		return (new_tab);
	ft_strcpy(new_tab, tab);
	free(tab);
	return (new_tab);
}

char	*ft_read_file(int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*str;
	int		ret;
	int		size;

	size = 0;
	if (!(str = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	str[0] = '\0';
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		size += ret;
		str = ft_realloc(str, size + 1);
		buff[ret] = '\0';
		ft_strcat(str, buff);
	}
	if (ret == -1)
		return (NULL);
	return (str);
}
