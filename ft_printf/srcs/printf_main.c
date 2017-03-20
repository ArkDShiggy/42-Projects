/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:17:12 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/28 11:47:50 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

void	error(char *s)
{
	if (s)
		ft_putstr_fd(s, 2);
}

void	malloc_error(char *s)
{
	ft_putstr_fd("Error while allocating memory", 2);
	if (s)
		ft_putstr_fd(s, 2);
	ft_putchar_fd('\n', 2);
	exit(-1);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			len++;
		}
		else
			len += percent_eval((char *)str, &i, args);
		i++;
	}
	va_end(args);
	return (len);
}
