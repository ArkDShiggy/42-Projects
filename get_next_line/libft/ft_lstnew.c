/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:48:13 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/13 13:46:21 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*memdup(void const *content, size_t content_size)
{
	void *new;

	if (!(new = malloc(content_size)))
		return (NULL);
	ft_memcpy(new, (void *)content, content_size);
	return (new);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*new_content;

	if (content && content_size > 0)
		new_content = memdup(content, content_size);
	else
	{
		new_content = NULL;
		content_size = 0;
	}
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->content = new_content;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
