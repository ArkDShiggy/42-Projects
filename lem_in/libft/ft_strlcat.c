/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:07:22 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/13 14:24:01 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t l1;
	size_t l2;
	size_t i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (size < l1)
	{
		return (size + l2);
	}
	i = 0;
	while (s2[i] && i + l1 < size - 1)
	{
		s1[i + l1] = s2[i];
		i++;
	}
	s1[i + l1] = '\0';
	return (l1 + l2);
}
