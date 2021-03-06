/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 21:33:36 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/04 14:46:52 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(char const *str, int c)
{
	while (1)
	{
		if (*str == c)
			return ((char*)str);
		if (*str == '\0')
			return (NULL);
		str++;
	}
}
