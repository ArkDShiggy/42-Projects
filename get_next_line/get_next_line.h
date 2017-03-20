/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:42:20 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/22 16:47:37 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 12

typedef struct			s_file_lst
{
	int					fd;
	int					len;
	char				*str;
	struct s_file_lst	*next;

}						t_file;

int						get_next_line(const int fd, char **line);
#endif
