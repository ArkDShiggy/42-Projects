/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:55:49 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/07 15:48:18 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int n;

	i = 0;
	n = ft_strlen(s);
	while (i <= n)
	{
		if (s[n - i] == c)
			return ((char *)s + n - i);
		i++;
	}
	return (NULL);
}
