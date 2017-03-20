/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:01:05 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/13 12:15:10 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**tab_realloc(char **tab, char *s, size_t size)
{
	size_t	i;
	char	**new;

	i = 0;
	if (!(new = (char **)malloc((sizeof(char *)) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		new[i] = tab[i];
		i++;
	}
	if (size > 0)
		new[size - 1] = s;
	new[size] = 0;
	free(tab);
	return (new);
}

static char		**init(size_t *i, size_t *size)
{
	char **tab;

	*i = 0;
	*size = 0;
	if (!(tab = (char **)malloc(sizeof(char *))))
		return (NULL);
	tab[0] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!s || !(tab = init(&i, &size)))
		return (NULL);
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j > 0)
		{
			if (!(str = ft_strsub(s, i, j)))
				return (NULL);
			if (!(tab = tab_realloc(tab, str, ++size)))
				return (NULL);
			i += (j - 1);
		}
		i++;
	}
	return (tab);
}
