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

void print_data(t_data *data)
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
