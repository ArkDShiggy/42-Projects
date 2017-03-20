/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:07:50 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/13 09:56:04 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *node;
	t_list *next;

	next = NULL;
	if (alst)
	{
		node = *alst;
		(*del)(node->content, node->content_size);
		while (node->next)
		{
			next = node->next;
			(*del)(next->content, next->content_size);
			free(node);
			node = next;
		}
		free(node);
		*alst = NULL;
	}
}
