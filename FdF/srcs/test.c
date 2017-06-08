/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 13:32:49 by jcatinea          #+#    #+#             */
/*   Updated: 2017/06/04 13:33:04 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_data(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			ft_putnbr(data->data[i * data->width + j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_hexa(char *pix_ar)
{
	int				i;
	int				j;
	unsigned int	*test;

	test = (unsigned int *)pix_ar;
	i = 0;
	printf("\n\n");
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			printf("%x\n", test[i * 5 + j]);
			j++;
		}
		i++;
	}
}
