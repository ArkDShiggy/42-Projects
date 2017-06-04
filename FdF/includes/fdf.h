/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 14:55:38 by jcatinea          #+#    #+#             */
/*   Updated: 2017/06/04 14:55:39 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include "mlx.h"

typedef struct	s_data
{
	int			width;
	int			height;
	int			*data;
}				t_data;

void			error(char *str);
t_data			*get_data_from_file(char *filename);


void			print_data(t_data *data);

#endif
