/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:01:47 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/10 12:42:57 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
	{
		while (len > 0)
		{
			*((unsigned char *)dst + len - 1) = \
				*((unsigned char *)src + len - 1);
			len--;
		}
	}
	else
		ft_memcpy(dst, (void *)src, len);
	return (dst);
}
