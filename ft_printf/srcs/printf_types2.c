/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:37:40 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/29 16:37:43 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_jd(t_options *options, va_list args)
{
	intmax_t	value;
	int			len;
	int			sign;
	char		*str;

	value = va_arg(args, intmax_t);
	sign = (value > 0) - (value < 0);
	str = NULL;
	if (options->fill == '0' && options->precision >= 0)
		options->fill = 0;
	if (options->precision < 0)
		options->precision = 1;
	if (value == 0 && options->precision == 0)
		str = xt_strnew(0);
	else
		str = xt_itoa(value, options, str);
	len = ft_strlen(str);
	adjust(str, options, sign, &len);
	free(str);
	return (len);
}

int		print_zd(t_options *options, va_list args)
{
	ssize_t		value;
	int			len;
	int			sign;
	char		*str;

	value = va_arg(args, ssize_t);
	sign = (value > 0) - (value < 0);
	str = NULL;
	if (options->fill == '0' && options->precision >= 0)
		options->fill = 0;
	if (options->precision < 0)
		options->precision = 1;
	if (value == 0 && options->precision == 0)
		str = xt_strnew(0);
	else
		str = xt_itoa(value, options, str);
	len = ft_strlen(str);
	adjust(str, options, sign, &len);
	free(str);
	return (len);
}

int		print_ju(t_options *options, va_list args)
{
	uintmax_t	value;
	int			len;
	int			sign;
	char		*str;

	value = va_arg(args, uintmax_t);
	str = NULL;
	if (options->fill == '0' && options->precision >= 0)
		options->fill = 0;
	if (options->precision < 0)
		options->precision = 1;
	if (value == 0 && options->precision == 0)
		str = xt_strnew(0);
	else
		str = xt_uitoa_base(value, options, str);
	len = ft_strlen(str);
	sign = (value > 0);
	adjust(str, options, sign, &len);
	free(str);
	return (len);
}

int		print_zu(t_options *options, va_list args)
{
	size_t		value;
	int			len;
	int			sign;
	char		*str;

	value = va_arg(args, size_t);
	str = NULL;
	if (options->fill == '0' && options->precision >= 0)
		options->fill = 0;
	if (options->precision < 0)
		options->precision = 1;
	if (value == 0 && options->precision == 0)
		str = xt_strnew(0);
	else
		str = xt_uitoa_base(value, options, str);
	len = ft_strlen(str);
	sign = (value > 0);
	adjust(str, options, sign, &len);
	free(str);
	return (len);
}

int		print_zero_chars(t_options *options)
{
	int i;

	i = 0;
	while (i < options->width - 1 && options->width != '-')
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar(0);
	while (i < options->width - 1 && options->width == '-')
	{
		ft_putchar(' ');
		i++;
	}
	return (i + 1);
}
