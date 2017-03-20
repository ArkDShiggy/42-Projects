/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:09:18 by ndombre           #+#    #+#             */
/*   Updated: 2017/02/23 11:47:07 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_malloc(size_t s)
{
	void	*ptr;

	ptr = malloc(s);
	if (!ptr)
		ft_error("ERROR MALLOC", -1);
	ft_memset(ptr, '~', s);
	return (ptr);
}
