/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:54:29 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/13 15:14:21 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	l;
	char	*str;

	if (!s)
		return (NULL);
	l = ft_strlen(s) - 1;
	while ((s[l] == ' ' || s[l] == '\t' || s[l] == '\n') && l > 0)
		l--;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (i != ft_strlen(s))
		return (ft_strsub(s, i, l - i + 1));
	if (!(str = (char *)malloc(sizeof(char))))
		return (NULL);
	str[0] = '\0';
	return (str);
}
