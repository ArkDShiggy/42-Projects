/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:48:54 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/28 12:33:55 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		percent_eval(char *s, size_t *i, va_list args)
{
	t_options	options[1];
	int			a;
	int			result;

	(*i)++;
	result = -1;
	if (!(ft_strinc("0123456789.-+ #%lhsSpdDioOuUxXcCjz", s[*i])))
	{
		error("wrong or missing symbols after percent");
		(*i)--;
		return (0);
	}
	a = eval_flags(s, i, options);
	if (a)
		a = eval_width(s, i, options);
	if (a)
		a = eval_precision(s, i, options);
	if (a)
		result = conversion(s, i, args, options);
	if (result < 0)
	{
		(*i)--;
		result = 0;
	}
	return (result);
}

int		eval_flags(char *s, size_t *i, t_options *options)
{
	options->sign = 0;
	options->alt = 0;
	options->fill = 0;
	while (ft_strinc("#0+- ", s[*i]))
	{
		if (s[*i] == '#')
			options->alt = 1;
		if (s[*i] == '0' && options->fill != '-')
			options->fill = '0';
		if (s[*i] == '-')
			options->fill = '-';
		if (s[*i] == ' ' && options->sign != '+')
			options->sign = ' ';
		if (s[*i] == '+')
			options->sign = '+';
		(*i)++;
	}
	if (!(ft_strinc("123456789.%lhjzsSpdDioOuUxXcC", s[*i])))
	{
		error("wrong or missing symbols after flag charachers");
		return (0);
	}
	return (1);
}

int		eval_width(char *s, size_t *i, t_options *options)
{
	options->width = 0;
	if (ft_isdigit(s[*i]))
		options->width = ft_atoi(s + *i);
	while (ft_isdigit(s[*i]))
		(*i)++;
	if (!(ft_strinc(".%lhjzsSpdDioOuUxXcC", s[*i])))
	{
		error("wrong or missing symbols after width");
		return (0);
	}
	return (1);
}

int		eval_precision(char *s, size_t *i, t_options *options)
{
	options->precision = -1;
	if (s[*i] == '.')
	{
		(*i)++;
		options->precision = ft_atoi(s + *i);
		if (options->precision < 0)
			options->precision = 0;
		while (ft_isdigit(s[*i]))
			(*i)++;
	}
	if (!(ft_strinc("%lhjzsSpdDioOuUxXcC", s[*i])))
	{
		error("wrong or missing symbols after precision");
		return (0);
	}
	return (1);
}
