/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:55:30 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/13 14:58:14 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t l1;
	size_t l2;
	size_t i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	i = 0;
	while (s2[i] && i < n)
	{
		s1[l1 + i] = s2[i];
		i++;
	}
	s1[l1 + i] = '\0';
	return (s1);
}
