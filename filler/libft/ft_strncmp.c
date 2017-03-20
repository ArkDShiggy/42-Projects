/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:15:29 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/13 15:09:22 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t len;

	len = ft_strlen(s1);
	if (n == 0)
		return (0);
	if (len == 0)
		return (-(unsigned char)s2[0]);
	len = ft_strlen(s2);
	if (len == 0)
		return ((unsigned char)s1[0]);
	if (s1[0] == s2[0])
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
	else
		return ((unsigned char)s1[0] - (unsigned char)s2[0]);
}
