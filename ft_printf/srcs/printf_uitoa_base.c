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

static int	get_ulength(uintmax_t value, int base, int precision)
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
	if (flag == 'x' || flag == 'p')
		return (n - 10 + 'a');
	return (n - 10 + 'A');
}

static int	sign_to_base(int sign)
{
	sign = ft_tolower(sign);
	if (sign == 'u')
		return (10);
	if (sign == 'o')
		return (8);
	if (sign == 'b')
		return (2);
	if (sign == 'x' || sign == 'p')
		return (16);
	return (sign);
}

char		*xt_uitoa_base(uintmax_t value, t_options *options, char *new)
{
	int		len;
	int		base;

	base = sign_to_base(options->flag);
	if (value == 0)
	{
		new = xt_strnew(options->precision);
		ft_memset(new, '0', options->precision);
		return (new);
	}
	len = get_ulength(value, base, options->precision);
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		malloc_error("xt_uitoa_base");
	new[len] = '\0';
	while (len >= 0)
	{
		len--;
		new[len] = get_char(value % base, options->flag);
		value = value / base;
	}
	return (new);
}
