/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:10:13 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/13 12:00:31 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int l1;
	int l2;

	l1 = ft_strlen(s1);
	if (!l1)
		return (-(unsigned char)s2[0]);
	l2 = ft_strlen(s2);
	if (!l2)
		return ((unsigned char)s1[0]);
	if (s1[0] == s2[0])
		return (ft_strcmp(s1 + 1, s2 + 1));
	else
		return ((unsigned char)s1[0] - (unsigned char)s2[0]);
}
