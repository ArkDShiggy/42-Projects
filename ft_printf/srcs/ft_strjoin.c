/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:49:29 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/13 12:14:16 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	i;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	i = 0;
	while (i < l1 + l2)
	{
		if (i < l1)
			new[i] = s1[i];
		else
			new[i] = s2[i - l1];
		i++;
	}
	new[l1 + l2] = '\0';
	return (new);
}
