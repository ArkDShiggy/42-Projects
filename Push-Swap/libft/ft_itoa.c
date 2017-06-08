/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:48:59 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/13 15:17:17 by jcatinea         ###   ########.fr       */
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

static void	estimate(int n, int *sign, int *i)
{
	*i = -1;
	*sign = 1;
	if (n < 0)
	{
		*sign = -1;
	}
	while (n != 0)
	{
		n /= 10;
		(*i)++;
	}
}

static char	*zero_case(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		l;
	int		i;
	char	*str;
	int		sign;

	if (n == 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		return (zero_case(str));
	}
	estimate(n, &sign, &l);
	if (!(str = (char *)malloc(sizeof(char) * (l + 2 + (sign < 0)))))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	i = l;
	while (i >= 0)
	{
		str[l - i + (sign < 0)] = ((n / power_ten(i)) * sign) + '0';
		n %= power_ten(i);
		i--;
	}
	str[l + 1 + (sign < 0)] = '\0';
	return (str);
}
