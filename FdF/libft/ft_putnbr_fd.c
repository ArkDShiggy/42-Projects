/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:27:26 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/10 17:02:47 by jcatinea         ###   ########.fr       */
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

void		ft_putnbr_fd(int n, int fd)
{
	int m;
	int i;
	int sign;

	sign = 1;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	i = -1;
	m = n;
	while (m != 0)
	{
		m /= 10;
		i++;
	}
	while (i >= 0)
	{
		ft_putchar_fd((n / power_ten(i)) * sign + '0', fd);
		n %= power_ten(i);
		i--;
	}
}
