/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:24:15 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/01 14:24:17 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	two_bytes(unsigned int a)
{
	unsigned char	byte_one;
	unsigned char	byte_two;
	int				i;

	i = 1;
	byte_two = get_byte(&a);
	byte_one = 192;
	while (i < 32)
	{
		byte_one += (a % 2) * i;
		a /= 2;
		i *= 2;
	}
	ft_putchar(byte_one);
	ft_putchar(byte_two);
}

static void	three_bytes(unsigned int a)
{
	unsigned char	byte_one;
	unsigned char	byte_two;
	unsigned char	byte_three;
	int				i;

	i = 1;
	byte_three = get_byte(&a);
	byte_two = get_byte(&a);
	byte_one = 224;
	while (i < 16)
	{
		byte_one += (a % 2) * i;
		a /= 2;
		i *= 2;
	}
	ft_putchar(byte_one);
	ft_putchar(byte_two);
	ft_putchar(byte_three);
}

static void	four_bytes(unsigned int a)
{
	unsigned char	byte_one;
	unsigned char	byte_two;
	unsigned char	byte_three;
	unsigned char	byte_four;
	int				i;

	i = 1;
	byte_four = get_byte(&a);
	byte_three = get_byte(&a);
	byte_two = get_byte(&a);
	byte_one = 240;
	while (i < 8)
	{
		byte_one += (a % 2) * i;
		a /= 2;
		i *= 2;
	}
	ft_putchar(byte_one);
	ft_putchar(byte_two);
	ft_putchar(byte_three);
	ft_putchar(byte_four);
}

void		ft_putwchar(wchar_t value)
{
	unsigned int	a;
	int				bits;

	bits = -1;
	a = (unsigned int)value;
	while (a > 0)
	{
		a /= 2;
		bits++;
	}
	if (bits < 7)
		ft_putchar((char)value);
	else if (bits <= 11)
		two_bytes(value);
	else if (bits <= 16)
		three_bytes(value);
	else
		four_bytes(value);
}
