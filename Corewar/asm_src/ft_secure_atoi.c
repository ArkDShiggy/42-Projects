/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:51:52 by hmenzagh          #+#    #+#             */
/*   Updated: 2017/02/23 19:00:38 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

intmax_t		ft_secure_atoi(const char *str)
{
	intmax_t	i;
	intmax_t	save;
	intmax_t	res;

	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
				|| str[i] == '\n' || str[i] == '\r' || str[i] == ' '))
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] >= '0' &&
			str[i] <= '9')
		i++;
	save = i;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 - (str[i++] - '0');
		if (res < -INT_MAX || res - 1 > INT_MAX)
			ft_error("Error : Merci de ne renseigner que des nombres <= \
INT_MAX", 0);
	}
	if (!save || str[save - 1] != '-')
		return (-res);
	return (res);
}
