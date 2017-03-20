/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:29:41 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/13 12:19:03 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = (*f)(s[i]);
		i++;
	}
	new[len] = '\0';
	return (new);
}
