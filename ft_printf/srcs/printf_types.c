/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:37:40 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/29 16:37:43 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_d(t_options *options, va_list args)
{
	int		value;
	int		len;
	int		sign;
	char	*str;

	value = va_arg(args, int);
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

int		print_ld(t_options *options, va_list args)
{
	long int	value;
	int			len;
	int			sign;
	char		*str;

	value = va_arg(args, long int);
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

int		print_lld(t_options *options, va_list args)
{
	long long int	value;
	int				len;
	int				sign;
	char			*str;

	value = va_arg(args, long long int);
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
	len = 0;
	len = ft_strlen(str);
	adjust(str, options, sign, &len);
	free(str);
	return (len);
}

int		print_hd(t_options *options, va_list args)
{
	short int	value;
	int			len;
	int			sign;
	char		*str;

	value = va_arg(args, int);
	sign = (value > 0) - (value < 0);
	str = NULL;
	if (options->fill == '0' && options->precision >= 0)
		options->fill = 0;
	if (options->precision < 0)
		options->precision = 1;
	str = xt_itoa(value, options, str);
	len = ft_strlen(str);
	adjust(str, options, sign, &len);
	free(str);
	return (len);
}

int		print_hhd(t_options *options, va_list args)
{
	char	value;
	int		len;
	int		sign;
	char	*str;

	value = (char)va_arg(args, int);
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
