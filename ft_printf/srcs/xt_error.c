/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xt_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:00:10 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/28 17:00:12 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*xt_strdup(const char *s1)
{
	char *a;

	if (!(a = ft_strdup(s1)))
		malloc_error("strdup");
	return (a);
}

char	*xt_strjoin(char const *s1, char const *s2)
{
	char *a;

	if (!(a = ft_strjoin(s1, s2)))
		malloc_error("strjoin");
	return (a);
}

char	*xt_strnew(size_t size)
{
	char *a;

	if (!(a = ft_strnew(size)))
		malloc_error("strnew");
	return (a);
}

char	*xt_strsub(char const *s, unsigned int start, size_t len)
{
	char *a;

	if (!(a = ft_strsub(s, start, len)))
		malloc_error("strsub");
	return (a);
}
