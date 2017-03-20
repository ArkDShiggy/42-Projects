/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:59:00 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/22 06:30:50 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

typedef struct	s_map
{
	int			size;
	char		*map;
}				t_map;

typedef struct	s_piece
{
	int			placed;
	int			height;
	int			width;
	int			coord[4];
}				t_piece;

void			erreur();
void			malloc_error();
void			usage();
void			push_up(char *s);
void			push_left(char *s);
void			free_list(t_piece **tab);
t_piece			*piece_init(void);
t_piece			*piece_copy(t_piece *piece, int placed);
t_piece			*block_code(char *s);
int				main(int argc, char **argv);
t_map			*empty_map(int size);
void			del_map(t_map *map);
t_map			*copy_map(t_map *map);
void			print_map(t_map *map);
t_piece			**read_entry(int fd);
int				count_pieces(char *file);
t_piece			*read_block(char *s);
int				valid_block(char *s);
t_map			*get_new_map(t_piece *piece, t_map *map,
	int coord, int letter);
t_piece			**get_new_tab(t_piece **tab, int piece);
int				piece_check(t_piece *piece, t_map *map, int coord);
t_map			*fill_piece(t_piece **tab, t_map *map, int piece);
t_map			*fillit(t_piece **tab, t_map *map);
t_map			*test_size(t_piece **tab);
char			*ft_read_file(int fd);

#endif
