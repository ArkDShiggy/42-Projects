/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:17:06 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/30 10:17:07 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <wchar.h>

int		print_c(t_options *options, va_list args)
{
	unsigned char	value;
	int				len;
	char			*str;

	if (options->flag == '%')
		value = '%';
	else
		value = va_arg(args, unsigned int);
	len = 1;
	if (value)
	{
		str = xt_strnew(1);
		str[0] = value;
	}
	else
		return (print_zero_chars(options));
	adjust(str, options, 0, &len);
	free(str);
	return (len);
}

int		print_s(t_options *options, va_list args)
{
	char	*str;
	char	*new;
	int		value;

	str = va_arg(args, char *);
	if (!str)
		new = "(null)";
	else
	{
		if (options->precision >= 0)
			new = xt_strsub(str, 0, options->precision);
		else
			new = xt_strdup(str);
	}
	value = ft_strlen(new);
	adjust(new, options, 0, &value);
	if (str && ft_strlen(new) > 0)
		free(new);
	return (value);
}

int		print_lc(t_options *options, va_list args)
{
	wchar_t	value;
	int		width;
	char	*str;

	value = va_arg(args, wint_t);
	if (!value)
		return (print_zero_chars(options));
	else
		str = wctos(value);
	width = ft_strlen(str);
	adjust(str, options, 0, &width);
	free(str);
	return (width);
}

char	*wstos(char *s1, wchar_t *s2, int len)
{
	char	*new;
	char	*tmp;
	int		a;

	if (s2[0])
	{
		tmp = wctos(s2[0]);
		a = ft_strlen(tmp);
		len -= a;
		if (len < 0)
		{
			free(tmp);
			return (s1);
		}
		new = xt_strjoin(s1, tmp);
		if (ft_strlen(s1) > 0)
			free(s1);
		free(tmp);
		return (wstos(new, s2 + 1, len));
	}
	return (s1);
}

int		print_ls(t_options *options, va_list args)
{
	char	*str;
	wchar_t	*ws;
	int		value;

	ws = va_arg(args, wchar_t *);
	if (!ws)
		str = "(null)";
	else
	{
		value = 0;
		while (ws[value])
			value++;
		if (options->precision >= 0)
			str = wstos("", ws, options->precision);
		else
			str = wstos("", ws, value * 4);
	}
	value = ft_strlen(str);
	adjust(str, options, 0, &value);
	if (ws && ft_strlen(str) > 0)
		free(str);
	return (value);
}
