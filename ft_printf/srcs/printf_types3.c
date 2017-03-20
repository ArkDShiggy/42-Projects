/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:17:01 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/30 10:17:02 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_u(t_options *options, va_list args)
{
	unsigned int	value;
	int				len;
	int				sign;
	char			*str;

	value = va_arg(args, unsigned int);
	str = NULL;
	if (options->fill == '0' && options->precision >= 0)
		options->fill = 0;
	if (options->precision < 0)
		options->precision = 1;
	if (value == 0 && options->precision == 0)
		str = xt_strnew(0);
	else
		str = xt_uitoa_base(value, options, str);
	sign = (value > 0);
	len = ft_strlen(str);
	adjust(str, options, sign, &len);
	free(str);
	return (len);
}

int		print_lu(t_options *options, va_list args)
{
	unsigned long int	value;
	int					len;
	int					sign;
	char				*str;

	value = va_arg(args, unsigned long int);
	str = NULL;
	if (options->fill == '0' && options->precision >= 0)
		options->fill = 0;
	if (options->precision < 0)
		options->precision = 1;
	if (value == 0 && options->precision == 0)
		str = xt_strnew(0);
	else
		str = xt_uitoa_base(value, options, str);
	sign = (value > 0);
	len = ft_strlen(str);
	adjust(str, options, sign, &len);
	free(str);
	return (len);
}

int		print_llu(t_options *options, va_list args)
{
	unsigned long long int	value;
	int						len;
	int						sign;
	char					*str;

	value = va_arg(args, unsigned long long int);
	str = NULL;
	if (options->fill == '0' && options->precision >= 0)
		options->fill = 0;
	if (options->precision < 0)
		options->precision = 1;
	if (value == 0 && options->precision == 0)
		str = xt_strnew(0);
	else
		str = xt_uitoa_base(value, options, str);
	sign = (value > 0);
	len = ft_strlen(str);
	adjust(str, options, sign, &len);
	free(str);
	return (len);
}

int		print_hu(t_options *options, va_list args)
{
	unsigned short int	value;
	int					sign;
	int					len;
	char				*str;

	value = va_arg(args, unsigned int);
	str = NULL;
	if (options->fill == '0' && options->precision >= 0)
		options->fill = 0;
	if (options->precision < 0)
		options->precision = 1;
	if (value == 0 && options->precision == 0)
		str = xt_strnew(0);
	else
		str = xt_uitoa_base(value, options, str);
	sign = (value > 0);
	len = ft_strlen(str);
	adjust(str, options, sign, &len);
	free(str);
	return (len);
}

int		print_hhu(t_options *options, va_list args)
{
	unsigned char	value;
	int				sign;
	int				len;
	char			*str;

	value = va_arg(args, unsigned int);
	str = NULL;
	if (options->fill == '0' && options->precision >= 0)
		options->fill = 0;
	if (options->precision < 0)
		options->precision = 1;
	if (value == 0 && options->precision == 0)
		str = xt_strnew(0);
	else
		str = xt_uitoa_base(value, options, str);
	sign = (value > 0);
	len = ft_strlen(str);
	adjust(str, options, sign, &len);
	free(str);
	return (len);
}
