/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:34:34 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/29 15:22:39 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*get_flags(char *s, size_t *i, t_options *options, char *flags)
{
	int		len;

	len = 0;
	while (s[*i + len] && (!(ft_strinc("sSpdDioOuUxXcC%", s[*i + len])))
			&& len < 3)
	{
		flags[len] = s[*i + len];
		len++;
	}
	flags[len] = s[*i + len];
	flags[len + 1] = '\0';
	options->flag = flags[len];
	(*i) += len;
	return (flags);
}

int				conversion(char *s, size_t *i, va_list args, t_options *options)
{
	int					j;
	int					printed_chars;
	char				flags[4];

	j = 0;
	get_flags(s, i, options, flags);
	printed_chars = type_list(flags, options, args);
	if (printed_chars >= 0)
		return (printed_chars);
	error("incompatible conversion flags");
	return (-1);
}

int				print_p(t_options *options, va_list args)
{
	unsigned long int	value;
	int					len;
	int					sign;
	char				*str;

	value = va_arg(args, unsigned long int);
	options->alt = 1;
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
