/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 12:15:40 by jcatinea          #+#    #+#             */
/*   Updated: 2017/06/04 12:20:04 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_malloc(size_t n)
{
	void *result;

	result = malloc(n);
	if (result == NULL)
	{
		ft_putstr_fd("Malloc error", 2);
		exit(0);
	}
	return (result);
}
