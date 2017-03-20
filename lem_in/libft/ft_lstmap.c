/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:20:51 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/13 12:18:27 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *new;

	if (!lst)
		return (NULL);
	new = (*f)(lst);
	first = new;
	while (new)
	{
		if (lst->next)
		{
			new->next = (*f)(lst->next);
			lst = lst->next;
		}
		else
			new->next = NULL;
		new = new->next;
	}
	return (first);
}
