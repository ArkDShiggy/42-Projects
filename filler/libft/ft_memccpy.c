/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:45:32 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/07 13:40:19 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	byte;

	i = 0;
	while (i < n)
	{
		byte = *((unsigned char *)src + i);
		*((unsigned char *)dst + i) = byte;
		if (byte == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
