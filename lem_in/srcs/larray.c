/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   larray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 09:54:46 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/24 09:54:48 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "larray.h"

static t_larray	*increase_larray_size(t_larray *larray, int index)
{
	int		new_len;
	void	**new_arrays;
	int		i;

	new_len = index / larray->inner_len + 1;
	if (!(new_arrays = (void **)malloc(sizeof(void *) * new_len)))
		return (NULL);
	i = 0;
	while (i < larray->outer_len)
	{
		new_arrays[i] = larray->arrays[i];
		i++;
	}
	while (i < new_len)
	{
		if (!(new_arrays[i] = ft_memalloc(larray->size * larray->inner_len)))
			new_len = i - 1;
		i++;
	}
	free(larray->arrays);
	larray->arrays = new_arrays;
	larray->outer_len = new_len;
	if (new_len < (index / larray->inner_len + 1))
		return (NULL);
	return (larray);
}

t_larray		*new_larray(int inner_len, size_t size)
{
	t_larray *new;

	if (!(new = (t_larray *)malloc(sizeof(t_larray))))
		return (NULL);
	new->arrays = NULL;
	new->size = size;
	new->outer_len = 0;
	new->inner_len = inner_len;
	return (new);
}

void			*get_larray(t_larray *larray, int index)
{
	int				i;
	int				j;
	unsigned char	*str;
	void			*value;

	if (index < (larray->inner_len * larray->outer_len))
	{
		i = index / larray->inner_len;
		j = index % larray->inner_len;
		str = (unsigned char *)(larray->arrays[i]);
		value = (void *)(str + (j * larray->size));
		return (value);
	}
	else
	{
		if (!(increase_larray_size(larray, index)))
		{
			free_larray(larray);
			return (NULL);
		}
		return (get_larray(larray, index));
	}
}

t_larray		*set_larray(t_larray *larray, int index, void *value)
{
	unsigned char	*str;
	void			*ptr;
	int				i;
	int				j;

	if (index < (larray->inner_len * larray->outer_len))
	{
		i = index / larray->inner_len;
		j = index % larray->inner_len;
		str = (unsigned char *)(larray->arrays[i]);
		ptr = (void *)(str + (j * larray->size));
		ft_memcpy(ptr, value, larray->size);
	}
	else
	{
		if (!(increase_larray_size(larray, index)))
		{
			free_larray(larray);
			return (NULL);
		}
		set_larray(larray, index, value);
	}
	return (larray);
}

void			free_larray(t_larray *larray)
{
	int i;

	i = 0;
	while (i < larray->outer_len)
	{
		free(larray->arrays[i]);
		i++;
	}
	free(larray->arrays);
}
