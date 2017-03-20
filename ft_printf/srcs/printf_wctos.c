/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wctos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:36:42 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/01 15:36:44 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	get_byte(unsigned int *a)
{
	unsigned char	b;
	int				i;

	i = 1;
	b = 128;
	while (i < 64)
	{
		b += (*a % 2) * i;
		*a /= 2;
		i *= 2;
	}
	return (b);
}

static char	*two_bytes(unsigned int a)
{
	unsigned char	byte_one;
	char			*str;
	int				i;

	i = 1;
	str = xt_strnew(2);
	str[1] = get_byte(&a);
	byte_one = 192;
	while (i < 32)
	{
		byte_one += (a % 2) * i;
		a /= 2;
		i *= 2;
	}
	str[0] = byte_one;
	return (str);
}

static char	*three_bytes(unsigned int a)
{
	unsigned char	byte_one;
	char			*str;
	int				i;

	i = 1;
	str = xt_strnew(3);
	str[2] = get_byte(&a);
	str[1] = get_byte(&a);
	byte_one = 224;
	while (i < 16)
	{
		byte_one += (a % 2) * i;
		a /= 2;
		i *= 2;
	}
	str[0] = byte_one;
	return (str);
}

static char	*four_bytes(unsigned int a)
{
	unsigned char	byte_one;
	char			*str;
	int				i;

	i = 1;
	str = xt_strnew(4);
	str[3] = get_byte(&a);
	str[2] = get_byte(&a);
	str[1] = get_byte(&a);
	byte_one = 240;
	while (i < 8)
	{
		byte_one += (a % 2) * i;
		a /= 2;
		i *= 2;
	}
	str[0] = byte_one;
	return (str);
}

char		*wctos(wchar_t value)
{
	unsigned int	a;
	int				bits;
	char			*str;

	bits = 0;
	a = (unsigned int)value;
	while (a > 0)
	{
		a /= 2;
		bits++;
	}
	if (bits <= 7)
	{
		str = xt_strnew(1);
		str[0] = value;
		return (str);
	}
	else if (bits <= 11)
		return (two_bytes(value));
	else if (bits <= 16)
		return (three_bytes(value));
	else
		return (four_bytes(value));
}
