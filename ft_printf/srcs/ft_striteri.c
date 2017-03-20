/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:23:32 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/13 12:23:43 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	size_t			len;

	if (s && f)
	{
		len = ft_strlen(s);
		i = 0;
		while ((size_t)i < len)
		{
			(*f)(i, s + i);
			i++;
		}
	}
}
