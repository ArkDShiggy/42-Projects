/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_header2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:33:39 by jcatinea          #+#    #+#             */
/*   Updated: 2017/03/09 11:33:40 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_nc	*get_nc(t_header *header, int a)
{
	t_nc	*new;

	new = (t_nc *)ft_memalloc(sizeof(t_nc));
	if (a == 1)
	{
		new->length = COMMENT_LENGTH;
		new->dest = header->comment;
	}
	else
	{
		new->length = PROG_NAME_LENGTH;
		new->dest = header->prog_name;
	}
	return (new);
}
