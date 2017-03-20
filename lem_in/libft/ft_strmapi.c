/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:37:43 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/13 12:11:45 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	unsigned int	len;
	char			*new;

	if (s)
	{
		index = 0;
		len = ft_strlen(s);
		if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (index < len)
		{
			new[index] = (*f)(index, s[index]);
			index++;
		}
		new[len] = '\0';
		return (new);
	}
	return (NULL);
}
