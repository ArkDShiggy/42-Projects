/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:22:35 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/10 12:41:29 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		n;
	int		i;

	n = ft_strlen(s1);
	if (!(s2 = (char*)malloc(sizeof(char) * (n + 1))))
		return (0);
	i = 0;
	while (i <= n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
