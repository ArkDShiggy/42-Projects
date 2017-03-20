/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:09:53 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/28 17:09:22 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	get_length(intmax_t value, int base, int precision)
{
	int len;

	len = 0;
	while (value != 0)
	{
		value /= base;
		len++;
	}
	if (precision > len)
		len = precision;
	return (len);
}

static char	get_char(int n, char flag)
{
	if (n < 10)
		return (n + '0');
	if (flag == 'x')
		return (n - 10 + 'a');
	return (n - 10 + 'A');
}

char		*xt_itoa(intmax_t value, t_options *options, char *new)
{
	int		len;
	int		sign;

	sign = (value > 0) - (value < 0);
	if (value == 0)
	{
		new = xt_strnew(options->precision);
		ft_memset(new, '0', options->precision);
		return (new);
	}
	len = get_length(value, 10, options->precision);
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		malloc_error("xt_itoa");
	new[len] = '\0';
	while (len >= 0)
	{
		len--;
		new[len] = get_char((value % 10) * sign, options->flag);
		value = value / 10;
	}
	return (new);
}
