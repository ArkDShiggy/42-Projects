/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:28:08 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/07 15:53:44 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int n;

	n = ft_strlen(src);
	dst = ft_memcpy(dst, (char *)src, n + 1);
	return (dst);
}
