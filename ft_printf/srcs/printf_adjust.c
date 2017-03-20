/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_adjust.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:09:53 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/28 17:09:22 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	adjust(char *str, t_options *options, int sign, int *len)
{
	char *prefix;
	char *sign_s;

	prefix = get_prefix(options, sign, str);
	*len += ft_strlen(prefix);
	sign_s = get_sign(options, sign);
	*len += ft_strlen(sign_s);
	if (options->width > 0 && options->fill == 0)
		print_white(options, len);
	ft_putstr(sign_s);
	ft_putstr(prefix);
	if (options->width > 0 && options->fill == '0')
		print_zeros(options, len);
	ft_putstr(str);
	if (options->width > 0 && options->fill == '-')
		print_white(options, len);
}

void	print_zeros(t_options *options, int *len)
{
	if (ft_strinc("iduox", ft_tolower(options->flag)))
	{
		while (*len < options->width)
		{
			ft_putchar('0');
			(*len)++;
		}
	}
}

void	print_white(t_options *options, int *len)
{
	while (options->width > *len)
	{
		ft_putchar(' ');
		(*len)++;
	}
}

char	*get_prefix(t_options *options, int sign, char *str)
{
	if (options->alt == 1)
	{
		if (ft_tolower(options->flag) == 'o' && str[0] != '0')
			return ("0");
		if (options->flag == 'p')
			return ("0x");
		if (options->flag == 'x' && sign != 0)
			return ("0x");
		if (options->flag == 'X' && sign != 0)
			return ("0X");
	}
	return ("");
}

char	*get_sign(t_options *options, int sign)
{
	if (sign == 0 && options->precision == 0)
		return ("");
	if (ft_strinc("di", ft_tolower(options->flag)))
	{
		if (sign == -1)
			return ("-");
		if (options->sign == '+' && sign >= 0)
			return ("+");
		if (options->sign == ' ' && sign >= 0)
			return (" ");
	}
	return ("");
}
