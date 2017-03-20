/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:34:16 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/02 16:39:24 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_minmax
{
	int			distance;
	int			x;
	int			y;
	int			wtf;
}				t_minmax;

typedef struct	s_info
{
	int			map_w;
	int			map_h;
	char		*map_str;
	int			piece_w;
	int			piece_h;
	char		*piece_str;
	char		player;
	char		opponent;
	char		status;
	char		strategy;
	char		phase;
	char		*previous_map;
}				t_info;

int				ft_abs(int a);
void			get_player(t_info *info);
void			get_map_size(t_info *info, char *line);
void			get_piece_size(t_info *info, char *line);
void			get_map_info(t_info *info);
void			get_piece_info(t_info *info);
int				get_info(t_info *info);
int				valid_coord(t_info *info, int i, int x, int y);
int				check_piece(t_info *info, int x, int y);
void			print_result(int x, int y);
int				eval_map(t_info *info);

int				follow_priority(t_info *info, int quadrant);
void			true_follow_coord(t_info *info, int coord, t_minmax *best);
int				fake_follow_coord(t_info *info, int coord);
int				find_enemy_coord(t_info *info);
void			priority_start(t_info *info);
void			priority_start_two(t_info *info, int p_q, int diff);
void			starting_strategy(t_info *info);

void			new_best(t_info *info, t_minmax *best);
void			change_best(t_minmax *best, int distance, int x, int y);
int				check_distance(int coord, int x, int y, t_info *info);
int				get_quadrant(t_info *info, int x, int y, int nmi_coord);
int				get_quadrant_two(t_info *info, int x, int y);
void			wall_check(t_info *info);
void			wall_check_two(t_info *info);
int				check_v_wall(t_info *info, int a);
int				check_h_wall(t_info *info, int a);

int				ur_corner_strat(t_info *info, int enemy_pos);
int				dl_corner_strat(t_info *info, int enemy_pos);
int				corner_strat(t_info *info, int enemy_pos);

int				priority_ul(t_info *info);
int				priority_ur(t_info *info);
int				priority_dl(t_info *info);
int				priority_dr(t_info *info);
int				priority_lu(t_info *info);
int				priority_ld(t_info *info);
int				priority_ru(t_info *info);
int				priority_rd(t_info *info);

#endif
