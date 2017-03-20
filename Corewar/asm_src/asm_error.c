/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:27:34 by jcatinea          #+#    #+#             */
/*   Updated: 2017/03/09 10:44:24 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	show_usage(void)
{
	ft_putendl_fd("Usage: ./asm file_to_compile", 2);
	exit(1);
}

void	error(char *str)
{
	ft_putstr_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}

void	parse_error(char *str, t_position *pos)
{
	ft_putstr_fd("Error Line ", 2);
	ft_putnbr_fd(pos->line, 2);
	ft_putstr_fd(", Col ", 2);
	ft_putnbr_fd(pos->col, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd(str, 2);
	free(pos);
	exit(1);
}
