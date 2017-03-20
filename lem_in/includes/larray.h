/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   larray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 09:47:36 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/24 09:49:31 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LARRAY_H
# define LARRAY_H

# include "libft.h"

typedef struct	s_larray
{
	void		**arrays;
	size_t		size;
	int			inner_len;
	int			outer_len;
}				t_larray;

t_larray		*new_larray(int inner_len, size_t size);
void			*get_larray(t_larray *larray, int index);
t_larray		*set_larray(t_larray *larray, int index, void *value);
void			free_larray(t_larray *larray);

#endif
