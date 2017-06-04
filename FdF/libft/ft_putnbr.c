/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:15:33 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/10 16:59:36 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power_ten(int l)
{
	int i;
	int result;

	i = 0;
	result = 1;
	while (i < l)
	{
		result *= 10;
		i++;
	}
	return (result);
}

void		ft_putnbr(int n)
{
	int m;
	int i;
	int sign;

	sign = 1;
	if (n == 0)
		ft_putchar('0');
	if (n < 0)
	{
		ft_putchar('-');
		sign = -1;
	}
	m = n;
	i = -1;
	while (m != 0)
	{
		m /= 10;
		i++;
	}
	while (i >= 0)
	{
		ft_putchar((n / power_ten(i)) * sign + '0');
		n %= power_ten(i);
		i--;
	}
}
