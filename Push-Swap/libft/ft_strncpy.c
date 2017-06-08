/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:30:36 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/07 17:12:58 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t n;

	n = ft_strlen(src);
	if (len >= (n + 1))
	{
		ft_memcpy(dst, (char *)src, n + 1);
		ft_bzero(dst + n, len - n);
	}
	else
		ft_memcpy(dst, (char *)src, len);
	return (dst);
}
