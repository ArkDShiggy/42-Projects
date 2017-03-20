/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 09:18:55 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/13 09:44:40 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include "larray.h"

typedef struct	s_weight
{
	int			turn;
	int			weight;
}				t_weight;

typedef struct	s_room
{
	int			visited;
	int			special;
	char		*name;
	int			x;
	int			y;
	int			link_num;
	t_larray	*links;
	t_larray	*turns;
}				t_room;

typedef struct	s_antfarm
{
	t_larray	*rooms;
	int			room_num;
	int			ant_num;
}				t_antfarm;

typedef struct	s_path
{
	int			len;
	char		p[4];
	t_list		**list;
}				t_path;

t_antfarm		*get_antfarm(void);
int				get_special(char **line);
int				is_comment(char *str);
int				is_command(char *str);
int				create_graph(t_antfarm *antfarm);
int				create_graph_two(t_antfarm *antfarm, char *line, int phase);
void			read_file(t_antfarm *antfarm);

int				read_room(t_antfarm *antfarm, char *str, int special);
int				get_x(char *str, int *i, int *x);
int				get_y(char *str, int *i, int *y);
int				check_coordinates(char *str, t_antfarm *antfarm, t_room *room);
t_room			*new_room(char *name, int special);

int				read_link(t_antfarm *antfarm, char *str);
int				name_to_links(t_antfarm *antfarm, char *name1, char *name2);
int				add_link(t_room *room1, int room2_index);

int				special_search(t_antfarm *antfarm, int special);
int				name_search(t_antfarm *antfarm, char *name);
int				coord_search(t_antfarm *antfarm, int x, int y);

void			free_path_array(t_path **array, int ant_num);
void			free_room(t_room *room);
void			free_path(t_path *path);
void			free_antfarm(t_antfarm *antfarm);

void			malloc_error_two(t_antfarm *antfarm,
	t_path **array, t_path *paths);
void			malloc_error_one(t_antfarm *antfarm, char *s);
void			malloc_error(char *s);
void			error(t_antfarm *antfarm);

void			print_path(t_path *path);
void			print_paths(t_path **array, int ant_num);
void			print_recursive_node(t_room *room, t_antfarm *antfarm);
void			print_links(t_room *room, t_antfarm *antfarm);
void			print_graph(t_antfarm *antfarm);

int				add_node_to_path(t_room *room,
	t_path *path, t_path *min, int ant_num);
void			del_node_from_path(t_path *path);
void			del_last_node(t_list **list);
t_path			*copy_path(t_path *path);
void			free_path(t_path *path);
int				add_path_to_list(t_path **array, t_path *path, int ant_num);
int				explore(t_room *start, t_path **array, t_path *path,
	t_antfarm *antfarm);
t_path			**find_paths(t_antfarm *antfarm);
t_path			*new_path(void);

int				verify_graph(t_antfarm *antfarm);
int				verify_graph_two(t_antfarm *antfarm);

void			ft_lstappend(t_list **alst, t_list *new);

int				search_turn(t_room *room, int turn);
int				path_length(t_path *path);
t_path			*search_paths(t_path **paths, int ant_num);
void			solve(t_path **paths, int ant_num);

int				update_link_path(t_path *path);
int				update_link_room(t_room *room, int turn);

void			free_array(t_room ***array, int max_turns);
t_room			***create_array(int ant_num, int max_turns);
void			turn_convert(t_room ***array, t_path *path, int ant);
void			print_part(int i, int j, int count, t_room ***array);
void			print_solution(t_room ***array, int max_turn, int ant_num);

#endif
