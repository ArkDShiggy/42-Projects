/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:12:29 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/21 12:17:36 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list *node;

	node = *alst;
	if (node == NULL)
	{
		*alst = new;
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = new;
}
